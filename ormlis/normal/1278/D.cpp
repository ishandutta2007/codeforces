#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;
int n;
vector<pair<int, int>> scanline;
int arr[500002];
set<pair<int, int>> s;
vector<int> g[500001];
int used[500001];
int cnt = 0;
void dfs(int v) {
    used[v] = 1;
    cnt ++;
    for(auto u: g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

void solve() {
    cin >> n;
    scanline.resize(2 * n);
    range(i, n) {
        int l, r;
        cin >> l >> r;
        scanline[i * 2] = {l, i};
        scanline[i * 2 + 1] = {r, i};
        arr[i] = r;
    }
    ll ans = 0;
    sort(all(scanline));
    range(i, n * 2) {
        if (scanline[i].first == arr[scanline[i].second]) {
            s.erase({scanline[i].first, scanline[i].second});
        } else {
            s.insert({arr[scanline[i].second], scanline[i].second});
            auto it = s.begin();
            while ((*it).first < arr[scanline[i].second]) {
                g[scanline[i].second].push_back((*it).second);
                g[(*it).second].push_back(scanline[i].second);
                it++;
                ans++;
            }
        }
        if (s.empty() && i != n * 2 - 1) {
            cout << "NO";
            return;
        }
        if (ans > n - 1) {
            cout << "NO";
            return;
        }
    }
    if (ans == n - 1) {
        dfs(0);
        if (cnt == n) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}