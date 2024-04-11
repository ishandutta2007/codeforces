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

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2000+5;
int n,m,cnt,f[MAXN],vis[MAXN],ru[MAXN],dis[MAXN],bel[MAXN];
char s[MAXN][MAXN];
std::vector<int> G[MAXN],V[MAXN];

int find(int x){return f[x] == x ? x : f[x] = find(f[x]);}

int main() {
	scanf("%d%d",&n,&m);
	FOR(i,1,n+m) f[i] = i;
	FOR(i,1,n){
		scanf("%s",s[i]+1);
		FOR(j,1,m) if (s[i][j] == '=') f[find(i)] = find(j + n);
	}
	FOR(i,1,n+m){
		int x = find(i);
		if (!vis[x]) vis[x] = ++cnt;
		bel[i] = vis[x];
		V[vis[x]].push_back(i);
	}
	FOR(i,1,n){
		FOR(j,1,m){
			if(s[i][j]=='<') G[bel[i]].push_back(bel[n + j]),ru[bel[n + j]]++;
            if(s[i][j]=='>') G[bel[n + j]].push_back(bel[i]),ru[bel[i]]++;
		}
	}
	std::queue<int> q;
	int ans = 0;
	FOR(i,1,cnt) if(!ru[i]) q.push(i),ans++,dis[i] = 1;
	while(!q.empty()){
		int u = q.front();
		for(int v: G[u]){
			dis[v] = std::max(dis[v], dis[u] + 1);if(!--ru[v]) ans++,q.push(v);
		}
		q.pop();
	}
	if (ans != cnt){
        puts("No");
        return 0;
    }
	puts("Yes");
	FOR(i,1,n) printf("%d ",dis[bel[i]]);puts("");
	FOR(i,1,m) printf("%d ",dis[bel[i + n]]);puts("");
	return 0;
}