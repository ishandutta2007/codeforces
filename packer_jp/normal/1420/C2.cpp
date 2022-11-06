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

struct fast_io {
    static constexpr int SIZE_IN = 1 << 26, SIZE_OUT = 1 << 26;
    char data_in[SIZE_IN], data_out[SIZE_OUT], *p_in, *p_out, s[30];
    fast_io() { fread(data_in, 1, SIZE_IN, stdin), p_in = data_in, p_out = data_out; }
    ~fast_io() { fwrite(data_out, 1, p_out - data_out, stdout); }
    void putchar(char x) { *p_out++ = x; }
    template<typename T> void putint(T x) {
        if (x < 0) { *p_out++ = '-', x = -x; }
        int i = 0;
        do { s[i++] = x % 10 + '0'; } while (x /= 10);
        while (i--) { *p_out++ = s[i]; }
    }
    template<typename T=int> T getint() {
        while (!isdigit(*p_in) && *p_in != '-') { p_in++; }
        bool negative = *p_in == '-';
        T ret = negative ? 0 : *p_in - '0';
        while (isdigit(*++p_in)) { (ret *= 10) += *p_in - '0'; };
        return negative ? -ret : ret;
    }
} io;

signed main() {
    int t = io.getint();
    while (t--) {
        int n = io.getint(), q = io.getint();
        vint a(n + 2);
        a[0] = a[n + 1] = INT_MIN;
        reps(i, n) { a[i] = io.getint(); }
        int ans = 0;
        auto calc = [&](int i) -> int {
            if (i == 0 || i == n + 1) { return 0; }
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) { return a[i]; }
            if (a[i - 1] > a[i] && a[i] < a[i + 1]) { return -a[i]; }
            return 0;
        };
        reps(i, n) { ans += calc(i); }
        io.putint(ans), io.putchar('\n');
        while (q--) {
            int l = io.getint(), r = io.getint();
            vint v;
            for (int j = l - 1; j <= l + 1; j++) { v.emplace_back(j); }
            for (int j = r - 1; j <= r + 1; j++) { v.emplace_back(j); }
            sort(all(v)), uniq(v);
            for (int x:v) { ans -= calc(x); }
            swap(a[l], a[r]);
            for (int x:v) { ans += calc(x); }
            io.putint(ans), io.putchar('\n');
        }
    }
}