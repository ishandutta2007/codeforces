#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> v(n + 1), a(k);
        for (int i = 1; i <= n; i++){
            char r;
            cin >> r;
            if (r == '1'){
                v[i] = 1;
                a[i % k]++;
            }
            else{
                v[i] = 0;
            }
        }
        int x, y;
        cin >> x >> y;
        int ans = 1e18;
        for (int i = 0; i < p; i++){
            if (v[i]){
                a[i % k]--;
            }
        }
        for (int i = 0; i < n; i++){
            if (i + p > n) break;
            int need = (n - (p + i)) / k + 1;
            ans = min(ans, (need - a[(i + p) % k]) * x + i * y);
            if (v[(i + p)] == 1){
                a[(i + p) % k]--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}