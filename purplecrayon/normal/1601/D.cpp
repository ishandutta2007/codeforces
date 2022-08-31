#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

int n, d, dp[MAXN], nxt[MAXN];
vector<ar<int, 2>> a;
vector<pair<int, int>> ev[MAXN];

int t[4*MAXN], lzy[4*MAXN];

void push(int v, int tl, int tr, int x) {
    t[v] += x;
    if (tl != tr) {
        lzy[2*v] += x;
        lzy[2*v+1] += x;
    }
}
void app(int v, int tl, int tr) {
    push(v, tl, tr, lzy[v]), lzy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int x) {
    app(v, tl, tr);
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        push(v, tl, tr, x);
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
    t[v] = max(t[2*v], t[2*v+1]);
}
int qry(int v, int tl, int tr, int l, int r) {
    app(v, tl, tr);
    if (r < tl || l > tr) return -MOD;
    if (l <= tl && tr <= r) return t[v];
    int tm=(tl+tr)/2;
    return max(qry(2*v, tl, tm, l, r), qry(2*v+1, tm+1, tr, l, r));
}
void upd(int l, int r, int x) {
    l = max(0, l), r = min(r, n);
    if (l > r) return;
    upd(1, 0, n, l, r, x);

    // for (int i = l; i <= r; i++) t[i] += x;
}
int qry(int l, int r) {
    l = max(0, l), r = min(r, n);
    if (l > r) return -MOD;
    return qry(1, 0, n, l, r);

    // int ans = -MOD;
    // for (int i = l; i <= r; i++) ans = max(ans, t[i]);
    // return ans;
}

void solve() {
    cin >> n >> d;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int s, x; cin >> s >> x;
        if (s < d) { // can never climb
            continue;
        }
        if (x <= d) { // already free
            cur++;
            continue;
        }
        a.push_back({s, x});
    }
    n = sz(a);
    sort(a.begin(), a.end(), [&](auto one, auto two){ 
        if (one[1] == two[1]) return one[0] < two[0];
        return one[1] < two[1];
    });

    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++) {
        if (a[i][1] > a[i][0]) continue;
        int lo = i, hi = n, mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            if (a[mid][1] <= a[i][0]) lo = mid;
            else hi = mid;
            mid = (lo + hi) / 2;
        }

        nxt[i] = lo;
    }
    for (int i = 0; i < n; i++) if (nxt[i] != -1) {
        ev[i+1].emplace_back(i, +1);
        ev[nxt[i]+1].emplace_back(i, -1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto [x, delta] : ev[i]) {
            upd(0, x, delta);
        }
        dp[i] = 1;

        int upd_idx = -1;
        if (a[i][0] >= a[0][1]) {
            int lo = 0, hi = i, mid = (lo + hi) / 2;
            while (lo < mid && mid < hi) {
                if (a[i][0] >= a[mid][1]) lo = mid;
                else hi = mid;
                mid = (lo + hi) / 2;
            }
            upd_idx = lo;
        }

        if (upd_idx != -1) upd(1, upd_idx + 1, +1);
        dp[i] = max(dp[i], qry(1, i));
        if (upd_idx != -1) upd(1, upd_idx + 1, -1);

        // for (int j = i-1; j >= 0; j--) {
        //    dp[i] = max(dp[i], dp[j] + qry(j + 1, j + 1) + int(a[i][0] >= a[j][1]));
        // }

        dp[i] = max(dp[i], qry(0, 0) + 1);
        upd(i + 1, i + 1, dp[i]);

        ans = max(ans, dp[i]);
    }

    cout << ans + cur << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}