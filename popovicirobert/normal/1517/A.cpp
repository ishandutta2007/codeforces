#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
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
    while (t--) {
        ll n;
        cin >> n;
        const int MOD = 2050;
        if (n % MOD == 0) {
            n /= MOD;
            int ans = 0;
            while (n > 0) {
                ans += n % 10;
                n /= 10;
            }
            cout << ans << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    
    return 0;
}