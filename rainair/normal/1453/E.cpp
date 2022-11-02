#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 2e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int n;
int lim;
bool flag;
int f[MAXN];

inline void dfs(int v,int fa=0){
    int mx = -1,cmx = -1,mn = 1e9;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);mn = std::min(mn,f[e[i].to]);
        if(f[e[i].to] > mx){
            cmx = mx;mx = f[e[i].to];
        }
        else if(f[e[i].to] > cmx){
            cmx = f[e[i].to];
        }
    }
    if(mx == -1){
        f[v] = 0;
        return;
    }
    if(mx+2 <= lim){
        f[v] = mn+1;
    }
    else if(mx == lim-1){
        if(cmx == lim-1) flag = 0;
        else f[v] = lim;
    }
    else{
        flag = 0;
    }
}

inline bool chk(int mid){
    flag = 1;lim = mid;
    dfs(1);
    return flag;
}

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) head[i] = 0;cnt = 0;
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);add(u,v);
    }
    int l = 1,r = n,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}