#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define dump(a) cerr << #a " = " << (a) << endl
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int bit(int n) { return 1LL << n; }
int sign(int a) { return (a > 0) - (a < 0); }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> T sq(T a) { return a * a; }
template<typename T> void fin(T a) {
    cout << a << endl;
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
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template<typename T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {
    os << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    }
} setup;

signed main() {
    int n, k;
    cin >> n >> k;
    vint c(n);
    rep(i, n) { cin >> c[i]; }
    sort(all(c));
    vint cum(n + 1), ccum(n + 1);
    rep(i, n) { cum[i + 1] = cum[i] + c[i]; }
    rep(i, n) { ccum[i + 1] = ccum[i] + c[i] * i; }
    int ans = LLONG_MIN;
    int coef = -1, pre = 0;
    rep(i, n) {
        if (i % (k + 1) == 0) { coef++; }
        pre += c[i] * coef;
        chmax(ans, pre + ccum[n] - ccum[i + 1] - (cum[n] - cum[i + 1]) * ((i + 1) - (coef + 1)));
    }
    cout << ans << endl;
}