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
vector <int> pws, pref;
int get(vector <string> a) {
    vector <int> lens;
    int n = a.size(), m = a[0].size(), sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '*') continue;
            int k = j;
            while (k < m and a[i][j] == a[i][k]) ++k;
            lens.push_back(k - j);
            sum += k - j;
            j = k - 1;
        }
    }
    int ans = 0;
    for (auto x : lens) {
        for (int i = 1; i <= x - 1; ++i) {
            int add = i & 1;
            if (i >= 2)
                add = (add + pref[i - 2]) % mod;
            add = add * pws[x - i - 1] % mod;
            add = (add * pws[sum - x]) % mod;
            ans = (ans + add) % mod;
        }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int n, m; cin >> n >> m;
    pws.resize(n * m + 5);
    pref.resize(n * m + 5);
    pws[0] = 1;
    for (int i = 1; i < pws.size(); ++i)
        pws[i] = (pws[i - 1] << 1) % mod;
    pref[0] = 1;
    pref[1] = 2;
    for (int i = 2; i < pref.size(); ++i) {
        pref[i] = (pref[i - 2] + pws[i]) % mod;
    }
    vector <string> a(n);
    for (auto& x : a) cin >> x;
    int res = get(a);
    vector <string> b(m, string(n, 'a'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            b[j][i] = a[i][j];
    }
    res = (res + get(b)) % mod;
    cout << res << '\n';
    return 0;
}