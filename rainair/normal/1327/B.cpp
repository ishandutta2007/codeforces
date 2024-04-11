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

const int MAXN = 1e5 + 5;
std::vector<int> v[MAXN];
int n;
bool vis[MAXN];

inline void Solve(){
	scanf("%d",&n);FOR(i,1,n) vis[i] = 0;
	FOR(i,1,n){
		int k;scanf("%d",&k);v[i].clear();
		while(k--){
			int x;scanf("%d",&x);v[i].pb(x);
		}
	}
	int p = -1;
	FOR(i,1,n){
		bool flag = 1;
		for(auto x:v[i]){
			if(vis[x]) continue;
			vis[x] = 1;flag = 0;break;
		}
		if(flag){
			p = i;
		}
	}
	if(p == -1) puts("OPTIMAL");
	else{
		puts("IMPROVE");
		int q = -1;
		FOR(i,1,n) if(!vis[i]) q = i;
		printf("%d %d\n",p,q);
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}