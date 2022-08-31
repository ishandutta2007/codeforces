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

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e5 + 10;

void solve() {
    vpi ans;
    int n, d12, d23, d31; cin >> n >> d12 >> d23 >> d31;
    int need = d12;
    int h = (d23 + d31 - d12);
    if (h % 2 || h < 0) {
        cout << "NO\n";
        return;
    }
    h /= 2;
    if (h + need > n - 1) {
        cout << "NO\n";
        return;
    }
    int A = d31 - h;
    if (A < 0 || A > d12) {
        cout << "NO\n";
        return;
    }
    vi res;
    res.push_back(1);
    int cur = 4;
    rep(_, d12 - 1) res.push_back(cur++);
    if (h == 0) {
        swap(res[(int)res.size() - 1], res[A]);
        cur--;
        res[A] = 3;
    }
    res.push_back(2);
    for(int i = 1; i < (int)res.size(); ++i) ans.emplace_back(res[i], res[i - 1]);
    if (h != 0) {
        int f = res[A];
        while(h != 1) {
            ans.emplace_back(f, cur);
            f = cur++;
            h--;
        }
        ans.emplace_back(f, 3);
    }
    while(cur <= n) {
        ans.emplace_back(1, cur++);
    }
    cout << "YES\n";
    for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
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