#include<bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;

struct Edge{
    int to,w,nxt;//id
}e[MAXN<<1];
int head[MAXN],cnt = 1;
int ans[MAXN];// 1:  2:
bool vis[MAXN];

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

inline void dfs(int v){
    vis[v] = 1;
    for(int &i = head[v];i;i = e[i].nxt){
        if(ans[e[i].w]) continue;
        ans[e[i].w] = 1+(i&1);
        int t = i;dfs(e[i].to);
    }
}
int n;
int du[MAXN],lst;
int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x,y;scanf("%d%d",&x,&y);
        add(x,y+2e5,i);du[x]++;du[y+200000]++;
    }
    int cnttt = n;
    FOR(i,1,4e5){
        if(du[i]&1){
            add(0,i,++cnttt);
        }
    }
    if(lst){puts("-1");return 0;}
    FOR(i,1,4e5) if(du[i] && !vis[i]) dfs(i);
    FOR(i,1,n) putchar(ans[i]==1?'b':'r');
    return 0;
}