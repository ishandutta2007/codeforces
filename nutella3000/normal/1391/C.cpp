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
        if (b & 1) res = res * a % mod;

    return res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int res = 1;
    for(int i = 1;i <= n;i++) res = res * i % mod;
    cout << (res - binpow(2, n - 1) + mod) % mod << endl;
}