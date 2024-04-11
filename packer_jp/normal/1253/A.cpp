#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint=vector<int>;
using vvint=vector<vint>;
using pint=pair<int, int>;
using vpint=vector<pint>;
template<typename T> using priority_queue_rev=priority_queue<T, vector<T>, greater<T>>;
constexpr double pi = 3.1415926535897932384626433832795028;
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T1, typename T2> bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> bool chmin(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &rhs) {
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

int t, N;
int a[110000], b[110000];
signed main() {
    cin >> t;
    rep(i, t) {
        cin >> N;
        rep(i, N) { cin >> a[i]; }
        rep(i, N) { cin >> b[i]; }
        int cur = -1, val = 0;
        rep(i, N) {
            a[i] = b[i] - a[i];
            if (a[i] != 0) {
                if (cur == -1 || cur == i - 1) { cur = i, val = a[i]; }
                else { goto nene; }
            }
        }
        if (val < 0) { goto nene; }
        rep(i, N) { if (a[i] != 0 && a[i] != val) { goto nene; }}
        cout << "YES" << endl;
        continue;
        nene:;
        cout << "NO" << endl;
    }

}