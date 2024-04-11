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

const int MAXN = 1e6 + 5;
int n,c;
std::vector<int> G[MAXN][2];// 0=L

inline void stop(){
	puts("IMPOSSIBLE");exit(0);
}

int ch[MAXN][2];

inline void print(int v){
	if(!v) return;
	print(ch[v][0]);
	printf("%d ",v);
	print(ch[v][1]);
}

int tot = 1;

inline void work(int v,int t){ // t
	FOR(i,0,1) std::sort(all(G[v][i]));
	if(!G[v][0].empty()){
		int n = ++tot;
		ch[v][0] = n;
		work(n,G[v][0].back());
	}
	if(!G[v][1].empty() && tot >= G[v][1].front()) stop();
	if(!G[v][1].empty()) t = std::max(t,G[v][1].back());
	if(tot < t){
		int n = ++tot;
		ch[v][1] = n;
		work(n,t);
	}
}

int main(){
	scanf("%d%d",&n,&c);
	FOR(i,1,c){
		int u,v;char str[23];scanf("%d%d%s",&u,&v,str+1);
		if(u >= v) stop();
		G[u][str[1]=='R'].pb(v);
	}
	work(1,n);
	print(1);
	return 0;
}