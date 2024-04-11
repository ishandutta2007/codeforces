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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int x = 0;
    for (int a, b, i = 1; i <= n; i++) {
        cin >> b;
        a = x + b;
        cout << a << " ";
        x = max(x, a);
    }
    
    return 0;
}/*

*/