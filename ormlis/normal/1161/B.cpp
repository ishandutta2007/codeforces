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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

vector<int> Zfunc(vector<int> &a) {
    int n = a.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && a[z[i]] == a[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n);
    vi bad;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int len1 = y - x;
        int len2 = x - y;
        if (len1 < 0) len1 += n;
        if (len2 < 0) len2 += n;
        if (len1 == len2) {
            bad.push_back(x);
            continue;
        }
        if (len1 < len2) {
            a[len1].push_back(x);
        } else {
            a[len2].push_back(y);
        }
    }
    int need = 1;
    rep(i, n) {
        if (a[i].empty()) continue;
        if (a[i].size() == 1) {
            need = n;
            continue;
        }
        sort(all(a[i]));
        vector<int> b;
        for (int j = 1; j <= (int) a[i].size(); ++j) {
            b.push_back(a[i][j % (int) a[i].size()] - a[i][j - 1]);
        }
        for (auto &x : b) if (x < 0) x += n;
        auto z = Zfunc(b);
        int res = (int) a[i].size();
        int cur = b[0];
        for (int j = 1; j < (int) a[i].size(); ++j) {
            if (cur > 0 && j + z[j] == (int) a[i].size() && (int) a[i].size() % j == 0) {
                res = j;
                break;
            }
            cur += b[j];
        }
        int ans = 0;
        rep(j, res) ans += b[j];
        need = 1ll * ans * need / __gcd(ans, need);
    }
    if (!bad.empty()) {
        assert(n % 2 == 0);
        int k = n / 2;
        for(auto &val : bad) val %= k;
        vector<int> b;
        for (int j = 1; j <= (int) bad.size(); ++j) {
            b.push_back(bad[j % (int) bad.size()] - bad[j - 1]);
        }
        for (auto &x : b) if (x <= 0) x += k;
        auto z = Zfunc(b);
        int res = (int) bad.size();
        int cur = b[0];
        for (int j = 1; j < (int) bad.size(); ++j) {
            if (cur > 0 && j + z[j] == (int) bad.size() && (int) bad.size() % j == 0) {
                res = j;
                break;
            }
            cur += b[j];
        }
        int ans = 0;
        rep(j, res) ans += b[j];
        need = 1ll * ans * need / __gcd(ans, need);
    }
    cout << (need == n ? "NO\n" : "YES\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}