#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e17 + 7;
const int max_n = 1e5 + 4;

int n;
vector<int> gr[max_n];
bool used[max_n];

bool dfs(int v, int pr) {
    if (used[v]) 
        return true;
    used[v] = true;

    for(int i : gr[v]) {
        if (i == pr)
            continue;
        if (dfs(i, v)) 
            return true;
    }
    return false;
}

void solve() {
    int m;
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    int res = 0;
    
    for(int i = 0;i < n;i++) {
        if (!used[i] && !dfs(i, -1))
            res++;
    }
    cout << res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}