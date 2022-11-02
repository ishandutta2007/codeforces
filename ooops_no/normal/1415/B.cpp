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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        int ans = 1e18;
        for (int i = 1; i <= 100; i++){
            int last = -1e18, cnt = 0;
            vector<int> u;
            for (int j = 0; j < n; j++){
                if (i != v[j]){
                    if (j - last >= k){
                        cnt++;
                        last = j;
                    }
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}