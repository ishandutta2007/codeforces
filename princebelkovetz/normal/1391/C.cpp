#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <deque>
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
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector <int> dp(n + 1);
    dp[3] = 2;
    int fact = 6, mod = 1e9 + 7;
    for (int i = 4; i <= n; ++i) {
        dp[i] = ((dp[i - 1] * 2) % mod + (fact * (i - 2)) % mod) % mod;
        fact = (fact * i) % mod;
    }
    cout << dp[n];
    return 0;
}