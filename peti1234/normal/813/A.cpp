#include <bits/stdc++.h>

using namespace std;
int n, x, sum, m, l, r;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x;
        sum+=x;
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int l, r;
        cin >> l >> r;
        if (l<=sum && sum<=r) {
            cout << sum << "\n";
            return 0;
        }
        if (sum<l) {
            cout << l << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}