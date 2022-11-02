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
const int mod = 1000000007;

struct Algo {
    int n, pop;
    
    Algo() {
        cin >> n >> pop;
        int res = 0;
        for (int a, i = 1; i < n; i++) {
            cin >> a;
            if (a < pop) {
                int x = pop - a;
                int pot = 1;
                while (x >>= 1) {
                    pot++;
                }
                res = max(res, pot);
            }
            pop = max(pop, a);
        }
        cout << res << "\n";
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        Algo p;
    }
    
    return 0;
}/*

*/