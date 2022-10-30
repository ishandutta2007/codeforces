#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e9 + 7;
const int max_n = 1e6 + 4;

int n;
vector<int> gr[max_n];
int p[max_n], h[max_n];
int sz[max_n];
bool res = true;

void dfs(int v, int pr) {
    sz[v] = p[v];
    int bad_mood = p[v];
    for(int i : gr[v]) {
        if (i == pr) continue;
        dfs(i, v);
        bad_mood += (sz[i] - h[i]) / 2;
        sz[v] += sz[i];
    }

    if ((sz[v] - h[v]) % 2 != 0) res = false;
    if (sz[v] < h[v]) res = false;
    if (sz[v] - 2 * bad_mood > h[v]) res = false; 
}

void solve() {
    int m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) 
        gr[i].clear();
    for(int i = 0;i < n;i++) 
        cin >> p[i];
    for(int i = 0;i < n;i++) 
        cin >> h[i];
    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    res = true;
    dfs(0, -1);

    cout << (res ? "YES" : "NO") << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }   
}