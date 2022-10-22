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
void dfs(int v, vector <bool> &used, vector <vector <pair <int, int>>> &a, vector <int> &num) {
    used[v] = true;
    
    for (auto u : a[v]) {
        if (used[u.first]) continue;
        dfs(u.first, used, a, num);
        num[v] += num[u.first];
    }
    if (!num[v]) ++num[v];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while(tt--) {
        int n, s; cin >> n >> s;
        vector <vector <pair <int, int>>> a(n + 1);
        vector <bool> used(n + 1);
        vector <int> num(n + 1);
        map <pair <int, int>, int> m, cost;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            a[u].push_back({ v, w });
            a[v].push_back({ u, w });
            cost[{u, v}] = w;
            cost[{v, u}] = w;
            m[{u, v}] = 0;
        }
        dfs(1, used, a, num);
        vector <int> ok;
        int sum = 0, ans = 0;
        for (auto &x : m) {
            x.second = min(num[x.first.first], num[x.first.second]);
            int c = cost[{x.first}];
            sum += c * x.second;
            while (c) {
                ok.push_back(x.second * (c - c / 2));
                c /= 2;
            }
        }
        sort(ok.rbegin(), ok.rend());
        for (int i = 0; i < (int)ok.size(); ++i) {
            if (sum <= s) break;
            sum -= ok[i];
            ++ans;
        }
        cout << ans << "\n";

    }
    return 0;
}