#include <iostream>

using namespace std;

string s, t;
int c[128];
int c1, c2;

int main() {
    cin >> s >> t;
    for (int i = 0; i < t.size(); i++) c[t[i]]++;
    for (int i = 0; i < s.size(); i++) {
        if (c[s[i]]) {
            c1++;
            c[s[i]]--;
            s[i] = 0;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 0) continue;
        if (s[i] <= 'Z' && c[s[i]+'a'-'A']) {
            c2++;
            c[s[i]+'a'-'A']--;
        } else if (s[i] >= 'a' && c[s[i]-'a'+'A']) {
            c2++;
            c[s[i]-'a'+'A']--;
        }
    }
    cout << c1 << " " << c2 << "\n";
}