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


inline void Solve(){
	int l,r;scanf("%d%d",&l,&r);
	int len = r-l;
	LL ans = r==1e9;int pw = 1;
	FOR(i,0,8){
		LL rem = len-(pw-l%pw-1);
		if(rem > 0){
			++ans;--rem;
			ans += rem/pw;
		}
		pw *= 10;
	}
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}