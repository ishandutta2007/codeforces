#include <bits/stdc++.h>

using namespace std;
int w, n, db[1005];
void solve(int l, int r) {
    if (l>r) return;
    int pos=l;
    for (int i=l; i<=r; i++) {
        if (db[i]<db[pos]) pos=i;
    }
    cout << l << " " << r << " " << pos << "\n";
    solve(l, pos-1), solve(pos+1, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int l, r;
            cin >> l >> r;
            for (int j=l; j<=r; j++) db[j]++;
        }
        solve(1, n);

        for (int i=1; i<=n; i++) {
            db[i]=0;
        }
    }
    return 0;
}