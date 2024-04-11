#include <bits/stdc++.h>

using namespace std;
int n, e, db1, db2;
map<pair<int, int>, char> m;
bool van(pair<int, int> p) {
    return (m.find(p)!=m.end());
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> e;
    for (int i=1; i<=e; i++) {
        char c, x, y; cin >> c;
        int a, b;
        pair<int, int> p, q;
        if (c=='+') {
            cin >> a >> b >> x;
            p={a, b}, q={b, a};
            if (van(q)) {
                y=m[q];
                if (x==y) {
                    db1++;
                } else {
                    db2++;
                }
            }
            m[p]=x;
        }
        if (c=='-') {
            cin >> a >>b;
            p={a, b}, q={b, a};
            x=m[p];
            if (van(q)) {
                y=m[q];
                if (x==y) {
                    db1--;
                } else {
                    db2--;
                }
            }
            m.erase(p);
        }
        if (c=='?') {
            cin >> a;
            cout << (db1 || (db2 && a%2) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}