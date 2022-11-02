#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
//const int mod = 1000000007;
int mod;

int pot(int n, int k) {
    int res = 1;
    //cout << n << " " << k << " ";
    while (k) {
        if (k % 2) {
            res = res * n % mod;
        }
        n = n * n % mod;
        k /= 2;
    }
    //cout << res << endl;
    return res;
}

int silnia[1000010];

int dwumian(int n, int k) {
    //cout << n << " " << k << " " << silnia[n] << " " << silnia[k] << endl;
    //cout << silnia[n] * pot(silnia[k], mod - 2) % mod * pot(silnia[n - k], mod - 2) % mod << endl;
    return silnia[n] * pot(silnia[k], mod - 2) % mod * pot(silnia[n - k], mod - 2) % mod;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    silnia[0] = 1;
    int n;
    cin >> n >> mod;
    for (int i = 1; i <= n + 10; i++) {
        silnia[i] = silnia[i - 1] * i % mod;
        //cout << silnia[i] << endl;
    }
    
    int res = 0;
    for (int k = 1; k <= n; k++) {
        res += (n - k + 1) * (n - k + 1) % mod * silnia[k] % mod * silnia[n - k];
        res %= mod;
        //cout << res << endl;
    }
    
    cout << res;
    
    return 0;
}