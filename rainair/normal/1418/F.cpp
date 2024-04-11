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

const int MAXN = 2e5 + 5;
std::vector<int> G[MAXN];

inline void prework(){
	FOR(i,1,200000) for(int j = i;j <= 200000;j += i) G[j].pb(i);
}

LL L,R;
int n,m;
std::set<P> S;

int main(){
	prework();
	scanf("%d%d%lld%lld",&n,&m,&L,&R);
	int nowl=m+1,nowr=m;
	FOR(x,1,n){
		LL l=L/x,r=R/x;
		if(1ll*x*l < L) ++l;
		r = std::min(r,(LL)m);
		if(l > r){
			puts("-1");
			continue;
		}
		while(l < nowl){
			nowl--;
			for(auto x:G[nowl]) S.insert(MP(x,nowl));
		}
		while(nowr > r){
			for(auto x:G[nowr]) S.erase(MP(x,nowr));
			nowr--;
		}
		bool flag = 0;
		for(auto a:G[x]){
			auto it = S.upper_bound(MP(a,1e9));
			if(it == S.end()) break;
			int b = it->fi,y = it->se;
			if(1ll*(x/a)*b <= n){
				flag = 1;
				printf("%d %d %d %d\n",x,y,x/a*b,y/b*a);
				break;
			}
		}
		if(!flag){
			puts("-1");
		}
	}
	return 0;
}