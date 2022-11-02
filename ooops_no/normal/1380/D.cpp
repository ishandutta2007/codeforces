#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    int need_x = x;
    x = min(x, k * y);
    vector<int> a(n), b(m + 1);
    map<int, int> pos;
    for (int i = 0; i <= n; i++) pos[i] = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    pos[-1] = -1;
    b[0] = -1;
    for (int i = 1; i <= m; i++){
        cin >> b[i];
        b[i]--;
        if (pos[b[i]] == -1){
            cout << -1;
            return 0;
        }
    }
    b.pb(-2);
    pos[-2] = n;
    int ans = 0;
    for (int i = 0; i + 1 <= m + 1; i++){
        if (pos[b[i]] > pos[b[i + 1]]){
            cout << -1;
            return 0;
        }
        int cnt = pos[b[i + 1]] - pos[b[i]] - 1;
        if (cnt == 0) continue;
        if (cnt < k){
            int mx = 0;
            for (int f = pos[b[i]] + 1; f < pos[b[i + 1]]; f++){
                mx = max(mx, a[f]);
            }
            if (mx > b[i] && mx > b[i + 1]){
                cout << -1;
                return 0;
            }
            ans += cnt * y;
        }
        else{
            int val = need_x + (cnt - k) / k * x + cnt % k * y, mx = 0;
            for (int f = pos[b[i]] + 1; f < pos[b[i + 1]]; f++){
                mx = max(mx, a[f]);
            }
            if (mx <= b[i] || mx <= b[i + 1]){
                val = min(val, cnt * y);
            }
            ans += val;
        }
    }
    cout << ans << endl;
    return 0;
}