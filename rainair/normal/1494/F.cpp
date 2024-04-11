#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],bk[MAXN],cnt=1,n,m;
int deg[MAXN];
std::vector<int> S;
bool vis[MAXN],chk[MAXN];

inline void add(int u,int v){
    ++deg[u];++deg[v];
    e[++cnt] = (Edge){v,0,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
}

inline void dfs(int v){
	for(int &i = head[v];i;i = e[i].nxt){
		if(e[i].w) continue;
		e[i].w = e[i^1].w = 1;
		int t = i;dfs(e[i].to);
		S.pb(t);
	}
}

inline void get(int v){
    S.clear();
    int cnt = 0;
    FOR(i,1,n) if(deg[i]&1) ++cnt;
    if(cnt > 2 || (cnt == 2 && !(deg[v]&1))){
        FOR(i,1,n) head[i] = bk[i];
        FOR(i,1,::cnt) e[i].w = 0;
        return;
    }
    int p = v;
    if(cnt == 2){
        FOR(i,1,n) if(i != v && deg[i]&1) p = i;
    }
    dfs(p);std::reverse(all(S));
    FOR(i,1,n) head[i] = bk[i];
    FOR(i,1,::cnt) e[i].w = 0;
}

inline void print(std::vector<int> pat,std::vector<int> vec,int ed){
    std::vector<int> ans;
    if(!pat.empty()){
        ans.pb(e[pat[0]^1].to);
        for(auto x:pat) ans.pb(e[x].to);
    }
    else ans.pb(ed);
    ans.pb(-1);
    for(auto x:vec) ans.pb(x),ans.pb(ed);
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d ",x);puts("");
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    FOR(i,1,n) bk[i] = head[i];
    int odd = 0;
    FOR(i,1,n) odd += (deg[i]&1);
    if(odd <= 2){
        int v = 1;
        if(odd == 2){
            FOR(i,1,n) if(deg[i]&1) add(i,n+1);
            v = n+1;
        }
        dfs(v);std::reverse(all(S));
        printf("%d\n",m+1);
        if(v <= n) printf("%d ",v);
        for(auto x:S){
            v = e[x].to;
            if(v <= n) printf("%d ",v);
        }
        puts("");
        return 0;
    }
    FOR(v,1,n){
        std::vector<int> vec;
        for(int i = head[v];i;i = e[i].nxt){
            if(deg[e[i].to]&1) vec.pb(e[i].to),--deg[v],--deg[e[i].to],e[i].w = e[i^1].w = 1;
        }
        get(v);
        for(auto x:vec) ++deg[v],++deg[x];
        if(SZ(S)+SZ(vec) == m){
            print(S,vec,v);
            return 0;
        }
        FOR(t,0,SZ(vec)-1){
            for(int i = head[v];i;i = e[i].nxt) if(e[i].to != vec[t] && (deg[e[i].to]&1)) e[i].w = e[i^1].w = 1,--deg[v],--deg[e[i].to];
            get(v);
            for(auto x:vec) if(x != vec[t]) ++deg[v],++deg[x];
            if(SZ(S)+SZ(vec) == m+1){
                vec.erase(vec.begin()+t);
                print(S,vec,v);
                return 0;
            }
        }
    }
    puts("0");
    return 0;
}