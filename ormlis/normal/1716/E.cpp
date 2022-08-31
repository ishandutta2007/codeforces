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


const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

void solve() {
    int n; cin >> n;
    vector<ar<ll, 4>> a(1 << n);
    rep(i, 1 << n) {
        cin >> a[i][1];
        a[i][0] = a[i][2] = a[i][3] = max(0ll, a[i][1]);
    }
    auto combine = [&] (ar<ll, 4> &i, ar<ll, 4> &j) {
        ar<ll, 4> res;
        res[0] = max({i[0], j[0], i[3] + j[2]});
        res[1] = i[1] + j[1];
        res[2] = max(i[2], i[1] + j[2]);
        res[3] = max(j[3], j[1] + i[3]);
        return res;
    };
    rep(j, n) {
        for(int l = 0; l < (1 << n); l += (1 << (j + 1))) {
            int r = l + (1 << (j + 1));
            int mid = (l + r) / 2;
            rep(x, (1 << j)) {
                auto L = combine(a[l + x], a[mid + x]);
                auto R = combine(a[mid + x], a[l + x]);
                a[l + x] = L;
                a[mid + x] = R;
            }
        }
    }
    int x = 0;
    int q; cin >> q;
    rep(_, q) {
        int k; cin >> k;
        x ^= (1 << k);
        cout << a[x][0] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}