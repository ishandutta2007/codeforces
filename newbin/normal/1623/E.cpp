#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
const int maxn = 2e5+5;
char s[maxn];
int ch[maxn][2], fa[maxn];
int vis[maxn], n, k;
int dfn[maxn], idx = 0;
void dfs(int u){
    if(!u) return;
    dfs(ch[u][0]); dfn[++idx] = u; dfs(ch[u][1]);
}
int mark[maxn];

void go(int u, int flag, int dep){
    if(u == 0) return;
    go(ch[u][0], flag, dep+1);
    if(!flag && vis[u] && !mark[u]){
        if(k >= dep){
            k -= dep;
            int cur = u; while(!mark[cur]) mark[cur] = 1, cur = fa[cur];
        }
    }
    int c = dep; if(mark[u]) c = 0;
    go(ch[u][1], !mark[u] , c+1);
}
void show(int u){
    if(u == 0) return;
    show(ch[u][0]);
    printf("%c", s[u]);
    if(mark[u] == 1) printf("%c", s[u]);
    show(ch[u][1]);
    return;
}
int main(){
    cin>>n>>k;
    scanf("%s", s+1);
    fors(i,1,n+1){
        int x, y; scanf("%d%d", &x, &y);
        tie(ch[i][0],ch[i][1]) = tie(x, y);
        fa[x] = fa[y] = i;
    }
    dfs(1);
    for(int i = 1; i <= n; ++i){
        if(s[dfn[i]] < s[dfn[i+1]]){
            int j = i;
            while(j-1>0 && s[dfn[j-1]] == s[dfn[i]]) j--;
            while(j<=i) vis[dfn[j++]] = 1;
        }
    }
    
    mark[0] = 1; fa[0] = 0;
    go(1, 0, 1);
    show(1);
    return 0;
}