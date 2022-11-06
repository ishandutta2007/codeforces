#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), end(x))
#define bit(n) (1LL << (n))
#define cdiv(a, b) (((a) - 1) / (b) + 1)
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int DX[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

template<typename F> long long discrete_binary_search(long long ok, long long ng, F is_ok) {
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
}

int to_int(string s) {
    int ret = 0;
    rep(i, s.length()) { ret += bit(s.length() - i - 1) * (s[i] - '0'); }
    return ret;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vint a(n);
        rep(i, n) {
            string s;
            cin >> s;
            a[i] = to_int(s);
        }
        sort(all(a));
        int k = bit(m) - n;
        int ans = discrete_binary_search(bit(m) - 1, -1, [&](int x) {
            return x - (upper_bound(all(a), x) - a.begin()) >= (k - 1) / 2;
        });
        vint v(m);
        for (int i = 0; i < m; i++) {
            v[i] = ans % 2;
            ans /= 2;
        }
        for (int i = m - 1; i >= 0; i--) { cout << v[i]; }
        cout << endl;
    }
}