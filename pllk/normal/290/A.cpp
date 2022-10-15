#include <iostream>

using namespace std;

int a;
string n[42] =
{"Washington", "Adams", "Jefferson", "Madison", "Monroe",
 "Adams", "Jackson", "Van Buren", "Harrison",
 "Tyler", "Polk", "Taylor", "Fillmore", "Pierce", 
 "Buchanan", "Lincoln", "Johnson", "Grant", "Hayes",
 "Garfield", "Arthur", "Cleveland", "Harrison",
 "Cleveland", "McKinley", "Roosevelt", "Taft", 
 "Wilson", "Harding", "Coolidge", "Hoover", "Roosevelt",
 "Truman", "Eisenhower", "Kennedy", "Johnson",
 "Nixon", "Ford", "Carter", "Reagan", "Bush", "Clinton"};

int main() {
    cin >> a;
    cout << n[a-1] << endl;
}