#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e4 + 5;
const int LG = 20;

void solve() {
    int n = 4;
    vector<pair<int, int>> a(n), b(n);
    rep(i, n) cin >> a[i].first >> a[i].second;
    rep(i, n) cin >> b[i].first >> b[i].second;

    auto check = [] (vector<pair<int, int>> a, vector<pair<int, int>> b) {
        int x1 = 100, x2 = -100, y1 = 100, y2 = -100;
        for(auto &[x, y] : a) {
            x1 = min(x1, x);
            x2 = max(x2, x);
            y1 = min(y1, y);
            y2 = max(y2, y);
        }
        int X = 0, Y = 0;
        for(auto &[x, y] : b) {
            if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                return true;
            }
            X += x;
            Y += y;
        }
        X /= 4;
        Y /= 4;
        if (x1 <= X && X <= x2 && y1 <= Y && Y <= y2) return true;
        return false;
    };
    if (check(a, b)) {
        cout << "YES\n";
        return;
    }
    for(auto &[x, y] : a) {
        int x2 = x + y;
        int y2 = x - y;
        swap(x, x2);
        swap(y, y2);
    }

    for(auto &[x, y] : b) {
        int x2 = x + y;
        int y2 = x - y;
        swap(x, x2);
        swap(y, y2);
    }

    if (check(b, a)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}