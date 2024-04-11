#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())


typedef long double ld;
 
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const int max_n = 1e6 + 1;


int binpow(ll a, int b) {
    ll res = 1;
    for(;b;b /= 2, a = a * a % mod)
        if (b & 1)
            res = res * a % mod;

    return res;
}

int f[(1 << 20)][21];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        f[a[i]][0]++;
    }

    //cout << "bad" << endl;

    for(int i = (1 << 20) - 1;i >= 0;i--) {
        for(int j = 1;j <= 20;j++) {
            f[i][j] = f[i][j - 1];
            if (!((i >> (j - 1)) & 1))
                f[i][j] += f[i + (1 << (j - 1))][j - 1];

        }
    }

    ll res = 0;
    for(int i = 0;i < (1 << 20);i++) {
        res += binpow(-1, __builtin_popcount(i)) * binpow(2, f[i][20]);
    }
    cout << (res % mod + mod) % mod << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}