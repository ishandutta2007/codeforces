#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <functional>
#include <set>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 1e9 + 7, N = 10;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        multiset <int> a;
        for (int i = 0, x; i < n; ++i) {
            cin >> x; a.insert(x);
        }
        int ans = n;
        while (!a.empty()) {
            auto x = *a.begin();
            a.erase(a.begin());
            if (a.find(x * k) != a.end())
                a.erase(a.find(x * k)), ans -= 2;
        }
        cout << ans << '\n';
    }

    return 0;
}