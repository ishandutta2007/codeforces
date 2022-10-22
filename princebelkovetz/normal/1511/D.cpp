#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define ld long double
#define int long long
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int n, k; cin >> n >> k;
    vector <int> ok = {};
    for (int i = 0; i < k; ++i) {
        ok.push_back(i);
        for (int j = i + 1; j < k; ++j)
            ok.push_back(i), ok.push_back(j);
    }
    vector <int> ans = ok;
    while (ans.size() < n)
        for (auto x : ok)
            ans.push_back(x);
    for (int i = 0; i < n; ++i) {
        cout << (char)('a' + ans[i]);
    }
    cout << '\n';
    return 0;
}