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

typedef pair<vector<int>, vector<int>> pvv;

pvv rec(const vector<int>& s, int sign) {
    if (s.size() == 1) {
        if (sign == 1) {
            return {{}, s};
        } else if (sign == -1) {
            return {s, {}};
        } else {
            assert(false);
        };
    }

    if (s.size() == 0) return {{}, {}};

    int n = s.size();
    vector<int> smaller, larger, seen(n, 0);

    for (int i = 0; i < n; i++) {
        if (seen[i] == 0) {
            for (int j = i + 1; j < n && seen[i] == 0; j++) {
                if (seen[j] == 0) {
                    cout << "? " << s[i] << " " << s[j] << endl;
                    string res;
                    cin >> res;

                    if (res[0] == '>') {
                        smaller.push_back(s[j]);
                        larger.push_back(s[i]);
                        seen[i] = seen[j] = 1;
                    } else if (res[0] == '<') {
                        smaller.push_back(s[i]);
                        larger.push_back(s[j]);
                        seen[i] = seen[j] = 1;
                    } else if (res[0] == '=') {
                        seen[j] = 1;
                    }
                }
            }

            if(seen[i] == 0) {
                smaller.push_back(s[i]);
                larger.push_back(s[i]);
                seen[i] = 1;
            }
        }
    }

    if (sign == 1) {
        return {{}, rec(larger, 1).second};
    } else if (sign == -1) {
        return {rec(smaller, -1).first, {}};
    } else {
        return {rec(smaller, -1).first, rec(larger, 1).second};
    }
}

void solve() {
    int n;
    cin >> n;

    if(n == 1){
        cout << "! 1 1" << endl;
        return;
    }
    vector<int> tmp(n);
    iota(all(tmp), 1);

    pvv ans = rec(tmp, 0);
    cout << "! " << ans.first[0] << " " << ans.second[0] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}