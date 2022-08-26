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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 5e6 + 30;
const int LG = 100;

void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    while (l < n && s[l] == '0') l++;
    while (r >= 0 && s[r] == '0') r--;
    if (l == n) {
        cout << "0\n";
        return;
    }
    if (l == r) {
        if (n - 1 - r <= k) {
            swap(s[n - 1], s[r]);
        } else if (l <= k) {
            swap(s[0], s[l]);
        }
    } else {
        if (n - 1 - r <= k) {
            swap(s[n - 1], s[r]);
            k -= (n - 1 -r);
        }
        if (l <= k) {
            swap(s[0], s[l]);
            k -= l;
        }
    }
    int ans = 0;
    rep(i, n) {
        if (s[i] == '0') continue;
        if (i != 0) ans += 1;
        if (i != n - 1) ans += 10;
    }
    cout << ans << '\n';
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