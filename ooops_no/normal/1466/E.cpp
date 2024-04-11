#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

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
        int n, cnt = 0;
        cin >> n;
        vector<int> col(61), po(61);
        vector<int> sum(n);
        vector<int> v(n);
        po[0] = 1;
        for (int j = 1; j < 61; j++){
            po[j] = po[j - 1] * 2;
        }
        for (int i = 0; i < n; i++){
            cin >> v[i];
            cnt += v[i];
            cnt %= MOD;
            for (int j = 0; j < 61; j++){
                if (v[i] & po[j]){
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < n; i++){
            sum[i] = cnt;
            for (int j = 0; j < 61; j++){
                if (v[i] & po[j]){
                    sum[i] += ((n - col[j]) * (po[j] % MOD)) % MOD;
                    sum[i] %= MOD;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < 61; j++){
            vector<int> arr;
            for (int i = 0; i < n; i++){
                if (v[i] & po[j]){
                    arr.pb(sum[i]);
                }
            }
            int val = po[j] % MOD;
            for (auto to : arr){
                ans += ((to * val) % MOD  * (int)(arr.size())) % MOD;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}