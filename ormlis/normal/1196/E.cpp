#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 5001;
ll md = 1000000007;

void solve() {
    int b, w; cin >> w >> b;
    vector<pair<int, int>> ans;
    if (b >= w) {
        range(i, w) {
            ans.emplace_back(i * 2 + 1, 1);
            ans.emplace_back(i * 2 + 2, 1);
        }
        b -= w;
        if (b) {
            ans.emplace_back(w * 2 + 1, 1);
            b--;
        }
        w = 0;
        int s = ans.size();
        range(i, s) {
            if (!b) {
                break;
            }
            if ((ans[i].first + ans[i].second) % 2) {
                ans.emplace_back(ans[i].first, ans[i].second - 1);
                b--;
                if (!b) {
                    break;
                }
                ans.emplace_back(ans[i].first, ans[i].second + 1);
                b--;
            }
        }
    } else {
        range(i, b) {
            ans.emplace_back(i * 2, 1);
            ans.emplace_back(i * 2 + 1, 1);
        }
        w -= b;
        if (w) {
            ans.emplace_back(b * 2, 1);
            w--;
        }
        b = 0;
        int s = ans.size();
        range(i, s) {
            if (!w) break;
            if ((ans[i].first + ans[i].second) % 2 == 0) {
                ans.emplace_back(ans[i].first, ans[i].second - 1);
                w--;
                if (!w) {
                    break;
                }
                ans.emplace_back(ans[i].first, ans[i].second + 1);
                w--;
                if (!w) break;
            }
        }
    }
    if (!b && !w) {
        cout << "YES\n";
        for(auto x: ans) {
            cout << x.first + 1 << " " << x.second + 1 << "\n";
        }
    } else {
        cout << "NO\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}