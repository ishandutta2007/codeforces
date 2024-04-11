#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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
const int maxN = 1e5 + 30;
const int LG = 20;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = 0;
    while (f < n && s[f] != '1') f++;
    if (f == n) {
        cout << "NO\n";
        return;
    }
    int ct = 0;
    rep(i, n) if (s[i] == '1') ct++;
    if (ct % 2 == 1) {
        cout << "NO\n";
        return;
    }
    f = (f + 1) % n;
    cout << "YES\n";
    for (int i = f + 1, j = f + 1; i < n + f; i = j) {
        cout << f + 1 << ' ' << (i % n) + 1 << '\n';
        while (s[j % n] != '1') {
            cout << (j % n) + 1 << ' ' << ((j + 1) % n) + 1 << '\n';
            j++;
        }
        j++;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}