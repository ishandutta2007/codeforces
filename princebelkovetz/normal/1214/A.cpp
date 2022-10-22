#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(7);
    int n, d, e; cin >> n >> d >> e;
    int ans = 1e9;
    for (int i = 0; d * i <= n; ++i) {
        ans = min(ans, (n - d * i) % (5 * e));
    }
    cout << ans << endl;
}