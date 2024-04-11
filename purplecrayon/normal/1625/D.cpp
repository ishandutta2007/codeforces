#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 998244353;
const int B = 31;
const int N = MAXN * B;

int n, k, p[MAXN], a[MAXN], dp[MAXN], prv[MAXN];
int nxt[N][2], sub[N], m = 0;

// xor of two things has to be > k

void solve() {
    cin >> n >> k, k--;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k == -1) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    iota(p, p + n, 0);
    sort(p, p + n, [&](int x, int y) { return a[x] < a[y]; });

    sort(a, a + n);
    
    memset(nxt, -1, sizeof(nxt));
    memset(prv, -1, sizeof(dp));
    memset(sub, -1, sizeof(sub));
    for (int i = 0; i < n; i++) {
        int x = a[i];
        {
            int c = 0;
            for (int b = B-1; b >= 0; b--) {
                int me = (x >> b) & 1;
                int he = (k >> b) & 1;
                if (he == 0 && nxt[c][me ^ 1] != -1) {
                    if (sub[nxt[c][me ^ 1]] != -1 && dp[i] < dp[sub[nxt[c][me ^ 1]]])
                        prv[i] = sub[nxt[c][me ^ 1]], dp[i] = dp[prv[i]];
                }

                if (nxt[c][me ^ he] == -1) nxt[c][me ^ he] = ++m;
                c = nxt[c][me ^ he];
            }
        }
        dp[i]++;
        {
            int c = 0;
            for (int b = B-1; b >= 0; b--) {
                int me = (x >> b) & 1;
                if (nxt[c][me] == -1) nxt[c][me] = ++m;

                if (sub[nxt[c][me]] == -1 || dp[i] > dp[sub[nxt[c][me]]]) {
                    sub[nxt[c][me]] = i;
                }
                c = nxt[c][me];
            }
        }
    }
    int end = max_element(dp, dp + n) - dp;
    if (dp[end] < 2) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans{end};
    while (ans.back() != -1) {
        ans.push_back(prv[ans.back()]);
    }
    ans.pop_back();

    cout << sz(ans) << '\n';
    for (int x : ans) cout << p[x]+1 << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}