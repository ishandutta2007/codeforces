#include<cstdio>
#include<cstring>

#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 210000;
int p;
struct node {
    int nex;
}a[maxn];
struct edge {
    int nex, y;
}e[maxn*2];

long long f[maxn][11];
long long w[11];
void add(int x, int y) {
    p++;
    e[p].nex = a[x].nex;
    e[p].y = y;
    a[x].nex = p;
}

int n, m;

void dfs(int x, int fa) {
    f[x][0]++;
    for (int t = a[x].nex; t; t = e[t].nex) {
        int y = e[t].y;
        
        if (y == fa) continue;
        
        dfs(y, x);
        
        f[x][m] += f[y][m]+f[y][0];
        for (int i = 0; i < m; i++) {
            f[x][i] += f[y][(i+m-1)%m];
        }
    }
}

void calc(int x, int fa) {
    
    if (fa != 0) {
        for (int i = 0; i <= m; i++) {
            w[i] = f[fa][i];
            
            
        }
        w[m] -= f[x][m]+f[x][0];
        for (int i = 0; i < m; i++) {
            w[i] -= f[x][(i+m-1)%m];
        }
        
        f[x][m] += w[m]+w[0];
        
        for (int i = 0; i < m; i++) {
            f[x][i] += w[(i+m-1)%m];
        }
        
    }
    for (int t = a[x].nex; t; t = e[t].nex) {
        int y  =e[t].y;
        if (y == fa) continue;
        calc(y, x);
    }
}

int main() {
    //freopen("c.in","r",stdin);
    
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x,y);
        add(y,x);
    }
    
    dfs(1, 0);
    
    
    calc(1, 0);
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += f[i][m];
    cout << ans/2 << endl;
    
}