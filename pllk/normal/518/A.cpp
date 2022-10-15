#include <iostream>

using namespace std;

string s, t;

int main() {
    cin >> s >> t;
    int n = s.size();
    bool ok = false;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'z') s[i] = 'a';
        else {s[i]++; ok = true; break;}
    }
    if (s == t || !ok) cout << "No such string\n";
    else cout << s << "\n";
}