#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int mod = 1e9 + 7;
 
int binpow(int a, int b) {
    int res = 1;
    for(;b;b /= 2, a = a * a % mod) 
        if(b & 1) 
            res = res * a % mod;
 
    return res;
}
 
int reverse(int a) {
    return binpow(a, mod - 2);
}
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n, m;
    cin >> n >> m;
 
    int q = n * binpow(m, n - 1) % mod;
    if (m != 2 * m - 1) 
        q = (binpow(2 * m - 1, n) - binpow(m, n)) * reverse(m - 1) % mod;
 
    //cout << q << endl;
 
    int res = m * q % mod + binpow(m, n) % mod;
 
    cout << (res + mod) % mod;
}