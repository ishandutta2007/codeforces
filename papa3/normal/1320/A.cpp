#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

int tab[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int res = 0;
    for (int a, i = n; i >= 1; i--) {
        cin >> a;
        tab[a + i] += a;
        res = max(res, tab[a + i]);
    }
    
    cout << res;
    
    return 0;
}/*

*/