#define DINGER_GISBAR
#include <bits/stdc++.h>
using namespace std;
const long long MOD = static_cast<int>(1e9) + 7;
//{{{TEMPLATE_BEGIN
#include <unistd.h>
using namespace std::rel_ops;
#ifdef ZEROKUGI
#include <dumper.hpp>
#define dump(x) dumper::dumper(cerr, __LINE__, (#x), (x), 50, 1, 1)
#define tick(...) dumper::tick(__VA_ARGS__)
#pragma message "Compiling " __FILE__
#else
#define dump(x)
#define tick(...)
#endif
typedef long long lint;
typedef unsigned long long ulint;
typedef long double ldouble;
typedef vector<int> vint;
#define rep(i, n) \
    for (int i = 0, i##_len = static_cast<int>(n); i < i##_len; i++)
#define all(c) begin(c), end(c)
#define perm(c)   \
    sort(all(c)); \
    for (bool c##p = 1; c##p; c##p = next_permutation(all(c)))
#define uniquenize(v) (v).erase(unique(all(v)), end(v))
#define cauto const auto&
#define memset(x, y) memset(x, y, sizeof(x))
#define popcount __builtin_popcount
#define gcd __gcd
inline lint bit(int x) { return 1LL << x; }
template <class T>
inline int size(const T& a) {
    return (int)a.size();
}
template <class T>
inline bool chmin(T& a, const T& b) {
    return a > b ? a = b, 1 : 0;
}
template <class T>
inline int clamp(T v, T lo, T hi) {
    return (v > hi) - (v < lo);
}
template <class T>
inline bool chmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0;
}
template <class T>
inline pair<vector<T>, char> operator*(const vector<T>& v, const char& c) {
    return make_pair(v, c);
}
template <class T>
inline istream& operator>>(istream& is, vector<T>& v) {
#ifdef ZEROKUGI
    if (v.empty()) {
        cerr << "Error L" << __LINE__ << ": vector size is zero." << endl;
        exit(EXIT_FAILURE);
    }
#endif
    for (auto& x : v) is >> x;
    return is;
}
template <class T>
inline ostream& operator<<(ostream& os, const pair<vector<T>, char>& v) {
    bool t = 0;
    for (const T& x : v.first) {
        if (t) os << v.second;
        os << x;
        t = 1;
    }
    return os;
}
template <class T>
inline ostream& operator<<(ostream& os, vector<T>& v) {
    return os << v * ' ';
}
struct before_main {
    before_main() {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
        tick(0, 0);
    };
} __before_main;
//}}}TEMPLATE_END

string f(int n, const vector<int>& v) {
    string res(n, '0');
    for (cauto x : v) res[x] = '1';
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    cin >> r;
    typedef pair<int, int> pii;

    if (n == 2) {
        if (r[0] == r[1]) {
            cout << r[0] << endl;
            cout << 0 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            int v = max(r[0], r[1]);
            cout << v << endl;
            while (v--) cout << 11 << endl;
            return 0;
        }
    }

    for (int ans = 100; ans >= 1; ans--) {
        bool ok = true;
        int rem = 0;

        priority_queue<pii> pq;
        for (int i = 0; i < n; i++) {
            ok &= r[i] >= ans;

            rem += r[i] - ans;

            pq.push({r[i] - ans, i});
        }
        if (!ok) continue;

        vector<string> mov;
        while (rem) {
            if (rem == 3) {
                pii p[3];
                rep(z, 3) {
                    p[z] = pq.top();
                    pq.pop();
                }
                if (p[2].first == 1) {
                    assert(p[0].first == 1 && p[1].first == 1);
                    mov.push_back(f(n, {p[0].second, p[1].second, p[2].second}));
                    rem -= 3;
                } else {
                    break;
                }
            } else {
                pii p[2];
                rep(z, 2) {
                    p[z] = pq.top();
                    pq.pop();
                }

                if(p[1].first > 0){
                    p[0].first--;
                    p[1].first--;
                    mov.push_back(f(n, {p[0].second, p[1].second}));
                    rem -= 2;
                    pq.push(p[0]);
                    pq.push(p[1]);
                } else {
                    break;
                }
            }
        }

        if(rem == 0) {
            cout << ans << endl;
            cout << mov.size() << endl;
            for(const string&s: mov) cout << s << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    cout << 100 * (n - 1) << endl;

    for(int i = 0; i + 1 < n; i++){
        rep(_, 100) cout << f(n, {i, i+1}) << endl;
    }
}