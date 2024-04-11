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

int n, k;
string s;
int cnt[1100000];
int solve() {
    cin >> n >> k >> s;
    fill(cnt, cnt + k, 0);
    vvint hoge(k, vint());
    int b = 0;
    rep(i, n) {
        if (s[i] == '1') {
            cnt[i % k]++;
            b++;
        }
        hoge[i % k].push_back(s[i] == '1' ? -1 : 1);
    }
    int ret = b;
    rep(i, k) {
        int cur = INT_MAX;
        vint cum(hoge[i].size() + 1);
        rep(j, hoge[i].size()) { cum[j + 1] = cum[j] + hoge[i][j]; }
        int m = INT_MIN;
        rep(j, cum.size()) {
            chmin(cur, cum[j] - m);
            chmax(m, cum[j]);
        }
        chmin(ret, (cnt[i] + cur) + (b - cnt[i]));
    }
    return ret;
}
signed main() {
    int t;
    cin >> t;
    while (t--) { cout << solve() << endl; }
}