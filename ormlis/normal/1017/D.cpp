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
const int maxN = 100;
const int LG = 20;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vi cnt(1 << n);
    vi w(n);
    rep(i, n) cin >> w[i];
    reverse(all(w));
    auto get = [&]() {
        str s;
        cin >> s;
        int x = 0;
        for (auto &c : s) {
            x *= 2;
            x += (c - '0');
        }
        return x;
    };
    rep(_, m) {
        cnt[get()]++;
    }
    vvi ans(1 << n, vi(101));
    rep(mask, 1 << n) {
        int res = 0;
        rep(i, n) if ((mask & (1 << i)) == 0) res += w[i];
        if (res > 100) continue;
        rep(mask2, 1 << n) {
            int mask3 = mask2 ^mask;
            ans[mask2][res] += cnt[mask3];
        }
    }
    rep(mask, 1 << n) {
        for (int i = 1; i <= 100; ++i) ans[mask][i] += ans[mask][i - 1];
    }
    rep(_, q) {
        int x = get();
        int k;
        cin >> k;
        cout << ans[x][k] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}