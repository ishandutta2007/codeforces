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
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
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
const int maxN = 3e5 + 5;
const int LG = 19;

void solve() {
    int n; cin >> n;
    vvi pos(n);
    rep(i, n) {
        int x; cin >> x;
        pos[x - 1].push_back(i);
    }
    vector<pair<int, int>> segs;
    vector<int> nxt(n, -1);
    rep(i, n) {
        if (pos[i].size() < 2) continue;
        nxt[pos[i][0]] = pos[i].back();
    }
    int ans = 0;
    int R = -1;
    while(R < n) {
        int cnt = 1;
        int L = R + 1;
        while(L < n && nxt[L] == -1) L++;
        if (L == n) break;
        R = nxt[L];
        int to = L + 1;
        while(to < R) {
            int t = -1;
            while(to < R) {
                t = max(t, nxt[to]);
                to++;
            }
            if (t < R) break;
            cnt++;
            R = t;
        }
        ans += R - L - 1;
        ans -= cnt - 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}