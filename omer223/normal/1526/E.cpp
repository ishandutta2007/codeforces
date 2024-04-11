
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll mod = 998244353;

void imult(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = ((lhs % mod) + (rhs % mod)) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return ((lhs % mod) + (rhs % mod)) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}

const int sz = 5e5 + 5;
ll f[sz], finv[sz];

void initf() {
    f[0] = 1;
    foru(i, 1, sz)f[i] = mult(i, f[i - 1]);
    finv[sz - 1] = bpw(f[sz - 1], mod - 2);
    ford(i, sz - 2, 0)finv[i] = mult(finv[i + 1], i + 1);
}

ll chs(int n, int k) {
    if (n < k)return 0;
    else if (n < 0)return 0;
    return mult(f[n], mult(finv[k], finv[n - k]));
}

int main() {
	fast;
    initf();
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pos(n);
    foru(i, 0, n)cin >> a[i], pos[a[i]]=i;
    if (n == 1) {
        cout << k << '\n';
        return 0;
    }
    a.push_back(-5);
    int z = 0, o = 0;
    foru(i, 1, n) {
        int posa = a[i-1]+1, posb = a[i]+1;
        int pposa = (posa == n ? -1 : pos[posa]), pposb = (posb == n ? -1 : pos[posb]);
        if (pposa > pposb)o++;
        else z++;
    }
    int lhs = k - 1;
    lhs -= o;
    if (lhs < 0) {
        cout << 0 << '\n';
        return 0;
    }
    ll tot = 0;
    for (int sm = 0; sm <= lhs; sm++) {
        ll ya = chs(n - 1 + sm - 1, n - 2);
        if(k-(sm+o)>0)iadd(tot, mult(ya, k - (sm + o)));
    }
    cout << tot;
	return 0;
}