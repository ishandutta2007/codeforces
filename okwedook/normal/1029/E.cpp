#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5;
int n;
vector<int> G[N];
int rev[N];
bool used[N], used1[N];
vector<int> arr;

void dfs(int v = 0, int d = 0, int p = 0) {
    used1[v] = true;
    rev[v] = p;
    for (auto i : G[v])
        if (!used1[i])
            dfs(i, d + 1, v);
    if (d > 2) arr.pb(v);
}

int main() {
    FAST;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs();
    int ans = 0;
    for (auto i : arr) 
        if (!used[i]) {
            ++ans;
            used[rev[i]] = true;
            for (auto j : G[rev[i]]) used[j] = true;
        }
    cout << ans;
    return 0;
}