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
const int maxN = 3e5 + 5;
const int LG = 19;

void solve() {
    int n, k;
    cin >> n >> k;
    int to = (n - 1);
    if (k == n - 1) {
        if (n == 4) {
            cout << "-1\n";
            return;
        }
        int t = __lg(n);
        cout << (1 << t) - 1 << ' ' << (1 << (t - 1)) - 1 << '\n';
        cout << (1 << (t - 1)) + 1 << ' ' << (1 << (t - 1)) << '\n';
        cout << 0 << ' ' << (to ^ ((1 << (t - 1)) + 1)) << '\n';
        vector<int> ban;
        ban.push_back((1 << t) - 1);
        ban.push_back((1 << (t - 1)) - 1);
        ban.push_back((1 << (t - 1)) + 1);
        rep(i, n / 2) {
            bool ok = true;
            for(auto &x : ban) {
                if (x == i || (to ^ x) == i) ok = false;
            }
            if (!ok) continue;
            cout << i << ' ' << (to ^ i) << '\n';
        }
        return;
    }
    if (k == 0) {
        rep(i, n / 2) {
            cout << i << ' ' << (to ^ i) << '\n';
        }
        return;
    }
    cout << "0 " << (k ^ to) << '\n';
    cout << k << ' ' << to << '\n';
    for (int i = 1; i < n / 2; ++i) {
        if (i == k || (i ^ to) == k) continue;
        cout << i << ' ' << (to ^ i) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}