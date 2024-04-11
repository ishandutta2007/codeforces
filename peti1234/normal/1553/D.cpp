#include <bits/stdc++.h>

using namespace std;
int w, sa, sb, pos, db;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        sa=a.size(), sb=b.size();
        pos=0, db=0;
        if (sa%2!=sb%2) {
            pos++;
        }
        while (pos<sa) {
            if (db<sb && a[pos]==b[db]) {
                pos++, db++;
            } else {
                pos+=2;
            }
        }
        cout << (db==sb ? "YES" : "NO") << "\n";
    }
    return 0;
}