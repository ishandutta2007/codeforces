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

const int MAXN = 2e6 + 5;
int n;
int a[MAXN],b[MAXN];

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt=1;
int du[MAXN];
inline void add(int u,int v){
    e[++cnt] = (Edge){v,0,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
    du[u]++;du[v]++;
}
std::vector<int> S;
bool vis[MAXN];
inline void dfs(int v){vis[v]  =1;
	for(int &i = head[v];i;i = e[i].nxt){
		if(e[i].w) continue;
		e[i].w = 1;
		e[i^1].w = 1;
		int t = i;dfs(e[i].to);
		S.pb((t&1?-1:1)*(int)(t/2));
	}
}
bool used[MAXN];
inline bool chk(int k){
    int N = (1<<k);int u = N-1;S.clear();
    FOR(i,0,N+1) head[i] = vis[i] = used[i] = du[i] = 0;cnt = 1;
    FOR(i,1,n){
        add((a[i]&u)+1,(b[i]&u)+1);
        used[(a[i]&u)+1] = used[(b[i]&u)+1] = 1;
    }
    int cnt = 0;
    FOR(i,1,N) if(du[i]&1) return 0;
    FOR(i,1,N){
        if(!used[i]) continue;
        if(!vis[i]) dfs(i),cnt++;
    }
    if(cnt > 1) return 0;
    return 1;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",a+i,b+i);
    ROF(i,20,0){
        if(chk(i)){
            printf("%d\n",i);std::reverse(all(S));
            int las = 1e9;
            for(auto x:S){
                if(x > 0) printf("%d %d ",x*2-1,x*2);
                else x = -x,printf("%d %d ",x*2,x*2-1);
            }
            puts("");
            return 0;
        }
    }
    return 0;
}