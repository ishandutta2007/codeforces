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
const int maxN = 2e5 + 10;

const int T = 100;

void print(int x) {
    cout << x / 100 << '.';
    cout << (x / 10) %  10;
    cout << x % 10;
}

ld ask(vector<pair<int, int>> pts, bool rv) {
    cout << "? " << pts.size() << endl;
    for (auto[x, y] : pts) {
        if (rv) swap(x, y);
        print(x);
        cout << ' ';
        print(y);
        cout << '\n';
    }
    ld s;
    cin >> s;
    return s;
}

void solve() {
    auto get = [&](int n, int m, bool rv) {
        if (n == 1) return (ld)0;
        vector<pi> pts;
        pts.emplace_back(-100, -100);
        for (int i = 0; i < n; ++i) {
            pts.emplace_back(i * 100, 0);
            pts.emplace_back(i * 100, m * 100);
            pts.emplace_back(i * 100 + i + 1, m * 100);
            pts.emplace_back(i * 100 + i + 1, 0);
        }
        pts.emplace_back(n * 100, -100);
        ld val = ask(pts, rv) * 100;
        const ld EPS = 1e-8;
        int j = 0;
        int L = 0;
        int R = (n - 1) * 100;
        while (j < n) {
            int val2 = j + 1;
            if ((ld)val2 + EPS < val) {
                L = max(L, j * 100 + val2);
                j++;
            } else {
                R = min(R, j * 100 + val2);
                break;
            }
        }
        assert(j != n);
        ld kek = j + 1;
        if (abs(kek - val) < EPS) {
            L = max(L, (j - 1) * 100 + j + 1);
        } else {
            R = min(R, (j - 1) * 100 + j + 1);
        }
        if (L >= R) return (ld)L / (ld)100;
        vector<pi> pts2;
        pts2.emplace_back(L, 0);
        pts2.emplace_back(L, m * 100);
        pts2.emplace_back(R, m * 100);
        pts2.emplace_back(R, 0);
        ld dx = ask(pts2, rv);
        return (ld)R/(ld)100 - dx;
    };
    int n, m;
    cin >> n >> m;
    ld X = get(n, m, false);
    ld Y = get(m, n, true);
    cout << "! " << X << " " << Y << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}