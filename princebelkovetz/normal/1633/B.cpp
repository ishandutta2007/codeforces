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
        string s; cin >> s;
        vector <int> cnt(2);
        for (auto& x : s) cnt[x - '0']++;
        cout << (cnt[0] == cnt[1] ? cnt[0] - 1 : min(cnt[0], cnt[1])) << '\n';
    }

    return 0;
}