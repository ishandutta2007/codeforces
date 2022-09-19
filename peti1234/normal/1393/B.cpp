#include <bits/stdc++.h>

using namespace std;
int n, q, a, b, db[100002];
void pl(int x) {
    db[x]++;
    if (db[x]%2==0) a++;
    if (db[x]==4) b++;
}
void mi(int x) {
    db[x]--;
    if (db[x]%2) a--;
    if (db[x]==3) b--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        pl(x);
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c=='+') pl(x);
        else mi(x);
        if (b && a>=4) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}