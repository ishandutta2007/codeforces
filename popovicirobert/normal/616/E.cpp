#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007


using namespace std;

inline ll sum(ll x) {
    x %= MOD;
    return (1LL * x * (x + 1) / 2) % MOD;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    long long n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ll ans = ((n % MOD) * (m % MOD)) % MOD;
    int rad = sqrt(n);
    for(int i = 1; i <= n / (rad + 1) && i <= m; i++) {
        ans -= (1LL * i * (n / i)) % MOD;
        if(ans < 0)
            ans += MOD;
    }
    for(int i = 1; i <= rad; i++) {
        ans -= (1LL * i * (sum(min(n / i, m)) - sum(min(n / (i + 1), m)) + MOD)) % MOD;
        if(ans < 0)
            ans += MOD;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}