#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
using namespace std;



 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, l, r;
        cin >> n >> l >> r;

        // x
        // r >= i - x >= l =>  i >= l + x
        // r >= i + x >= l =>  r - x >= i
        // r - x >= i >= l + x

        constexpr int MOD = (int)1e9 + 7;

        auto lgput = [&](int a, int b) {
            int ans = 1;
            while (b > 0) {
                if (b & 1) ans = (1LL * ans * a) % MOD;
                b >>= 1;
                a = (1LL * a * a) % MOD;
            }
            return ans;
        };

        vector<int> fact(n + 1, 1), invfact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
            invfact[i] = lgput(fact[i], MOD - 2);
        }

        auto comb = [&](int n, int k) {
            if (n < k || n < 0 || k < 0) return 0LL;
            return (1LL * fact[n] * (1LL * invfact[k] * invfact[n - k] % MOD)) % MOD;
        };

        int x = max(1, min(r - n, 1 - l)), ans = 0;

        if (n % 2 == 0) {
            ans = (ans + 1LL * (x - 1) * comb(n, n / 2)) % MOD;
        } else {
            ans = (ans + 1LL * (x - 1) * (comb(n, n / 2) + comb(n, (n + 1) / 2))) % MOD;
        }

        while (min(n, r - x) + 1 >= max(1, l + x)) {
            int start = max(1, l + x);
            int stop = min(n, r - x);

            if (n % 2 == 0) {
                ans = (ans + comb(stop - start + 1, n / 2 - (n - stop))) % MOD;
            } else {
                ans = (1LL * ans + comb(stop - start + 1, n / 2 - (n - stop))
                                 + comb(stop - start + 1, (n + 1) / 2 - (n - stop))) % MOD;

                if (tt == 1) {
                    cerr << start << " " << stop << "\n";    
                }
            }

            x++;
        }

        cout << ans << "\n";
    }



    return 0;
    
}