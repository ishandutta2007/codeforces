#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cassert>
#include <numeric>
#include <climits>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 5e5 + 2, L = 30;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        map <int, vector <int>> ids;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            ids[x].push_back(i);
        }
        vector <int> ans(n);
        while (!ids.empty()) {
            vector <int> vs, is, ks;
            for (auto& x : ids) {
                vs.push_back(x.first);
                is.push_back(x.second.back());
                x.second.pop_back();
                if (x.second.empty()) ks.push_back(x.first);
            }
            for (int i = 0; i < vs.size(); ++i) {
                ans[is[(i + 1) % is.size()]] = vs[i];
            }
            for (auto& x : ks)
                ids.erase(x);
        }
        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
    }
    
    return 0;
}