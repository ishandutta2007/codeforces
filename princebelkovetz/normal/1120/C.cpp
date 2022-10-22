#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <bitset>
#include <functional>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int mod = 1e9 + 7, p = 239;

vector <int> zf(string s) {
    int n = s.size();
    vector <int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(0ll, min(r - i, z[i - l]));
        while (i + z[i] < n and s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    vector <vector <int>> minId(n, vector <int>(n, n));
    for (int i = 0; i < n; ++i) {
        string t = s.substr(i, n - i) + '?' + s;
        vector <int> z = zf(t);
        for (int j = n - i + 1; j < t.size(); ++j) {
            if (!z[j]) continue;
            minId[i][z[j] - 1] = min(minId[i][z[j] - 1], j - n + i - 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 1; --j)
            minId[i][j - 1] = min(minId[i][j - 1], minId[i][j]);
    }
    vector <int> dp(n + 1, mod);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a;
        for (int j = i - 1; j >= 0; --j) {
            int id = minId[j][i - j - 1];
            int L = id, R = id + i - j - 1;
            if (R < j) dp[i] = min(dp[i], dp[j] + b);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}