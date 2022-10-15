#include <iostream>

using namespace std;

string s;

int main() {
    cin >> s;
    if (s[0] > 'Z') s[0] -= ('a'-'A');
    cout << s << endl;
}