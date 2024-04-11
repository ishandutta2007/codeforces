#pragma GCC optimize("O3")
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
 
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
 
using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;
 
int k;
vector<vector<int>> a;
ll sum;
map<int, int> box;
vector<ll> bs;
bool dp[1 << 15];
 
struct ROMA {
    int box;
    ll val;
    int to;
    bool operator < (const ROMA& o) const {
        return box < o.box;
    }
};
 
vector<ROMA> memo[1 << 15];
 
int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> k;
    a.resize(k);
    bs.resize(k, 0);
    for (int i = 0; i < k; i++) {
        int nn;
        cin >> nn;
        a[i].resize(nn);
        for (int j = 0; j < nn; j++) {
            cin >> a[i][j];
            sum += a[i][j];
            box[a[i][j]] = i;
            bs[i] += a[i][j];
        }
    }
    if (sum % k != 0) {
        return cout << "No", 0;
    }
    sum /= k;
    for (int start = 0; start < k; start++) {
        for (int start_el : a[start]) {
            vector<ROMA> path;
            vector<bool> was(k, false);
            int ibox = start;
            ll need = sum - (bs[start] - start_el);
            int mask = 0;
            bool bad = false;
            ll mem = need;
            while (!was[ibox]) {
                if (box.count(need) == 0) {
                    bad = true;
                    break;
                }
                int next_box = box[need];
                path.pb({ next_box, need, ibox });
                was[ibox] = true;
                mask |= (1 << ibox);
                ibox = next_box;
                need = sum - (bs[ibox] - need);
            }
            if (!bad && ibox == start) {
                if (need == mem) {
                    dp[mask] = true;
                    memo[mask] = path;
                }
            }
        }
    }
    for (int mask = 1; mask < (1 << k); mask++) {
        if (!dp[mask]) {
            for (int smask = mask; smask > 0; smask = (smask - 1) & mask) {
                if (dp[smask] && dp[mask ^ smask]) {
                    dp[mask] = true;
                    memo[mask] = memo[mask ^ smask];
                    for (auto e : memo[smask]) {
                        memo[mask].pb(e);
                    }
                }
            }
        }
    }
    if (dp[(1 << k) - 1]) {
        cout << "Yes\n";
        auto vec = memo[(1 << k) - 1];
        assert(sz(vec) == k);
        sort(all(vec));
        for (auto e : vec) {
            cout << e.val << ' ' << e.to + 1 << '\n';
        }
    }
    else {
        cout << "No\n";
    }
}