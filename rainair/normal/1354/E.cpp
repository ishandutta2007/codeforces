/*
 * Author: RainAir
 * Time: 2020-05-17 17:58:46
 */
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

const int MAXN = 2e5 + 5;
int n,n1,n2,n3,m;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int col[MAXN];
bool flag = true;
std::vector<int> G[MAXN];
int tot;

inline void dfs(int v,int fa=0){
    G[tot].pb(v);
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        if(col[e[i].to] == -1){
            col[e[i].to] = col[v]^1;
            dfs(e[i].to,v);
        }
        else{
            if(col[e[i].to] == col[v]){
                flag = false;
                break;
            }
        }
    }
}
int a[MAXN],b[MAXN];
bool chg[MAXN];
int f[5005][5005],ans[MAXN];
bool use[MAXN];
int main(){
    scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&n3);
    bool exexex = (n1 == 1708)&&(n2==2333)&&(n3==959);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);add(u,v);
    }
    CLR(col,-1);
    FOR(i,1,n) if(col[i] == -1) ++tot,col[i]=0,dfs(i);
    if(!flag){
        puts("NO");
  //      if(exexex)puts("1");
        return 0;
    }
    int sm = 0;
    FOR(i,1,tot){
        for(auto x:G[i]){
            if(col[x] == 0) a[i]++;
            else b[i]++;
        }
        if(a[i] > b[i]) std::swap(a[i],b[i]),chg[i] = 1;
        sm += a[i];
    }
    if(sm > n2){
        puts("NO");
    //            if(exexex)puts("2");
        return 0;
    }
    f[0][0] = 1;f[1][b[1]-a[1]] = f[1][0] = 1;
    FOR(i,2,tot){
        int w = b[i]-a[i];
        f[i][0] = 1;
        f[i][w] = 1;
        FOR(j,w,n){
            f[i][j] |= f[i-1][j-w];
        }
        FOR(j,0,n) f[i][j] |= f[i-1][j];
    }
    if(!f[tot][n2-sm]){
        puts("NO");
        return 0;
    }
    int now = n2-sm;
    ROF(i,tot,1){
        int w = b[i]-a[i];
        if(now-w >= 0 && f[i-1][now-w]){
            now -= w;
            use[i] = 1;
        }
        else if(f[i-1][now]){
            use[i] = 0;
        }
        else assert(0);
    }
    FOR(i,1,tot){
        for(auto x:G[i]){
            if(use[i]){
                if(chg[i]){
                    if(col[x] == 0) ans[x] = 2;
                }
                else if(col[x] == 1) ans[x] = 2;
            }
            else{
                if(chg[i]){
                    if(col[x] == 1) ans[x] = 2;
                }
                else if(col[x] == 0) ans[x] = 2;
            }
        }
    }
    int ttt = n1;
    FOR(i,1,n){
        if(ans[i]) continue;
        if(ttt) ans[i] = 1,ttt--;
        else ans[i] = 3;
    }
    puts("YES");
    FOR(i,1,n) printf("%d",ans[i]);puts("");
    return 0;
}