#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
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

const int md = 998244353; //998244353; //1e9 + 9;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    int n;
    cin >> n;
    vector<ar<int, 3>> have;
    int ans = 0;
    {
        int x;
        cin >> x;
        have.push_back({1, 1, x});
        ans = x % md;
    }
    int A = 0;
    int coef = 1;
    rep(_, n - 1) {
        int x;
        cin >> x;
        // t -> (sum - t)
        int was = ans;
        A = sub(ans, A);
        ans = mul(ans, max(x, have.back()[2]) - 1);
        coef = sub(0, coef);
        if (have.back()[2] < x) {
            // y * coef + add = was
            int y = mul(sub(was, A), rev(coef));
            int l = have.back()[2] + 1;
            int r = x;
            have.push_back({y, l, r});
        } else {
            while (have.back()[2] > x) {
                auto[val, l, r] = have.back();
                int tt = val;
                val = mul(val, coef);
                val = add(val, A);
                have.pop_back();
                if (l > x) {
                    ans = sub(ans, mul(r - l + 1, val));
                    continue;
                }
                ans = sub(ans, mul(r - x, val));
                have.push_back({tt, l, x});
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}