#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, q, db[c], ans;
void add(int a, int b, int c) {
    if (a>b) {
        swap(a, b);
    }
    db[a]+=c;
    if (db[a]==0) {
        ans++;
    }
    if (c==1 && db[a]==1) {
        ans--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ans=n;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b, 1);
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int x;
        cin >> x;
        if (x==3) {
            cout << ans << "\n";
        } else {
            int a, b;
            cin >> a >> b;
            add(a, b, (x==1 ? 1 : -1));
        }
    }
    return 0;
}