#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;
 
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    lint n, p;
    cin >> n >> p;
    lint ans = 1e18;
    lint step = 0;
    
    while (1 <= n && n <= 8e18 && step <= 100000) {
        lint k = __builtin_popcountll(n);
        if (k <= step && step <= n) ans = min(ans, step);
        n -= p;
        step++;
        if (ans < step) break;
    }
    ans = (ans == 1e18)? -1 : ans;
    cout << ans << "\n";
 
}