#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

const int MOD = 998244353;

int binpow(int n, int v){
    if (v == 0) return 1;
    if (v % 2 == 0){
        int g = binpow(n, v / 2) % MOD;
        return (g * g) % MOD;
    }
    else{
        return ( binpow(n, v - 1) * n % MOD);
    }
}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> fib(n + 100);
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= MOD;
    }
    int now = 1;
    for (int i = 0; i < n; i++){
        now *= 2;
        now %= MOD;
    }
    cout << (fib[n] * (binpow(now, MOD - 2)) % MOD + MOD) % MOD;
    return 0;
}