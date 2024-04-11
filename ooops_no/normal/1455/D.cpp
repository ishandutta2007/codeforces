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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        bool f = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        for (int i = 0; i < n - 1; i++){
            if (v[i] > v[i + 1]) f = 1;
        }
        if (!f){
            cout << 0 << endl;
            continue;
        }
        int ans = 1e18;
        for (int i = 0; i < n; i++){
            int cnt = 0, ccc = x;
            vector<int> a = v;
            for (int j = i; j < n; j++){
                if (a[j] > ccc){
                    cnt++;
                    swap(a[j], ccc);
                    if (is_sorted(a.begin(), a.end())){
                        ans = min(ans, cnt);
                        break;
                    }
                }
            }
        }
        if (ans == 1e18) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}