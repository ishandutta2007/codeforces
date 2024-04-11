#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 998244353, N = 2e5 + 3;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n % 7) {
            for (int i = 0; i < 10; ++i)
                if ((n - n % 10 + i) % 7 == 0) {
                    cout << n - n % 10 + i << '\n';
                    break;
                }
        }
        else cout << n << '\n';
    }

    return 0;
}