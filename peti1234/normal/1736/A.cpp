#include <bits/stdc++.h>

using namespace std;
int a[100005], b[100005];
void solve() {
    int n, db1=0, db2=0, dif=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        db1+=a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        db2+=b[i];
        if (a[i]!=b[i]) dif++;
    }
    cout << min(dif, abs(db1-db2)+1) << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}