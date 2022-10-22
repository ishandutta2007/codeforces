#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, p = 239, N = 4e5 + 5;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector <vector <int>> a(n - 1);
        for (auto& x : a) {
            int k; cin >> k;
            x.resize(k);
            for (auto& y : x) 
                cin >> y, --y;
        }
        vector <int> ans(n);

        for (int i = 0; i < n; ++i) {
            ans[0] = i;
            vector <set <int>> ok(n - 1);
            vector <vector <int>> ids(n - 1);
            for (int j = 0; j < n - 1; ++j) {
                for (auto& x : a[j])
                    ok[j].insert(x);
            }
            bool able = true;
            for (int j = 1; j < n; ++j) {
                int cnt = 0, id = 0;
                for (int k = 0; k < n - 1; ++k) {
                    if (ok[k].find(ans[j - 1]) != ok[k].end())
                        ids[k].push_back(j);
                    ok[k].erase(ans[j - 1]);
                    if (ok[k].size() == 1)
                        cnt++, id = k;
                }
                if (cnt != 1) {
                    able = false;
                    break;
                }
                for (int k = 0; k + 1 < ids[id].size(); ++k)
                    if (ids[id][k] != ids[id][k + 1] - 1)
                        able = false;
                if (!able) break;
                ans[j] = *ok[id].begin();
            }
            if (able) break;
        }
        for (auto& x : ans) cout << ++x << ' ';
        cout << '\n';


    }

    return 0;
}