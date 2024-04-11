#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int mod = 998244353;

int binpow(int a, int b) {
    int res = 1;
    while(b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int rev(int a) {
    return binpow(a, mod - 2);
}




signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> c(n), suf(n);
    for(int i = 0;i < n;i++) cin >> c[i];
    sort(c.begin(), c.end(), [](int v1, int v2) {return v1 > v2;});

    suf[n - 1] = c[n - 1];
    for(int i = n - 2;i >= 0;i--) suf[i] = suf[i + 1] + c[i];

    vector<int> res(n + 1);

    for(int k = 1;k <= n;k++) {
        for(int i = k;i < n;i += k) {
            res[k] += suf[i];
        }
    }

    for(int i = 1;i <= n;i++) {
        cout << res[i] % mod * rev(n) % mod << " ";
    }
}