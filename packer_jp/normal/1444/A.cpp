#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define bit(n) (1LL << (n))
#define dump(a) cerr << #a " = " << (a) << endl
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int a) { return (a > 0) - (a < 0); }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T a) {
    cout << a << endl;
    exit(0);
}
template<typename T> T sq(T a) { return a * a; }
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
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
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
    };
} setup;

template<typename T> std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T> src) {
    std::vector<std::pair<T, int>> ret;
    if (src.size() > 0) { ret.push_back({src[0], 1}); }
    for (int i = 1; i < src.size(); i++) {
        if (src[i] == ret.back().first) { ret.back().second++; }
        else { ret.push_back({src[i], 1}); }
    }
    return ret;
}

template<typename T> std::vector<T> prime_factorize(T n) {
    std::vector<T> ret;
    for (T i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.emplace_back(i);
            n /= i;
        }
    }
    if (n != 1) { ret.emplace_back(n); }
    return ret;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int p, q;
        cin >> p >> q;
        vpint pf = run_length_encoding(prime_factorize(q));
        auto pow = [](auto &&pow, int a, int m) -> int {
            if (m == 0) { return 1; }
            int x = pow(pow, a, m / 2);
            if (m & 1) { return x * x * a; }
            else { return x * x; }
        };
        int r = LLONG_MAX;
        for (auto[a, n]:pf) {
            int m = 0, pc = p;
            while (pc % a == 0) { m++, pc /= a; }
            chmin(r, pow(pow, a, max(0LL, m - n + 1)));
        }
        cout << p / r << endl;
    }
}