#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;

const int N = (int) 2e5 + 123;

int n;
int a[N], b[N];
int ans[N];
vector<int> g[N];

void dfs(int v) {
    for (int u : g[v]) {
        if (!ans[u]) {
            ans[u] = ans[v] == 1 ? 2 : 1;
            dfs(u);
        }
    }
}

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
        g[2 * i].push_back(2 * i + 1);
        g[2 * i + 1].push_back(2 * i);
    }
    
    for (int i = 0; i < 2 * n; i++) {
        if (!ans[i]) {
            ans[i] = 1;
            dfs(i);
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[a[i]] << " " << ans[b[i]] << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}