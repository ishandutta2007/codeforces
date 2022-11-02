#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, sum = 0, ex = 0, ans = 0;
        cin >> n >> m;
        vector<int> k(n), c(m);
        for (int i = 0; i < n; i++){
            cin >> k[i];
        }
        sort(k.begin(), k.end());
        for (int i = 0; i < m; i++){
            cin >> c[i];
        }
        for (int i = 0; i < n; i++){
            sum += c[k[i] - 1];
        }
        ans = sum;
        int l = -1;
        for (int i = n - 1; i > -1; i--){
            l++;
            sum -= c[k[i] - 1];
            ex += c[l];
            if (l >= k[i]) break;
            ans = min(ans, sum + ex);
        }
        cout << ans << endl;
    }
    return 0;
}