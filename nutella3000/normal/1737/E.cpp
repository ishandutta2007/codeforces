#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15 + 7;
const ll mod = 1e9 + 7;
const int N = 1e6 + 5;

ll binpow(ll a, ll b) {
    ll r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}
ll inv(ll a) { return binpow(a, mod - 2); }

int n;
ll F[N], G[N];

void run() {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        F[i] = 0;
        G[i] = 0;
    }

    ll inv2 = inv(2);

    ll pow[n+1] = {};
    pow[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow[i] = pow[i-1] * inv2 % mod;

    F[n] = G[n] = 1;
    for (int k = n-1; k >= 1; --k) {
        F[k] = (G[k+1] * inv2 - (2 * k <= n ? G[2*k] * pow[k] : 0)) % mod;
        G[k] = (F[k] + G[k+1] * inv2) % mod;
    }

    for (int k = 1; k <= n; ++k) {
        cout << (2 * pow[(k+1)/2] * F[k] % mod + mod) % mod << '\n';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}