#include <iostream>

using namespace std;

const long long MOD = 998244353;

long long pw(long long a, int n){
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return pw(a, n - 1) * a % MOD;
    long long tmp = pw(a, n / 2);
    return tmp * tmp % MOD;
}

long long anti[200001];

int main(){
    int n;
    cin >> n;
    long long t;
    cin >> t;
    if (t >= n){
        cout << 0 << '\n';
        return 0;
    }
    int k = n - t;
    if (k == n){
        long long ans = 1;
        for (int i = 1; i <= n; ++i)
            ans = (ans * i) % MOD;
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        anti[i] = pw(i, MOD - 2);
    long long ans = 0;
    long long C = 1;
    for (int i = 1; i <= k; ++i){
        C = C * (k - i + 1) % MOD * anti[i] % MOD;
        long long tmp = C * pw(i, n) % MOD;
        if ((k - i) % 2 == 1){
            ans -= tmp;
            if (ans < 0)
                ans += MOD;
        } else {
            ans += tmp;
            if (ans >= MOD)
                ans -= MOD;
        }
    }
    for (int i = 1; i <= k; ++i)
        ans = ans * (n + 1 - i) % MOD * anti[i] % MOD;
    ans = (ans * 2) % MOD;
    cout << ans << '\n';
    return 0;
}