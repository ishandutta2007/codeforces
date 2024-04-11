#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 101;

int n, cyc;
vector<int> g[N];

bool active[N], visited[N];
void dfs(int x, int p = -1, int d = 1) {
    if (cyc) return;

    active[x] = true;
    visited[x] = true;

    for (int i : g[x]) {
        if (i == p) continue;

        if (active[i])
            cyc = d;
        else dfs(i, x, d + 1);
    }

    active[x] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int c = 0;
    for (int i = 1; i <= n; i++) {
        cyc = 0;
        if (!visited[i]) {
            dfs(i);
        }

        if (cyc % 2 != 0) c += 1;
    }

    cout << c + (n - c) % 2 << "\n";
    return 0;
}