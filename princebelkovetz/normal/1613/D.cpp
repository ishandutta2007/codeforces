#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <stack>

using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 998244353, N = 5e6 + 5;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <int> a(n);
        for (auto& x : a) cin >> x;
        map <int, int> can, cant, cant2;
        can[-1] = 1;
        int ans = 0;
        for (auto& x : a) {
            ans += can[x - 2] + can[x - 1] + can[x] + cant[x] + cant[x + 2] + cant2[x] + cant2[x - 2];
            can[x] += can[x - 1] + can[x];
            cant[x] += can[x - 2] + cant[x] + cant2[x - 2];
            cant2[x] += cant2[x] + cant[x + 2];
            ans %= mod, can[x] %= mod, cant[x] %= mod, cant2[x] %= mod;
        }
        cout << ans << '\n';
    }
    

}