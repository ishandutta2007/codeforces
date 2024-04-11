#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 3e5;

void solve() {
    int n; cin >> n;
    vector<str> a(n);
    rep(i, n) cin >> a[i];
    vector<vi> b(n);
    vector<char> chars;
    rep(i, n) {
        for(auto &c : a[i]) chars.push_back(c);
    }
    chars.push_back(0);
    sort(all(chars));
    chars.resize(unique(all(chars)) - chars.begin());
    int k = chars.size();
    rep(i, n) {
        b[i].push_back(0);
        for(auto &c : a[i]) {
            int j = lower_bound(all(chars), c) - chars.begin();
            b[i].push_back(j);
        }
    }
    vector<vector<ar<int, 2>>> pos(n, vector<ar<int, 2>> (k, {-1, -1}));
    rep(i, n) {
        vector<int> cur(k, 0);
        rep(j, (int)b[i].size()) {
            int c = b[i][j];
            pos[i][c][cur[c]++] = j;
        }
    }
    vector<vector<int>> dp(k, vector<int> (1 << n, -1));
    vector<vector<int>> pred(k, vector<int> (1 << n, -1));
    vector<int> cur(k, 0);
    dp[0][0] = 1;
    pair<int, int> mx = {-1, -1};
    rep(i, (int)b[0].size()) {
        int c = b[0][i];
        int j = cur[c]++;
        rep(mask2, 1 << (n - 1)) {
            int mask = (mask2 << 1) | j;
            if (dp[c][mask] == -1) continue;
            mx = max(mx, {dp[c][mask], (c << 10) | mask});
            rep(nxt, k) {
                int mask3 = 0;
                bool ok = true;
                rep(e, n) {
                    int w = -1;
                    if (mask & (1 << e)) {
                        w = pos[e][c][1];
                    } else {
                        w = pos[e][c][0];
                    }
                    if (pos[e][nxt][0] > w) continue;
                    if (pos[e][nxt][1] > w) {
                        mask3 |= (1 << e);
                        continue;
                    }
                    ok = false;
                    break;
                }
                if (!ok) continue;
                if (dp[nxt][mask3] < dp[c][mask] + 1) {
                    dp[nxt][mask3] = dp[c][mask] + 1;
                    pred[nxt][mask3] = (c << 10) | mask;
                }
            }
        }
    }
    int len = mx.first - 1;
    cout << len << '\n';
    int c = mx.second >> 10;
    int mask = mx.second ^ (c << 10);
    string s;
    while(pred[c][mask] != -1) {
        s += chars[c];
        int c2 = pred[c][mask] >> 10;
        int mask2 = pred[c][mask] ^ (c2 << 10);
        swap(c, c2);
        swap(mask, mask2);
    }
    reverse(all(s));
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}