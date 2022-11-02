#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#define P std::pair<LL,LL>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

inline char nc(){
    #define SIZE 1000000
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
}

inline void read(int &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}


inline void read(LL &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

const int MAXN = 1000+5;
const int MAXM = 10000+5;

struct Edge{
    int to;LL w;int nxt,id;
}e[MAXM<<1];
int head[MAXN],cnt;
int eu[MAXM<<1],ev[MAXM<<1];LL ew[MAXM<<1];
bool emp[MAXM<<1];
LL dis1[MAXN],dis2[MAXN];
int n,m,s,t;LL l;

inline void add(int id,int u,int v,LL w){
    e[++cnt] = (Edge){v,w,head[u],id};head[u] = cnt;
}

inline void dij(int type,LL dis[],int s){
    std::priority_queue<P,std::vector<P>,std::greater<P> > q;
    FOR(i,1,n) dis[i] = 1e18;
    q.push(MP(dis[s] = 0,s));
    while(!q.empty()){
        P vv = q.top();q.pop();
        if(vv.fi != dis[vv.se]) continue;
//        if(used[v]) continue;
  //      used[v] = true;
        int v = vv.se;
        for(int i = head[v];i;i = e[i].nxt){
            LL w = e[i].w;int id = e[i].id;
            if(emp[id] && type){
                w = ew[id] = std::max(ew[id],l-dis[v]-dis1[e[i].to]);
            }
            if(dis[e[i].to] > dis[v] + w){
                dis[e[i].to] = dis[v] + w;
                q.push(MP(dis[e[i].to],e[i].to));
            }
        }
    }
}

signed main(){
    read(n);read(m);read(l);read(s);read(t);++s;++t;
    FOR(i,1,m){
        int u,v;LL w;read(u);read(v);read(w);++u,++v;
        eu[i] = u;ev[i] = v;ew[i] = w;emp[i] = !w;if(!w) w = ew[i] = 1;
        add(i,u,v,w);add(i,v,u,w);
    }
    dij(0,dis1,t);dij(1,dis2,s);
    if(dis2[t] != l){
        puts("NO");
        return 0;
    }
    puts("YES");
    FOR(i,1,m) printf("%d %d %lld\n",eu[i]-1,ev[i]-1,ew[i]);
    return 0;
}