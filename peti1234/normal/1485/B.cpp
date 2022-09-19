#include <bits/stdc++.h>

using namespace std;
int n, q, k, t[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=q; i++) {
        int l, r, h; cin >> l >> r, h=r-l+1;
        cout << 2*(k-h)-t[l]+1-k+t[r] << "\n";
    }
    return 0;
}