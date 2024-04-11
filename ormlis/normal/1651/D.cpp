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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 2e5 + 20;
const int LG = 30;

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> ind;
    vector<pair<int, int>> a(n);
    vector<pair<int, int>> ans(n, {INFi, INFi});
    queue<int> q;
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
        ind[a[i]] = i;
    }
    vi dx = {0, 0, 1, -1};
    vi dy = {-1, 1, 0, 0};
    rep(i, n) {
        rep(d, 4) {
            int x = a[i].first + dx[d];
            int y = a[i].second + dy[d];
            if (ind.count({x, y})) continue;
            ans[i] = {x, y};
            q.push(i);
            break;
        }
    }
    rep(i, n) if (ans[i].first != INFi) ind.erase(a[i]);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        rep(d, 4) {
            int x = a[i].first + dx[d];
            int y = a[i].second + dy[d];
            if (!ind.count({x, y})) continue;
            int j = ind[{x, y}];
            ans[j] = ans[i];
            q.push(j);
            ind.erase(a[j]);
        }
    }
    rep(i, n) cout << ans[i].first << ' ' << ans[i].second << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}