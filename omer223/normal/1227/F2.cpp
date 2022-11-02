#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const int sz = 3e5;
ll n, k;
ll h[sz], f[sz], invf[sz];

ll mpw(ll b, ll e) {
    if (!e)return 1;
    ll tmp = mpw(b, e >> 1);
    tmp *= tmp;
    tmp %= mod;
    if (e & 1) {
        tmp *= b;
        tmp %= mod;
    }
    return tmp;
}

void prec() {
    f[0] = 1;
    foru(i, 1, sz)f[i] = (f[i - 1] * i) % mod;
    invf[sz - 1] = mpw(f[sz - 1], mod - 2);
    ford(i, sz - 2, 0)invf[i] = (invf[i + 1] * (i + 1)) % mod;
}

inline ll mul(const ll &lhs, const ll &rhs) {
    return ((lhs % mod) * (rhs % mod)) % mod;
}

int main() {
    fast;
    bool eq = 1;
    prec();
    cin >> n >> k;
    foru(i, 0, n) {
        cin >> h[i];
        eq &= (i ? (h[i - 1] == h[i]) : 1);
    }
    if (eq) {
        cout << 0 << '\n';
        return 0;
    }
    ll free = 0, no = 0;
    foru(i, 0, n) {
        if (h[i] == h[(i + 1) % n])free++;
        else no++;
    }
    ll x = 0;
    k-=2;
    for (int i = 0; 2 * i <= no; i++) {
        ll tmp = f[no];
        tmp = mul(tmp, invf[i]);
        tmp = mul(tmp, invf[i]);
        tmp = mul(tmp, invf[no - 2 * i]);
        tmp = mul(tmp, mpw(k, no - 2 * i));
        x += tmp;
        x %= mod;
    }
    ll ret = mpw(k+2, free);
    ll t2 = ((mpw(k + 2, no) - x) % mod + mod) % mod;
    ret = mul(ret, t2);
    ret = mul(ret, mpw(2, mod - 2));
    cout<<ret<<'\n';
    return 0;
}