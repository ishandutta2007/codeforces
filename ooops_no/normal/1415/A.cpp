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
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        vector<int> a{1, n}, b{1, m};
        int ans = 0;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                ans = max(ans, abs(a[i] - r) + abs(b[j] - c));
            }
        }
        cout << ans << endl;
    }
    return 0;
}