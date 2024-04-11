#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define Re register
#define LL long long
//#define U unsigned
#define P std::pair<LL,LL>
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

#define int LL
const int MAXN = 150000 + 100;
int f[MAXN],n;
P dis[MAXN];
int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}

int a[MAXN][3],cnt[MAXN];

void U(int x,int y){dis[y].fi = dis[x].se;f[x] = y;}
void dfs(int u,int fa){if(!u) return;printf("%I64d ",u);if(a[u][1] == fa) dfs(a[u][2],u);else dfs(a[u][1],u);}
signed main(){
	scanf("%I64d",&n);
	FOR(i,1,n) f[i] = dis[i].fi = dis[i].se = i;
	FOR(i,1,n-1){
        int x,y;scanf("%I64d%I64d",&x,&y);x=find(x);y = find(y);int k1 = dis[x].fi,k2 = dis[y].fi;a[k1][++cnt[k1]] = k2;a[k2][++cnt[k2]] = k1;U(x,y);
	}
	int u = 0;
    FOR(i,1,n) if(cnt[i] == 1){u = i;break;}
    dfs(u,0);
	return 0;
}