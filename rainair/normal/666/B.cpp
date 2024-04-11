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

const int MAXN = 3000+5;

struct Edge{
	int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
	e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

int dis[MAXN][MAXN],n,m;

inline void gao(int dis[],int S){
	std::queue<int> q;q.push(S);
	FOR(i,1,n) dis[i] = 1e9;dis[S] = 0;
	while(!q.empty()){
		int v = q.front();q.pop();
		for(int i = head[v];i;i = e[i].nxt){
			if(dis[e[i].to] != 1e9) continue;
			dis[e[i].to] = dis[v]+1;q.push(e[i].to);
		}
	}
}

std::vector<P> pre[MAXN],suf[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);add(u,v);
	}
	FOR(i,1,n) gao(dis[i],i);
	FOR(i,1,n){
		FOR(j,1,n){
			if(i == j || dis[i][j] == 1e9) continue;
			pre[j].pb(MP(dis[i][j],i));
			suf[i].pb(MP(dis[i][j],j));
		}
	}
	FOR(i,1,n) std::sort(all(pre[i])),std::sort(all(suf[i]));
	FOR(i,1,n) std::reverse(all(pre[i])),std::reverse(all(suf[i]));
	FOR(i,1,n){
		if(pre[i].size() > 4) pre[i].resize(4);
		if(suf[i].size() > 4) suf[i].resize(4);
	}
	int mx = 0;
	int aa=-1,bb=-1,cc=-1,dd=-1;
	FOR(b,1,n){
		FOR(c,1,n){
			if(dis[b][c] == 1e9) continue;
			if(b == c) continue;
			for(auto x:pre[b]){
				int a = x.se;
				if(a == b || a == c) continue;
				for(auto y:suf[c]){
					int d = y.se;
					if(d == a || d == b || d == c) continue;
					if(mx < dis[a][b]+dis[b][c]+dis[c][d]){
						mx = dis[a][b]+dis[b][c]+dis[c][d];
						aa = a;bb = b;cc = c;dd = d;
					}
				}
			}
		}
	}
	// DEBUG(dis[2][1]+dis[1][8]+dis[8][7]);
	// DEBUG(dis[1][8]+dis[8][7]+dis[7][6]);
	printf("%d %d %d %d\n",aa,bb,cc,dd);
	return 0;
}