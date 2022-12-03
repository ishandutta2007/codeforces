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
 
const int N = 1e5 + 5;
 
vector<int> g[N];
vector<int> gr[N];
int used[N];
 
void dfs(int v) {
    used[v] = 1;
    for (int u : gr[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}
 
int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    if (n <= 10000) {
        vector<int> dist(n + 1);
        vector<int> used(n + 1);
        dist[1] = 0;
        used[1] = 1;
        for (int i : g[1]) {
            dist[i] = 1;
        }
        for (int i = 1; i < n; i++) {
            int v = -1;
            for (int j = 1; j <= n; j++) {
                if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                    v = j;
                }
            }
            ans += dist[v];
            used[v] = 1;
            vector<int> keks(n + 1);
            for (int j : g[v]) {
                keks[j] = 1;
            }
            for (int j = 1; j <= n; j++) {
                if (!keks[j]) {
                    dist[j] = 0;
                }
            }
        }
    } else {
        vector<int> sub(n + 1);
        int koko = 0;
        for (int i = 1; i <= n; i++) {
            if (g[i].size() > n / 3) {
                sub[i] = 1;
                koko++;
            }
        }
        sub[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (sub[i]) {
                vector<int> kek(n + 1);
                for (int j : g[i]) {
                    kek[j] = 1;
                }
                int sz = 0;
                for (int j = 1; j <= n; j++) {
                    if (sub[j] && !kek[j]) {
                        gr[i].push_back(j);
                        gr[j].push_back(i);
                    }
                    if (sub[j] && kek[j]) {
                        sz++;
                    }
                }
                if (g[i].size() - sz != n - koko) {
                    gr[i].push_back(0);
                    gr[0].push_back(i);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (!used[i] && sub[i]) {
                ans++;
                dfs(i);
            }
        }
        ans--;
    }
    cout << max(ans, 0) << endl;
}