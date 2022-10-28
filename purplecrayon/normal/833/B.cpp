#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3.5e4+10, MOD = 1e9+7;
const int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int n, k, a[MAXN];
int cnt[MAXN], pre[MAXN], cur[MAXN];

int ans=0, pl=-1, pr=-1;
void add(int i){ if (0 <= i && i < n) ans += !(cnt[a[i]]++); }
void er(int i){ if (0 <= i && i < n) ans -= !(--cnt[a[i]]); }
int C(int l, int r) {
    while (pl >= l) add(--pl);
    while (pr <= r) add(++pr);
    while (pl < l) er(pl++);
    while (pr > r) er(pr--);
    return ans;
}
void rec(int l, int r, int optl, int optr) {
    if (l > r) return;
    int m=(l+r)/2;
    ar<int, 2> opt{-MOD, -1};
    for (int k = optl; k <= min(m, optr); k++) 
        opt = max(opt, ar<int, 2>{(k ? pre[k-1] : 0) + C(k, m), k});
    cur[m] = opt[0];
    rec(l, m-1, optl, opt[1]), rec(m+1, r, opt[1], optr);
}
void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    memset(pre, 0, sizeof(pre)), memset(cur, 0, sizeof(cur));

    for (int rep = 0; rep < k; rep++) {
        rec(0, n-1, 0, n-1);
        for (int i = 0; i < n; i++) pre[i] = cur[i], cur[i] = 0;
    }
    cout << pre[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}