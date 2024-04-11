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
#define FOR(i,a,b) for(register int i = a;i <= b;++i)
#define ROF(i,a,b) for(register int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

inline char nc(){
    #define SIZE 300000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
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

const int MAXN = 1e4 + 5;
int N,S,T;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
//std::vector<Edge> e;
//std::vector<int> head,cur;
//int cnt = 1;
int head[MAXN],cur[MAXN],cnt=1;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
}

//std::vector<int> dep;
int dep[MAXN],qq[MAXN];
//std::vector<int> qq;
int top;

inline bool bfs(){
//    dep.assign(N+2,0);
//    cur.assign(all(head));
    memcpy(cur,head,sizeof(cur));
    CLR(dep,0);
    std::queue<int> q;q.push(T);
    qq[top = 1] = T;dep[T] = 1;
    FOR(i,1,top){
        int v = qq[i];
        for(int i = head[v];i;i = e[i].nxt){
            if(e[i^1].w > 0 && !dep[e[i].to]){
                dep[e[i].to] = dep[v] + 1;
                if(e[i].to == S) return 1;
                qq[++top] = e[i].to;
//                q.push(e[i].to);
            }
        }
    }
    return 0;
}

inline int dfs(int v,int flow=1e9){
    if(!flow) return 0;
    if(v == T) return flow;
    int res = 0;
    for(int &i = cur[v];i;i = e[i].nxt){
        if(e[i].w > 0 && dep[e[i].to] == dep[v] - 1){
            int t = dfs(e[i].to,std::min(flow,e[i].w));
            if(t > 0){
                e[i].w -= t;e[i^1].w += t;flow -= t;res += t;
                if(!flow) break;
            }
            else dep[e[i].to] = -1;
        }
    }
    return res;
}

int rr;

inline int Dinic(bool flag=0){
    int res=0,flow;
    while(bfs()) while((flow=dfs(S,flag==0?1e9:25))) res += flow;
    return res;
}

int m,k,q;

int u[MAXN],v[MAXN],w[MAXN];
//std::vector<int> u,v,w,g,h,t,ps;
//std::vector<int> ttt[11];
int g[(1<<10)+3],h[(1<<10)+3],t[233],ttt[11][MAXN<<1];

int ps[(1<<10)+3];
#define lowbit(x) ((x)&(-(x)))

inline void dfs(int S,int dep,int now){
    if(dep == k+1){g[S] = now;return;}
    dfs(S,dep+1,now);
    FOR(i,2,cnt) ttt[dep][i] = e[i].w;
    e[2*dep].w = 25;
    now += Dinic(1);
    dfs(S^(1<<(dep-1)),dep+1,now);
    e[2*dep].w = 0;
    FOR(i,2,cnt) e[i].w = ttt[dep][i];
}

int main(){
//    e.resize(2*MAXN+3);head.resize(MAXN+3);cur.resize(MAXN+4);qq.resize(MAXN);
//    u.resize(MAXN);v.resize(MAXN);w.resize(MAXN);g.resize(1048);h.resize(1048);t.resize(123);ps.resize(1048);
//    FOR(i,0,10) ttt[i].resize(MAXN*2+3);
//    int sz = sizeof(f)+3*sizeof(ps)+4*sizeof(u);
//    DEBUG(sizeof(f)/1024/1024);
    read(N);read(m);read(k);read(q);
    FOR(i,1,m) read(u[i]),read(v[i]),read(w[i]);
    S = 1;T = N;cnt = 1;
    FOR(i,1,k) add(u[i],v[i],0);
    FOR(i,k+1,m) add(u[i],v[i],w[i]);
    rr = Dinic();
    FOR(i,2,cnt) ttt[0][i] = e[i].w;
    g[(1<<k)-1] = rr;
    FOR(i,0,k-1) ps[1<<i] = i;
    dfs((1<<k)-1,1,rr);
    while(q--){
        FOR(i,1,k) read(t[i]);
        int ans = g[0];
        FOR(S,1,(1<<k)-1){
            int p = ps[lowbit(S)];
            h[S] = h[S^(1<<p)]+t[p+1];
            ans = std::min(ans,g[S]+h[S]);
        }
        printf("%d\n",ans);
    }
    return 0;
}