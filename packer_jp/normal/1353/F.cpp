#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) begin(x), end(x)
#define uniq(x) (x).erase(unique(all(x)), end(x))
#define bit(n) (1LL << (n))
#define cdiv(a, b) (((a) - 1) / (b) + 1)
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr long double PI = 3.1415926535897932384626433832795028L;
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

int solve() {
    int n, m;
    cin >> n >> m;
    vvint a(n + 1, vint(m + 1));
    vint val;
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
            a[i][j] -= i + j;
            val.push_back(a[i][j]);
        }
    }
    int ans = LLONG_MAX;
    sort(all(val));
    rep(i, val.size()) {
        vvint b(a);
        rep(j, n) {
            rep(k, m) {
                if (b[j][k] < val[i]) { b[j][k] = LLONG_MAX; }
                else { b[j][k] -= val[i]; }
            }
        }
        vvint dp(n + 1, vint(m + 1, LLONG_MAX));
        dp[0][0] = b[0][0];
        rep(j, n) {
            rep(k, m) {
                if (dp[j][k] < LLONG_MAX && b[j + 1][k] < LLONG_MAX) { chmin(dp[j + 1][k], dp[j][k] + b[j + 1][k]); }
                if (dp[j][k] < LLONG_MAX && b[j][k + 1] < LLONG_MAX) { chmin(dp[j][k + 1], dp[j][k] + b[j][k + 1]); }
            }
        }
        chmin(ans, dp[n - 1][m - 1]);
    }
    return ans;
}
signed main() {
    int t;
    cin >> t;
    while (t--) { cout << solve() << endl; }
}