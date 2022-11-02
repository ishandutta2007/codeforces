/*
 * Author: RainAir
 * Time: 2019-10-08 19:07:45
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
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 13+2;
const int MAXM = 1000+5;
#define int LL
int f[MAXN][(1<<MAXN)+3];
int n,m,q;
int pc[(1<<MAXN)+3];
int a[MAXM],b[MAXM],c[MAXM];
int G[MAXN][MAXN];
struct Edge{
    int u,v;
    Edge(int u=0,int v=0) : u(u),v(v) {}
}e[MAXN];
bool in(int x, int s){ return s & (1 << x); }
inline int dfs(int v,int S){
    int &ans = f[v][S];
    if(pc[S] == 1) return ans = (S == (1<<v));
    if(ans != -1) return ans;
    ans = 0;S ^= (1<<v);
//    int TT = ((1<<n)-1)^(1<<0);
    int son = 0;
    FOR(i,0,n-1) if((1<<i)&S) son = i; // 
    for(int T = S;T;T = (T-1)&S){
        if(!((1<<son)&T)) continue;
        // lca
        //  lca 
        //  lca 
        bool flag = true;
        FOR(i,1,q){
            if(c[i] == v && (T&(1<<a[i])) && (T&(1<<b[i]))){
                flag = 0;
                break;
            }
        }
        if(!flag) continue;
        FOR(i,1,q){
            if(T&(1<<c[i]) && !((T&(1<<a[i])) && (T&(1<<b[i])))){
                flag = 0;
                break;
            }
        }
        if(!flag) continue;
        // edge
        // 
        // 
        FOR(i,1,m){
            if(e[i].u != v && e[i].v != v && ((bool)(T&(1<<e[i].u))) ^ ((bool)(T&(1<<e[i].v)))){
                flag = 0;
                break;
            }
        }
        if(!flag) continue;        
        int cnt = 0,x = 0;
        FOR(i,1,m){
            if(e[i].u == v || e[i].v == v){
                int t = e[i].u == v ? e[i].v : e[i].u;
                if(T&(1<<t)) cnt++,x = t;
                if(cnt > 1){
                    flag = 0;
                    break;
                }
            }
        }
        if(!flag) continue;
//            if(v == 1 && S == 4) DEBUG(T),DEBUG(cnt),DEBUG(x);
        if(cnt == 1) ans += dfs(x,T)*dfs(v,(S^T)^(1<<v));
        else{
            FOR(x,0,n-1){
                if(T&(1<<x))
                    ans += dfs(x,T)*dfs(v,(S^T)^(1<<v));
                  //  if(v == 0 && T == 6) DEBUG(dfs(x,T)),DEBUG(x);
            }
        }
    }
    return ans;
}

signed main(){
    scanf("%lld%lld%lld",&n,&m,&q);CLR(f,-1);
    FOR(i,1,(1<<n)-1) pc[i] = pc[i>>1]+(i&1);
    FOR(i,1,m){
        int u,v;scanf("%lld%lld",&u,&v);--u;--v;
        G[u][v] = G[v][u] = 1;
        e[i] = Edge(u,v);
    }
    FOR(i,1,q) scanf("%lld%lld%lld",a+i,b+i,c+i),--a[i],--b[i],--c[i];
    FOR(i,0,n-1) f[i][(1<<i)] = 1;
    printf("%lld\n",dfs(0,(1<<n)-1));
    return 0;
}