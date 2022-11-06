#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int x) { return (x > 0) - (x < 0); }
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T> T sq(T x) { return x * x; }
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
template<typename T> ostream &operator<<(ostream &os, const deque<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &rhs) {
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

template<typename T> std::vector<T> get_divisors(T n) {
    std::vector<T> ret;
    T i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            ret.emplace_back(i);
            ret.emplace_back(n / i);
        }
    }
    if (i * i == n) { ret.emplace_back(i); }
    std::sort(ret.begin(), ret.end());
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

template<typename T> std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T> src) {
    std::vector<std::pair<T, int>> ret;
    if (src.size() > 0) { ret.push_back({src[0], 1}); }
    for (int i = 1; i < src.size(); i++) {
        if (src[i] == ret.back().first) { ret.back().second++; }
        else { ret.push_back({src[i], 1}); }
    }
    return ret;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vint d = get_divisors(n);
        vint p = prime_factorize(n);
        uniq(p);
        if (p.size() == 2) {
            if (d.size() == 4) {
                cout << d[1] << " " << d[2] << " " << d[3] << endl;
                cout << 1 << endl;
            } else {
                vpint rp = run_length_encoding(prime_factorize(n));
                if (rp[0].second == 1) { swap(p[0], p[1]); }
                vector<bool> used(d.size());
                int y = p[0] * p[0] * p[1];
                rep(i, p.size()) {
                    int x = p[i] * p[(i + 1) % p.size()], ix;
                    rep(j, d.size()) {
                        if (d[j] == x) { ix = j; }
                        if (!used[j] && d[j] % p[i] == 0 && d[j] != x && d[j] != y) {
                            cout << d[j] << " ";
                            used[j] = true;
                        }
                    }
                    if (i == 0) { cout << x << " "; }
                    else { cout << y << " "; }
                    used[ix] = true;
                }
                cout << endl;
                cout << 0 << endl;
            }
            continue;
        }
        vector<bool> used(d.size());
        int y = p[0] * p[p.size() - 1];
        rep(i, p.size()) {
            int x = p[i] * p[(i + 1) % p.size()], ix;
            rep(j, d.size()) {
                if (d[j] == x) { ix = j; }
                if (!used[j] && d[j] % p[i] == 0 && d[j] != x && d[j] != y) {
                    cout << d[j] << " ";
                    used[j] = true;
                }
            }
            cout << x << " ";
            used[ix] = true;
        }
        cout << endl;
        cout << 0 << endl;
    }
}