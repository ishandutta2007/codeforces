#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2000 + 5;

template <const int M> struct ModInt {
    int val;
    ModInt(ll x = 0): val((x % M + M) % M) {}

    ModInt<M> pow(ll n) const {
        ModInt<M> ans = 1, x = val;
        while (n) {
            if (n & 1) ans *= x;
            x *= x;
            n /= 2;
        }
        return ans;
    }

    ModInt<M> inverse() const { return pow(M - 2); }
    ModInt operator+ (const ModInt<M>& m) { return (val + m.val) % M; }
    ModInt operator- (const ModInt<M>& m) { return ((val - m.val) % M + M) % M; }
    ModInt operator* (const ModInt<M>& m) { return val * (ll) m.val % M; }
    ModInt operator/ (const ModInt<M>& m) { return *this * m.inverse(); }
    ModInt operator+=(const ModInt<M>& m) { return *this = *this + m; }
    ModInt operator-=(const ModInt<M>& m) { return *this = *this - m; }
    ModInt operator*=(const ModInt<M>& m) { return *this = *this * m; }
    ModInt operator/=(const ModInt<M>& m) { return *this = *this / m; }

    friend ostream &operator<<(ostream &os, const ModInt &m) {
        os << m.val;
        return os;
    }
};

using mint = ModInt<mod>;
mint fact[N];

mint choose(int n, int k) {
    mint num = fact[n];
    mint dem = fact[k] * fact[n - k];
    return num * dem.inverse();
}

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int c1 = 0, c2 = 0;
    {
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (a[i] != -1)
                s.insert(a[i]);
        }

        for (int i = 1; i <= n; i++) {
            if (!s.count(i)) {
                if (a[i - 1] == -1)
                    c1++;
                else c2++;
            }
        }
    }

    mint ans = fact[c1 + c2];
    for (int i = 1; i <= c1; i++) {
        if (i & 1)
            ans -= choose(c1, i) * fact[c1 + c2 - i];
        else ans += choose(c1, i) * fact[c1 + c2 - i];
    }

    cout << ans << '\n';
    return 0;
}