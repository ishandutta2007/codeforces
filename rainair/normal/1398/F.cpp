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
int n;
char a[MAXN];
int g[MAXN];
std::vector<int> G[MAXN];
int f[MAXN];

inline int find(int x){
	if(x <= 0) return 0;
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
	scanf("%d",&n);scanf("%s",a+1);
	int dp0 = 0,dp1 = 0;
	FOR(i,1,n){
		int new_dp0 = 0,new_dp1 = 0;
		if(a[i] == '0') new_dp0 = dp0+1;
		if(a[i] == '1') new_dp1 = dp1+1;
		if(a[i] == '?') new_dp0 = dp0+1,new_dp1 = dp1+1;
		dp0 = new_dp0;dp1 = new_dp1;
		g[i] = std::max(dp0,dp1);
		G[g[i]].pb(i);
	}
//	FOR(i,1,n) DEBUG(g[i]);
	int now = 0,t = 0;
	FOR(i,1,n) f[i] = i;
	FOR(x,1,n){
		int p = find(n),ans = p?1:0;
		while(p){
			p = find(p-x);
			if(p) ans++;
		}
		printf("%d ",ans);
		for(auto v:G[x]){
			assert(find(v) == v);
			f[v] = find(v-1);
		}
	}
	puts("");
	return 0;
}