#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};


void solve() {
    int n, m; cin >> n >> m;
    vector<int> ans;
    for(int i = 1; m && i <= n; ++i) {
        int w = (i-1)/2;
        if (w > m) {
            for(int j = i + 1; w != m; ++j) {
                w = (i - (j - (i - 1))) / 2;
                if (w == m) {
                    ans.push_back(j);
                    break;
                }
            }
            m -= w;
            break;
        }
        m -= w;
        ans.push_back(i);
    }
    if (m) {
        cout << -1;
    } else {
        for(int i = ans.size()-n+1; i <= 0; ++i) ans.push_back((int)1e9 + 5001 * i);
        range(i, n) cout << ans[i] << " ";
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}