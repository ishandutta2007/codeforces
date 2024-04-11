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

const int MAXN = 5e5 + 5;
int a[MAXN],n;
std::vector<int> v1,v2;

inline void Solve(){
	scanf("%d",&n);v1.clear();v2.clear();
	FOR(i,1,n){
		int x;scanf("%d",&x);
		if(x > 0) v1.pb(x);
		else v2.pb(x);
	}
	std::sort(all(v1));std::sort(all(v2));std::reverse(all(v2));
	LL ans = -1e18;
	FOR(i,0,5){
		if(v1.size() < i) continue;
		if(v2.size() < 5-i) continue;
		LL gx = 1;
		if((5-i)&1){
			FOR(j,0,i-1) gx *= v1[j];
			FOR(j,0,5-i-1) gx *= v2[j];
		}
		else{
			FOR(j,0,i-1) gx *= v1[(int)v1.size()-j-1];
			FOR(j,0,5-i-1) gx *= v2[(int)v2.size()-j-1];
		}
		ans = std::max(ans,gx);
	}
	// DEBUG(ans);
	// exit(0);
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}