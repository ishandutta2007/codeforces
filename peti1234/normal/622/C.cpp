#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, q, t[c], kov[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=n; i>=1; i--) {
        kov[i]=(t[i]==t[i+1] ? kov[i+1] : i+1);
    }
    while (q--) {
        int l, r, ert;
        cin >> l >> r >> ert;
        if (t[l]!=ert) cout << l << "\n";
        else if (kov[l]<=r) cout << kov[l] << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}