#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 210000;

vector<int>g[maxn];
int sn, se;
bool f[maxn];

void dfs(int x) {
    f[x] = true;
    sn++;
    for (int i = 0; i < (int)g[x].size(); i++) {
        int y = g[x][i];
        if (!f[y]) dfs(y);
    }
    se += g[x].size();
}
int main() {
    //freopen("a.in","r",stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(f,0,sizeof(f));
    bool ff = true;
    for (int i = 1; i <= n; i++) {
        if (f[i]) continue;
        sn = se = 0;
        dfs(i);
        if (se != 1LL*sn*(sn-1)) {
            ff = false;
            break;
        }
    }
    if (ff)
        printf("YES\n");
    else
        printf("NO\n");
}