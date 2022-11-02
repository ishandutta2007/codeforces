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
#define int LL
const int MAXN = 1e5 + 5;
int k,n,m;
int a[MAXN];
int t[MAXN],p[MAXN],b[MAXN];
std::vector<P> v[MAXN][4];
P id[MAXN];

inline bool cmp(int x,int y){
	return t[x]<t[y];
}

signed main(){
	scanf("%lld%lld%lld",&k,&n,&m);
	FOR(i,1,k) scanf("%lld",a+i);
	FOR(i,1,n){
		scanf("%lld%lld%lld",t+i,p+i,b+i);
		v[p[i]][t[i]].pb(MP(b[i],i));
	}
	FOR(i,1,k) FOR(j,1,3) std::sort(all(v[i][j])),std::reverse(all(v[i][j]));
	FOR(i,1,k){
		if(v[i][1].empty()) continue;
		P mx = v[i][1][0];v[i][1].clear();
		v[i][1].pb(mx);
	}
	std::vector<std::pair<long double,int> > S;
	FOR(i,1,k){
		if(!v[i][1].empty()){
			if(a[i] < v[i][1][0].fi) v[i][2].pb(MP(v[i][1][0].fi-a[i],v[i][1][0].se));
		}
		std::sort(all(v[i][2]));std::reverse(all(v[i][2]));
		for(auto x:v[i][2]) S.pb(MP((long double)(a[i]+x.fi)/a[i],x.se)),a[i] += x.fi;
		for(auto x:v[i][3]) S.pb(MP(x.fi,x.se));
	}
	std::vector<int> ans;std::sort(all(S));std::reverse(all(S));
	FOR(i,0,std::min((int)S.size()-1,m-1)) ans.pb(S[i].se);
	std::sort(all(ans),cmp);
	printf("%lld\n",(int)ans.size());
	for(auto x:ans) printf("%lld ",x);puts("");
	return 0;
}
/*
570
*/