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
const int maxN = 5000 + 10;
const int LG = 30;

void solve() {
    int n, x;
    cin >> n >> x;
    x--;
    vi deg(n);
    vi xx(n);
    int X = 0;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        xx[a] ^= b;
        xx[b] ^= a;
        deg[a]++;
        deg[b]++;
    }
    rep(i, n) X ^= i;
    vi p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    vi u(n);
    int cyc = 0;
    rep(i, n) {
        if (u[i]) continue;
        int v = i;
        while (!u[v]) {
            u[v] = 1;
            v = p[v];
        }
        assert(v == i);
        cyc++;
    }
    int kek = n - cyc;
    if (kek == 0) {
        cout << "Alice\n";
        return;
    }
    if (kek == 1) {
        rep(i, n) {
            if (p[i] != i) {
                if (i != x && p[i] != x) {
                    cout << "Alice\n";
                    return;
                }
            }
        }
    }
    rep(R, n) {
        if (deg[R] == n - 1 && p[R] != R && (x == p[R] || x == R)) {
            cout << "Bob\n";
            return;
        }
        if (deg[R] == n - 1) {
            if (x == R && (kek % 2 == 0)) {
                cout << "Bob\n";
                return;
            }
            if (x != R && kek % 2 == 1) {
                cout << "Bob\n";
                return;
            }
        } else if (deg[R] == n - 2) {
            continue;
            if (x == R && (kek % 2 == 0)) {
                cout << "Bob\n";
                return;
            }
            if (x == R) continue;
            int to = xx[R] ^R ^X;
            if (to != x) {
                if (kek % 2 == 1) {
                    cout << "Bob\n";
                    return;
                }
            } else {
                if (kek % 2 == 1) continue;
                int t2 = xx[to];
                if (kek > 2) {
                    cout << "Bob\n";
                    return;
                }
                assert(kek == 2);
                if (p[t2] != x) continue;
                cout << "Bob\n";
                return;
            }
        }
    }
    cout << "Alice\n";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}