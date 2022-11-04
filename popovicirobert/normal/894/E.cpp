#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MAXN = (int) 1e6;
const int DIM = (int) 2e4 + 10;

struct Edge {
    int x, y;
    int w;
}edge[MAXN + 1];

vector < pair <int, int> > g[MAXN + 1];
vector < pair <int, int> > rev[MAXN + 1];

int top[MAXN + 1];
int sz = 0;

bool viz[MAXN + 1];

void top_sort(int nod) {
    viz[nod] = 1;
    for(auto it : g[nod]) {
        if(viz[it.first] == 0)
           top_sort(it.first);
    }
    top[++sz] = nod;
}

int ind[MAXN + 1];
int cnt = 0;

void CTC(int nod) {
    ind[nod] = cnt;
    for(auto it : rev[nod]) {
        if(ind[it.first] == 0)
            CTC(it.first);
    }
}

ll sum[MAXN + 1];
ll sp[DIM + 1];

inline ll cst(int val) {
    int res = 0;
    for(int pas = 1 << 13; pas; pas >>= 1) {
        if((res + pas) * (res + pas + 1) <= 2 * val)
            res += pas;
    }
    return 1LL * (res + 1) * val - sp[res];
}

ll dp[MAXN + 1];

void dfs(int nod) {
    viz[nod] = 1;
    for(auto it : g[nod]) {
       if(viz[it.first] == 0)
           dfs(it.first);
       dp[nod] = max(dp[nod], it.second + dp[it.first]);
    }
    dp[nod] += sum[nod];
}

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    scanf("%d%d" ,&n,&m);
    for(i = 1; i <= m; i++) {
        int x, y, w;
        scanf("%d%d%d" ,&x,&y,&w);
        g[x].push_back({y, w});
        rev[y].push_back({x, w});
        edge[i] = {x, y, w};
    }
    for(i = 1; i <= n; i++) {
        if(viz[i] == 0)
           top_sort(i);
    }
    memset(viz, 0, sizeof(viz));
    for(i = n; i >= 1; i--) {
        if(ind[top[i]] == 0) {
            cnt++;
            CTC(top[i]);
        }
    }
    for(i = 1; i <= n; i++) {
        g[i].clear();
    }
    for(i = 1; i <= DIM; i++) {
        sp[i] = sp[i - 1] + (i * (i + 1)) / 2;
    }
    for(i = 1; i <= m; i++) {
        if(ind[edge[i].x] == ind[edge[i].y])
            sum[ind[edge[i].x]] += cst(edge[i].w);
        else
            g[ind[edge[i].x]].push_back({ind[edge[i].y], edge[i].w});
    }
    memset(viz, 0, sizeof(viz));
    int nod;
    scanf("%d" ,&nod);
    nod = ind[nod];
    dfs(nod);
    printf("%I64d" ,dp[nod]);
    //cin.close();
    //cout.close();
    return 0;
}