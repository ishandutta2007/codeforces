#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;
const int max_n = 3e5 + 1;
const int mod = 998244353;


int fact[max_n];

int binpow(int a, int b) {
    int res = 1;
    for(;b > 0; b /= 2, a = a * a % mod) 
        if (b & 1)
            res = res * a % mod;

    return res;
}

int inv(int v) {
    return binpow(v, mod - 2);
}

int cnk(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv(fact[k]) % mod * inv(fact[n - k]) % mod;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    fact[0] = 1;
    for(int i = 1;i < max_n;i++) 
        fact[i] = fact[i - 1] * i % mod;

    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    vector<pii> b(2 * n);

    for(int i = 0;i < n;i++) {
        cin >> a[i].fi >> a[i].se;
        b[i * 2] = mp(a[i].fi, -1);
        b[i * 2 + 1] = mp(a[i].se, 1);
    }

    int cnt = 0;
    int res = 0;

    sort(all(b));

    for(auto i : b) {
        cnt -= i.se;
        if (i.se == -1) res += cnk(cnt - 1, k - 1);
    }

    cout << res % mod;
}