#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int now = 0;
        vector<int> v(n), pr_mn(n), pr_mx(n), sf_mn(n), sf_mx(n);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '+') now++;
            else now--;
            v[i] = now;
        }
        pr_mn[0] = v[0];
        pr_mx[0] = v[0];
        sf_mn[n - 1] = v[n - 1];
        sf_mx[n - 1] = v[n - 1];
        for (int i = 1; i < n; i++){
            pr_mn[i] = min(v[i], pr_mn[i - 1]);
            pr_mx[i] = max(v[i], pr_mx[i - 1]);
        }
        for (int i = n - 2; i > -1; i--){
            sf_mn[i] = min(v[i], sf_mn[i + 1]);
            sf_mx[i] = max(v[i], sf_mx[i + 1]);
        }

        for (int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            l--, r--;
            int mn = 0, mx = 0, del = v[r];
            if (l != 0){
                del -= v[l - 1];
                mn = min(mn, pr_mn[l - 1]);
                mx = max(mx, pr_mx[l - 1]);
            }
            if (r != n - 1){
                mn = min(mn, sf_mn[r + 1] - del);
                mx = max(mx, sf_mx[r + 1] - del);
            }
            cout << mx - mn + 1 << endl;
        }
    }
    return 0;
}