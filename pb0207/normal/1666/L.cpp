#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, s;
int gp[N], ff[N];
vector<int> g[N];
inline void PrintAns(vector<int> ans, int x) {
    while (x != -1) {
        ans.push_back(x);
        x = ff[x];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x: ans) printf("%d ", x);
    puts("");
}
inline void Dfs(int x, int fa, int bel) {
    ff[x] = fa; gp[x] = bel;
    for (auto y: g[x]) if (!gp[y]) {
        Dfs(y, x, bel);
    } else if (gp[y] != bel) {
        if (y == s) continue;
        puts("Possible");
        PrintAns({y}, x);
        PrintAns({}, y);
        exit(0);
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
    ff[s] = -1; gp[s] = -1;
    for (auto y: g[s]) {
        if (gp[y] && gp[y] != y) {
            puts("Possible");
            PrintAns({y}, s);
            PrintAns({}, y);
            exit(0);
        }
        Dfs(y, s, y);
    }
    puts("Impossible");
    return 0;
}