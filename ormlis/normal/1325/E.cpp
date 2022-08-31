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
const int maxN = 1e6 + 1;
ll md = 1000000007;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

map<int, vector<pair<int, int>>> g;

void solve() {
    vector<int> d(1e4, 1);
    vector<int> p;
    for (int i = 2; i < 1e4; ++i) {
        if (d[i]) {
            p.push_back(i);
            for (int j = i; j < 1e4; j += i) {
                d[i] = 0;
            }
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int cw = 0;
    for (auto x: a) {
        vector<int> s;
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            if (x % p[i] == 0) {
                int cnt = 0;
                while (x % p[i] == 0) {
                    x /= p[i];
                    cnt++;
                }
                if (cnt % 2) s.push_back(p[i]);
            }
        }
        if (x != 1) {
            s.push_back(x);
        }
        while (s.size() < 2) {
            s.emplace_back(1);
        }
        g[s[0]].emplace_back(s[1], cw);
        g[s[1]].emplace_back(s[0], cw);
        cw++;
    }
    int ans = INFi;
    vector<int> order;
    for(auto &p: g) order.push_back(p.first);
    sort(all(order));
    range(i, n) {
        int start = order[i];
        map<int, int> d;
        d[start] = 0;
        queue<pair<int, int>> q;
        q.push({start, -1});
        while(!q.empty()) {
            int v = q.front().first;
            int w = q.front().second;
            q.pop();
            for(auto &u: g[v]) {
                if (u.second == w) continue;
                if (d.count(u.first)) {
                    ans = min(ans, d[v] + 1 + d[u.first]);
                } else {
                    d[u.first] = d[v] + 1;
                    q.push({u.first, u.second});
                }
            }
        }
        if (getTime() > 2.8) {
            break;
        }
    }
    if (ans == INFi) {
        cout << -1;
    } else {
        cout << ans;
    }
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