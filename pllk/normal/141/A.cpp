#include <iostream>

using namespace std;

int t[128];
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) t[s[i]]++;
    cin >> s;
    for (int i = 0; i < s.length(); i++) t[s[i]]++;
    cin >> s;
    for (int i = 0; i < s.length(); i++) t[s[i]]--;
    int v = 0;
    for (int a = 'A'; a <= 'Z'; a++) if (t[a]) v = 1;
    if (v == 0) cout << "YES\n";
    else cout << "NO\n";
}