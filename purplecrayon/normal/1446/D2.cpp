#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

const int B = 550;

int n, a[MAXN], ps[MAXN], mn[2*MAXN], prv_mx[MAXN], nxt_mx[MAXN];
vector<int> loc[MAXN];
int p = 0, cnt_max = 0;

int solve_big(int c) {
    for (int i = 0; i < n; i++) {
        if (a[i] == c) ps[i] = 1;
        else if (a[i] == p) ps[i] = -1;
        else ps[i] = 0;

        if (i) ps[i] += ps[i-1];
        else ps[i] += n;
    }
    fill(mn, mn+2*n, n);
    mn[n] = -1;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, i-mn[ps[i]]);
        mn[ps[i]] = min(mn[ps[i]], i);
    }
    return ans;
}

int vis[2*MAXN], tt=0;
int solve_small(int c) {
    int m = sz(loc[c]);

    int cnt = 0;
    vector<ar<int, 2>> he, me;
    for (int i : loc[c]) {
        int nxt = lower_bound(loc[p].begin(), loc[p].end(), i) - loc[p].begin();

        auto add = [&](int v, int sm) {
            if (he.empty() || v > he.back()[0]) he.push_back({v, sm});
        };

        for (int j = max(0, nxt-(m+1)); j < nxt; j++) {
            add(loc[p][j], -(j+1));
        }
        for (int j = nxt; j < sz(loc[p]) && j < nxt+(m+1); j++) {
            add(loc[p][j], -(j+1));
        }

        me.push_back({i, -nxt});
        cnt++;
    }
    assert(is_sorted(me.begin(), me.end()));
    assert(is_sorted(he.begin(), he.end()));

    vector<ar<int, 2>> b; b.reserve(sz(he)+sz(me));
    std::merge(me.begin(), me.end(), he.begin(), he.end(), back_inserter(b));
    assert(is_sorted(b.begin(), b.end()));

    int k = sz(b);
    vector<int> prv(k), nxt(k);
    for (int i = 0, ptr = 0; i < k; i++) {
        while (ptr < m && loc[c][ptr] <= b[i][0]) ptr++;
        prv[i] = prv_mx[b[i][0]], nxt[i] = nxt_mx[b[i][0]];
        if (ptr > 0) {
            if (loc[c][ptr-1] != b[i][0])
                prv[i] = max(prv[i], loc[c][ptr-1]);
            else if (ptr > 1)
                prv[i] = max(prv[i], loc[c][ptr-2]);
        }
        if (ptr < m) nxt[i] = min(nxt[i], loc[c][ptr]);
    }

    tt++;
    auto get = [&](int i) {
        if (vis[i] == tt) return mn[i];
        else return n;
    };
    auto set = [&](int i, int x) {
        vis[i] = tt, mn[i] = x;
    };

    set(n, -1);
    int ans = 0, ps = n;
    for (int i = 0; i < k; i++) {
        if (a[b[i][0]] == c) ps++;

        b[i][1] += ps;
        ans = max(ans, nxt[i]-1-get(b[i][1]));
        set(b[i][1], min(get(b[i][1]), b[i][0]));
    }
    return ans;
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    for (int i = 0; i < n; i++) loc[a[i]].push_back(i);
    for (int i = 0; i < n; i++) {
        if (sz(loc[i]) > sz(loc[p])) p = i, cnt_max = 1;
        else if (sz(loc[i]) == sz(loc[p])) cnt_max++;
    }
    if (cnt_max > 1){ cout << n << '\n'; return; }

    int prv = -1;
    for (int i = 0; i < n; i++) {
        prv_mx[i] = prv;
        if (a[i] == p) prv = i;
    }
    int nxt = n;
    for (int i = n-1; i >= 0; i--) {
        nxt_mx[i] = nxt;
        if (a[i] == p) nxt = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) if (i != p && sz(loc[i])) {
        int cur = -1;
        if (sz(loc[i]) >= B) cur = solve_big(i);
        else cur = solve_small(i);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}