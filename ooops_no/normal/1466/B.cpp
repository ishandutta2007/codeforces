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
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> col(2 * n + 100);
        for (int i = 0; i < n; i++){
            cin >> v[i];
            col[v[i]]++;
        }
        for (int i = 2 * n; i >= 1; i--){
            if (col[i]){
                if (col[i + 1] == 0){
                    col[i + 1]++;
                    col[i]--;
                }
            }
        }
        int ans = 0;
        for (auto to : col) if (to > 0) ans++;
        cout << ans << endl;
    }
    return 0;
}