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

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    int n; cin >> n;
    vector<int> q(n), p(n);
    range(i, n) cin >> q[i];
    range(i, n) q[i]--;

    vector<vector<vector<int>>> s(n + 1);
    vector<int> used(n, 0);
    range(i, n) {
        if (used[i]) continue;
        vector<int> cycle = {i};
        int cur = q[i];
        while(cur != i) {
            used[cur] = 1;
            cycle.push_back(cur);
            cur = q[cur];
        }
        s[(int)cycle.size()].push_back(cycle);
    }
    for(int sz = n; sz > 0; --sz) {
        if (sz & 1) {
            for(auto &cycle: s[sz]) {
                int x = (sz+1)/2;
                range(i, sz) {
                    p[cycle[i]] = cycle[(i+x)%sz];
                }
            }
        } else {
            if (s[sz].size() & 1) {
                cout << "-1\n";
                return;
            }
            range(i,(int)s[sz].size() / 2) {
                int j = i * 2;
                int e = j + 1;
                range(k, sz) {
                    p[s[sz][j][k]] = s[sz][e][k];
                    p[s[sz][e][k]] = s[sz][j][(k+1)%sz];
                }
            }
        }
    }
    range(i, n) cout << p[i] + 1 << " ";
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