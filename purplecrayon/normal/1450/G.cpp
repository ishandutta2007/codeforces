#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7, MAXC = 20;

int n, a, b, mn[MAXC], mx[MAXC], cnt[MAXC], p[MAXC], pre[MAXC], suf[MAXC];
string s;
bool dp[1<<MAXC];

void solve(){
    cin >> n >> a >> b >> s;

    std::fill(mn, mn+MAXC, n), std::fill(mx, mx+MAXC, -1);
    auto get = [&](char c) -> int {
        const string SATAN = "trygub";
        int ans = c-'a';
        for (auto v : SATAN) {
            if (v < c) ans--;
            else if (v == c) ans = -1;
        }
        return ans;
    };
    for (int i = 0; i < n; i++) {
        int c=get(s[i]);
        mn[c] = min(mn[c], i);
        mx[c] = max(mx[c], i);
        cnt[c]++;
    }

    iota(p, p+MAXC, 0);
    sort(p, p+MAXC, [&](int i, int j){ return mn[i] < mn[j]; });


    int m = 0;
    while (m < MAXC && cnt[p[m]]) m++;

    {
        int ps = 0;
        for (int i = 0; i < m; i++) {
            ps |= 1<<i;
            pre[i] = ps;
        }
    }
    {
        int ps = 0;
        for (int i = m-1; i >= 0; i--) {
            ps |= 1<<i;
            suf[i] = ps;
        }
    }


    dp[0] = 1;
    for (int i = 1; i < (1<<m)-1; i++) {
        bool bad = [&]() -> bool {
            int l = n, r = -1, c = 0;
            for (int j = 0; j < m; j++) if ((i>>j)&1) {
                l = min(l, mn[p[j]]);
                r = max(r, mx[p[j]]);
                c += cnt[p[j]];
            }
            return c*b < (r-l+1)*a;
        }();

        for (int _j = 0; !bad && _j < m; _j++) if ((i>>_j)&1) {
            int j = p[_j];

            dp[i] |= dp[i^(1<<_j)];
        }
        for (int j = 0; j < m-1; j++) {
            int a = pre[j] & i, b = suf[j+1] & i;
            if (!a || !b || a == i || b == i) continue;
            dp[i] |= dp[a] && dp[b];
        }
    }


    auto rget = [&](int v) -> char {
        for (char c = 'a'; c <= 'z'; c++) if (get(c) == v) return c;
        assert(false);
        return '?';
    };


    vector<int> ans;
    for (int i = 0; i < m; i++) if (dp[((1<<m)-1)^(1<<i)]) {
        ans.push_back(p[i]);
    }
    sort(ans.begin(), ans.end());

    cout << sz(ans) << ' ';
    for (auto c : ans) cout << rget(c) << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}