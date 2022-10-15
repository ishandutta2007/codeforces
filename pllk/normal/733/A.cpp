#include <iostream>

using namespace std;

string s;
int c, p;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {c=0;continue;}
        if (s[i] == 'E') {c=0;continue;}
        if (s[i] == 'I') {c=0;continue;}
        if (s[i] == 'O') {c=0;continue;}
        if (s[i] == 'U') {c=0;continue;}
        if (s[i] == 'Y') {c=0;continue;}
        c++;
        p = max(p,c);
    }
    cout << p+1 << "\n";
}