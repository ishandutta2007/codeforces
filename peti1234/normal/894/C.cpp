#include <bits/stdc++.h>

using namespace std;
int m, s[1001], lnko;
bool jo;
int main()
{
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> s[i];
        lnko=__gcd(lnko, s[i]);
    }
    for (int i=1; i<=m; i++) {
        if (lnko==s[i]) {
            jo=1;
        }
    }
    if (!jo) {
        cout << -1 << "\n";
    } else {
        cout << 2*m << "\n";
        for (int i=1; i<=m; i++) {
            cout << s[i] << " " << lnko << " ";
        }
        cout << "\n";
    }
    return 0;
}