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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int res = 0;
    
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '(') {
            sum++;
        } else {
            sum--;
        }
        
        
        if (sum < 0) {
            res++;
        } else if (sum == 0 && c == '(') {
            res++;
        }
    }
    
    if (sum == 0) {
        cout << res;
    } else {
        cout << -1;
    }
    
    return 0;
}/*

*/