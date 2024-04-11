#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int t[maxn];
int rec[maxn], nxt[maxn], f[maxn];
vector<int> val[maxn];
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i <= n; i++) f[i] = 0;
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if(x == y) continue;
            x--;
            y--;
            f[x] = max(f[x], y);
        }
        for(int i = 1; i < n; i++) f[i] = max(f[i], f[i-1]);
        for(int i = 0; i < n; i++) t[i] = a[i];
        sort(t, t+n);
        for(int i = 0; i < n; i++) a[i] = lower_bound(t, t+n, a[i]) - t;
        for(int i = 0; i <= n+1; i++) val[i].clear();
        for(int i = 0; i < n; i++) val[a[i]].push_back(i);
        for(int i = 0; i <= n; i++) rec[i] = nxt[i] = -1;
        for(int i = n-1; i >= 0; i--) {
            if(rec[a[i]] >= 0) {
                nxt[i] = rec[a[i]];
                rec[a[i]] = i;
            }
            else {
                rec[a[i]] = i;
            }
        }
        int bd = n, mx = -1;
        for(int i = 0; i < n; i++) {
            if(nxt[i] >= 0 && nxt[i] <= f[i]) mx = i;
        }
        int ans = mx+1;
        for(int i = 0; i < bd; i++) {
            ans = min(ans, mx-i+1);
            if(nxt[i] >= 0 && nxt[i] <= f[i]) {
                mx = max(mx, *prev(upper_bound(val[a[i]].begin(), val[a[i]].end(), f[i])));
                bd = min(bd, nxt[i]+1);
            }
        }
        ans = max(ans, 0);
        cout << ans << endl;
    }
}