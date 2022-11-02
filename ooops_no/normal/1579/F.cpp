#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> a(n), used(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool x = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (used[i]) continue;
            int j = i;
            vector<int> b;
            while(!used[j]){
                used[j] = 1;
                b.pb(a[j]);
                j += d;
                if (j >= n) j -= n;
            }
            if (*min_element(b.begin(), b.end()) == 1){
                x = 1;
            }
            else{
                int m = b.size();
                for (int j = 0; j < m; j++){
                    b.pb(b[j]);
                }
                int last = 0;
                for (int i = 2 * m - 1; i >= 0; i--){
                    if (b[i] == 0) last = i;
                    else{
                        if (i < m) ans = max(ans, last - i);
                    }
                }
            }
        }
        if (x) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}