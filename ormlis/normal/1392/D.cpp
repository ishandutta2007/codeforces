#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<int, int>> w;
    for(int i = 0, j = 0; i < n; i = j) {
        while(s[j] == s[i]) j++;
        w.emplace_back(i, j);
    }
    if (w.size() == 1) {
        cout << (n-1)/3 + 1 << "\n";
        return;
    }
    if (w.back().second == n && w[0].first == 0 && s[w.back().first] == s[w[0].first]) {
        w[0].first = - (w.back().second - w.back().first);
        w.pop_back();
    }
    int ans = 0;
    for(auto &p: w) {
        int k = p.second - p.first - 2;
        if (k <= 0) continue;
        ans += (k-1)/3+1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}