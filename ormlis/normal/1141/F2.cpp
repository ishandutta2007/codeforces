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
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 4000001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    int n; cin >> n;
    map<int, vector<pair<int, int>>> mp;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n){
        int s = 0;
        for(int j = i; j >= 0; --j) {
            s += a[j];
            pair<int, int> kek = {j, -1};
            int k = lower_bound(all(mp[s]), kek) - mp[s].begin();
            if (k != 0) {
                k--;
                mp[s].emplace_back(i, max(mp[s][k].second + 1, mp[s].back().second));
            } else {
                if (mp[s].empty()) mp[s].emplace_back(i, 1);
                else mp[s].emplace_back(i, mp[s].back().second);
            }
        }
    }
    pair<int, int> ans = {1, a[0]};
    for(auto &x: mp) {
        if (x.second.back().second > ans.first) {
            ans = {x.second.back().second, x.first};
        }
    }
    vector<pair<int, int>> toans = mp[ans.second];
    vector<pair<int, int>> answer;
    reverse(all(toans));
    int prev = n;
    range(i, toans.size()) {
        if (i != toans.size() - 1 && toans[i].second == toans[i+1].second) {
            continue;
        }
        if (toans[i].first >= prev) continue;
        int s = 0;
        int j = toans[i].first;
        for(; s != ans.second; --j) {
            s += a[j];
        }
        j = min(j+1, toans[i].first);
        answer.emplace_back(j, toans[i].first);
        prev = j;
    }
    if (ans.first != answer.size()) {
        cout << "FAIL\n";
    }
    cout << answer.size() << "\n";
    range(i, answer.size()) cout << answer[i].first+1 << " " << answer[i].second+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}