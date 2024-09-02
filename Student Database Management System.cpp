#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

// Structure to store student information
struct Student {
    int id;
    string name;
    int age;
    string course;
};

// Class for managing the student database
class StudentDatabase {
private:
    Student students[MAX_STUDENTS];
    int count;

public:
    StudentDatabase() : count(0) {}

    // Add a student to the database
    void addStudent() {
        if (count >= MAX_STUDENTS) {
            cout << "Database is full!" << endl;
            return;
        }
        Student student;
        cout << "Enter Student ID: ";
        cin >> student.id;
        cin.ignore(); // to ignore leftover newline character
        cout << "Enter Student Name: ";
        getline(cin, student.name);
        cout << "Enter Student Age: ";
        cin >> student.age;
        cin.ignore();
        cout << "Enter Student Course: ";
        getline(cin, student.course);

        students[count++] = student;
        cout << "Student added successfully!" << endl;
    }

    // Update a student's information
    void updateStudent() {
        int id;
        cout << "Enter Student ID to update: ";
        cin >> id;
        cin.ignore();
        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                cout << "Enter new Student Name: ";
                getline(cin, students[i].name);
                cout << "Enter new Student Age: ";
                cin >> students[i].age;
                cin.ignore();
                cout << "Enter new Student Course: ";
                getline(cin, students[i].course);
                cout << "Student updated successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    // Delete a student from the database
    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;
        cin.ignore();
        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    // Search for a student by ID
    void searchStudent() {
        int id;
        cout << "Enter Student ID to search: ";
        cin >> id;
        cin.ignore();
        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                cout << "Student ID: " << students[i].id << endl;
                cout << "Student Name: " << students[i].name << endl;
                cout << "Student Age: " << students[i].age << endl;
                cout << "Student Course: " << students[i].course << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    // Display all students
    void displayAllStudents() {
        if (count == 0) {
            cout << "No students in the database!" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "Student ID: " << students[i].id << endl;
            cout << "Student Name: " << students[i].name << endl;
            cout << "Student Age: " << students[i].age << endl;
            cout << "Student Course: " << students[i].course << endl;
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    StudentDatabase db;
    int choice;

    while (true) {
        cout << "\nStudent Database Management System Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore leftover newline character

        switch (choice) {
            case 1:
                db.addStudent();
                break;
            case 2:
                db.updateStudent();
                break;
            case 3:
                db.deleteStudent();
                break;
            case 4:
                db.searchStudent();
                break;
            case 5:
                db.displayAllStudents();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
/* output:
Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 1

Enter Student ID: 101
Enter Student Name: Alice Johnson
Enter Student Age: 20
Enter Student Course: Computer Science
Student added successfully!

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 1

Enter Student ID: 102
Enter Student Name: Bob Smith
Enter Student Age: 22
Enter Student Course: Mathematics
Student added successfully!

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 5

Student ID: 101
Student Name: Alice Johnson
Student Age: 20
Student Course: Computer Science
------------------------
Student ID: 102
Student Name: Bob Smith
Student Age: 22
Student Course: Mathematics
------------------------

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 4

Enter Student ID to search: 101
Student ID: 101
Student Name: Alice Johnson
Student Age: 20
Student Course: Computer Science

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 2

Enter Student ID to update: 102
Enter new Student Name: Robert Smith
Enter new Student Age: 23
Enter new Student Course: Statistics
Student updated successfully!

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 5

Student ID: 101
Student Name: Alice Johnson
Student Age: 20
Student Course: Computer Science
------------------------
Student ID: 102
Student Name: Robert Smith
Student Age: 23
Student Course: Statistics
------------------------

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 3

Enter Student ID to delete: 101
Student deleted successfully!

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 5

Student ID: 102
Student Name: Robert Smith
Student Age: 23
Student Course: Statistics
------------------------

Student Database Management System Menu:
1. Add Student
2. Update Student
3. Delete Student
4. Search Student
5. Display All Students
6. Exit
Enter your choice: 6
Exiting...
*/
