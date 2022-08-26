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
const int maxN = 5e5 + 20;
const int LG = 30;

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }
    vpi ans;
    auto Op = [&](int l, int r) {
        assert(a[l] == a[r]);
        ans.emplace_back(l + 1, r + 1);
        reverse(a.begin() + l, a.begin() + r + 1);
    };
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i] == b[i]) continue;
        int y = b[i];
        int x = a[i - 1];
        for (int j = i; j + 1 < n; ++j) {
            if (a[j] == y && a[j + 1] == x) {
                Op(i - 1, j + 1);
                assert(a[i] == b[i]);
                break;
            }
        }
        if (a[i] == b[i]) continue;
        bool ok = false;
        for (int j = i; j < n; ++j) {
            if (a[j] == y && a[j - 1] == x) {
                vi was(n, -1);
                for (int l = i - 1; l <= j - 1; ++l) was[a[l]] = l;
                for (int r = j; r < n; ++r) {
                    if (was[a[r]] != -1) {
                        Op(was[a[r]], r);
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            return;
        }
        if (a[i] == b[i]) continue;
        for (int j = i; j + 1 < n; ++j) {
            if (a[j] == y && a[j + 1] == x) {
                Op(i - 1, j + 1);
                assert(a[i] == b[i]);
                break;
            }
        }
        assert(a[i] == b[i]);
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    assert(ans.size() <= n * n);
    for (auto[x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}