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

template<typename F> long long discrete_binary_search(long long ok, long long ng, F is_ok) {
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> whole;
        reps(i, 2 * n) { whole.emplace(i); }
        vint b(n);
        rep(i, n) { cin >> b[i], whole.erase(b[i]); }
        vint c;
        for (int k:whole) { c.emplace_back(k); }
        int x = discrete_binary_search(0, n+1, [&](int x) {
            rep(i, x) {
                if (b[i] > c[n - x + i]) { return false; }
            }
            return true;
        });
        int y = n - discrete_binary_search(0, n+1, [&](int x) {
            rep(i, x) {
                if (b[n - x + i] < c[i]) { return false; }
            }
            return true;
        });
        cout << x - y + 1 << endl;
    }
}