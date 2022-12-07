#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

const int MAXN = 100010;

int n, m;
bool vis[MAXN];
vector<int> E[MAXN];
int c[MAXN];
vector<int> path;

void dfs(int u){
    vis[u] = 1;
    path.push_back(u);
    c[u] ^= 1;
    for(int v : E[u])
        if(!vis[v]){
            dfs(v);
            path.push_back(u);
            c[u] ^= 1;
            if(c[v]){
                path.push_back(v);
                c[v] ^= 1;
                path.push_back(u);
                c[u] ^= 1;
            }
        }
}

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,m){
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    FWD(i,1,n+1) scanf("%d", &c[i]);
    int s = 1;
    FWD(i,2,n+1) if(c[i]) s = i;
    dfs(s);
    if(c[s]){path.pop_back(); c[s] ^= 1;}
    bool ok = 1;
    FWD(i,1,n+1) if(c[i]) ok = 0;
    if(ok){
        printf("%d\n", (int)path.size());
        for(int u : path) printf("%d ", u);
        if(path.size()) printf("\n");
    }else printf("-1\n");
    return 0;
}