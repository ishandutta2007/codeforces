#include <iostream>

using namespace std;

int m[128];
string s;
int t;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (m[s[i]] == 0) t++;
        m[s[i]] = 1;
    }
    if (t%2 == 0) cout << "CHAT WITH HER!\n";
    if (t%2 == 1) cout << "IGNORE HIM!\n";
}