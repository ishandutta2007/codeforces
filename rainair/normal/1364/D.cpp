/*
 * Author: RainAir
 * Time: 2020-06-14 14:55:57
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

const int MAXN = 5e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int n,m,k;
bool vis[MAXN];
int mn,mnu,mnv;
int dep[MAXN];
int fa[MAXN];

inline void dfs(int v,int fa=0){
    vis[v] = 1;dep[v] = dep[fa]+1;::fa[v] = fa;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        if(vis[e[i].to] && dep[v] > dep[e[i].to]){
            if(mn > dep[v]-dep[e[i].to]+1){
                mn = dep[v]-dep[e[i].to]+1;
                mnu = v;mnv = e[i].to;
            }
        }
        if(!vis[e[i].to]) dfs(e[i].to,v);
    }
}
int col[MAXN];
int main(){
    scanf("%d%d%d",&n,&m,&k);mn = 1e9;
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1);
    if(mn == 1e9){
        std::queue<int> q;
        q.push(1);col[1] = 1;
        while(!q.empty()){
            int v = q.front();q.pop();
            for(int i = head[v];i;i = e[i].nxt){
                if(col[e[i].to]) continue;
                col[e[i].to] = 3-col[v];
                q.push(e[i].to);
            }
        }
        std::vector<int> t1,t2;
        FOR(i,1,n){
            if(col[i] == 1) t1.pb(i);
            else t2.pb(i);
        }
        puts("1");
        if(t1.size() < t2.size()) std::swap(t1,t2);
        FOR(i,1,(k+1)/2) printf("%d ",t1[i-1]);puts("");
        return 0;
    }
    else if(mn <= k){
        int v = mnu;std::vector<int> ans;
        while(v != mnv){
            ans.pb(v);
            v = fa[v];
        }
        ans.pb(mnv);
        puts("2");
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);puts("");
        return 0;
    }
    else{
        int v = mnu;std::vector<int> ans;
        while(v != mnv){
            ans.pb(v);
            v = fa[v];
        }
        ans.pb(mnv);
        puts("1");
        FOR(i,1,(k+1)/2) printf("%d ",ans[(i-1)*2]);puts("");
        return 0;
    }
    return 0;
}