#include <bits/stdc++.h>
using namespace std;

string s, t, u;

int main () {
    cin >> s;
    cin >> t;
    cin >> u;

    if (s.size() + t.size() != u.size()) {
        puts("NO");
        return 0;
    }

    bool uda[102]={};
    for (int i=0; i<u.size(); i++) {
        bool bisa = 0;
        for (int j=0; j<s.size(); j++) if (u[i] == s[j] && !uda[j]) {
            uda[j] = 1;
            bisa = 1;
            break;
        }

        if (bisa) continue;

        for (int j=0; j<t.size(); j++) if (u[i] == t[j] && !uda[s.size()+j]) {
            uda[s.size()+j] = 1;
            bisa = 1;
            break;
        }

        if (!bisa) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    return 0;
}