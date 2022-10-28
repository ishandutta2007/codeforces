#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


int n, m, k, a[MAXN];
map<int, int> cmp;


struct seg {
    int cnt[4*MAXN];
    ll sm[4*MAXN];

    void upd(int v, int tl, int tr, int pos, ll x, int mul) {
        if (pos < tl || pos > tr) return;
        if (tl == tr) {
            cnt[v] += mul;
            sm[v] += x*mul;
            return;
        }
        int tm=(tl+tr)/2;
        upd(2*v, tl, tm, pos, x, mul), upd(2*v+1, tm+1, tr, pos, x, mul);
        sm[v] = sm[2*v]+sm[2*v+1];
        cnt[v] = cnt[2*v]+cnt[2*v+1];
    }
    ll qry(int v, int tl, int tr, int x) { //find sum of xth largest values
        //cerr << v << ' ' << tl << ' ' << tr << ' ' << x << ' ' << cnt[v] << ' ' << sm[v] << endl;
        if (!x) return 0;
        if (x >= cnt[v]) return sm[v];
        if (tl == tr) return ll(x)*(sm[v]/cnt[v]);

        int tm=(tl+tr)/2;
        if (cnt[2*v+1] >= x) return qry(2*v+1, tm+1, tr, x);
        return sm[2*v+1]+qry(2*v, tl, tm, x-cnt[2*v+1]);
    }
    void init() {
        memset(cnt, 0, sizeof(cnt)); memset(sm, 0, sizeof(sm));
    }
} pos, neg;

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], cmp[abs(a[i])]++;
    cin >> k;

    int cc=0; for (auto& it : cmp) it.second = cc++;
    pos.init(); neg.init();

    ll cur = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] >= 0) pos.upd(1, 0, n-1, cmp[a[i]], a[i], 1);
        else neg.upd(1, 0, n-1, cmp[-a[i]], -a[i], 1);
        cur += a[i];
    }
    ll pr = 0;
    for (int i = m-1; i < n; i++) {
        if (i >= m) {
            int er = i-m;
            if (a[er] >= 0) pos.upd(1, 0, n-1, cmp[a[er]], a[er], -1);
            else neg.upd(1, 0, n-1, cmp[-a[er]], -a[er], -1);
            cur -= a[er];

            if (a[i] >= 0) pos.upd(1, 0, n-1, cmp[a[i]], a[i], 1);
            else neg.upd(1, 0, n-1, cmp[-a[i]], -a[i], 1);
            cur += a[i];
        }
        ll ans = abs(cur);
        ans = max(ans, abs(cur-2*pos.qry(1, 0, n-1, k)));
        ans = max(ans, abs(cur+2*neg.qry(1, 0, n-1, k)));
        pr = max(pr, ans);
    }
    cout << pr << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}