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
    while (tt-- > 0) {
        int n, m; cin >> n >> m;
        vector <int> a(n);
        map <int, int> cnt;
        for (auto& x : a) cin >> x, cnt[x]++;
        map <int, vector <int>> f;
        for (auto& x : cnt)
            f[x.second].push_back(x.first);
        vector <int> fs;
        vector <vector <int>> b;
        for (auto& x : f)
            sort(x.second.rbegin(), x.second.rend());
        for (auto& x : f) {
            fs.push_back(x.first);
            b.push_back(x.second);
        }
        map <int, set <int>> g;
        for (int i = 0, x, y; i < m; ++i) {
            cin >> x >> y;
            g[x].insert(y);
            g[y].insert(x);
        }
        int ans = 0;
        for (int k1 = 0; k1 < b.size(); ++k1) {
            for (int k2 = 0; k2 <= k1; ++k2) {
                for (auto& el : b[k1]) {
                    int i = 0;
                    while (i < b[k2].size() and ((g.find(el) != g.end() and g[el].find(b[k2][i]) != g[el].end())
                        or el == b[k2][i])) {
                        i++;
                    }
                    if (i < b[k2].size())
                        ans = max(ans, (fs[k1] + fs[k2]) * (el + b[k2][i]));
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}