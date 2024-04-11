#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = (3e5 + 10) * 30;

int mx[maxN][2];
int to[maxN][2];
int R = 1;

int get(int v, int i, int x, int y) {
    if (i == -1 || !v) return 0;
    int b = ((x >> i) & 1);
    int b2 = ((y >> i) & 1);
    return max(get(to[v][b], i - 1, x, y), to[v][b ^ 1] ? mx[to[v][b^1]][b2^1] : 0);
}

void update(int v, int i, int x, int y, int val) {
    if (i == -1) return;
    int b = ((x >> i) & 1);
    int b2 = ((y >> i) & 1);
    if (!to[v][b]) {
        to[v][b] = R++;
    }
    mx[to[v][b]][b2] = max(mx[to[v][b]][b2], val);
    update(to[v][b], i - 1, x, y, val);
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    int root = R++;
    rep(i, n) {
        int x; cin >> x;
        int res = get(root, 29, x ^ i, x) + 1;
        update(root, 29, x ^ i, i, res);
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}