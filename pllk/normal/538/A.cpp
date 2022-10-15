#include <iostream>

using namespace std;

string s;
string t = "CODEFORCES";
int a, b;

int main() {
    cin >> s;
    for (int i = 0; i < s.size() && i < t.size(); i++) {
        if (s[i] == t[i]) a++;
        else break;
    }
    for (int i = 0; i < s.size() && i < t.size(); i++) {
        if (s[s.size()-i-1] == t[t.size()-i-1]) b++;
        else break;
    }
    if (a+b >= 10) cout << "YES\n";
    else cout << "NO\n";
}