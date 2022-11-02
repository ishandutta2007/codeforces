#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = n; i > n - k; i--) {
        res += i;
    }
    
    int wyn = 0;
    int aku = 1;
    for (int a, i = 0; i < n; i++) {
        cin >> a;
        if (a > n - k) {
            wyn = wyn * aku % mod;
            aku = 0;
            wyn = max(wyn, 1LL);
        }
        aku++;
    }
    
    cout << res << " " << wyn;
    
    return 0;
}/*

*/