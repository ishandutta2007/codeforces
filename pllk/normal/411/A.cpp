#include <iostream>

using namespace std;

string s;
int c;

int main() {
    cin >> s;
    if (s.size() >= 5) c++;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {c++; break;}
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {c++; break;}
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {c++; break;}
    }
    if (c == 4) cout << "Correct\n";
    else cout << "Too weak\n";
}