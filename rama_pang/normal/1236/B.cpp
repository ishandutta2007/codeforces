#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;

lint pw(lint n, lint x) {
    if (x == 1) return n % MOD;
    if (x == 0) return 1;
    if (x & 1) return (n * pw(n, x - 1)) % MOD;
    lint res = pw(n, x / 2);
    res *= res;
    res %= MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    lint n, m; 
    cin >> n >> m;

    lint base = pw(2, m) - 1 + MOD;
    base %= MOD;
    lint ans = pw(base, n);
    ans %= MOD;
    cout << ans << "\n";
    

}