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

const int MAXN = 32000 + 5;
bool p[MAXN];int prime[MAXN],cnt;

inline void prework(){
	FOR(i,2,MAXN-1){
		if(!p[i]) prime[++cnt] = i;
		for(int j = 1;j <= cnt && 1ll*i*prime[j] < MAXN;++j){
			p[i*prime[j]] = 1;
			if(!(i%prime[j])) break;
		}
	}
}

inline int fac(int x){
	int ans = 0;
	FOR(i,1,cnt){
		int p = prime[i];
		if(p > x) break;
		while(!(x%p)) ++ans,x /= p;
	}
	if(x > 1) ++ans;
	return ans;
}

inline void Solve(){
	LL a,b,k;scanf("%lld%lld%lld",&a,&b,&k);
	if(a > b) std::swap(a,b);// a <= b
	if(k == 1){
		if(b%a == 0 && b != a){
			puts("Yes");
		}
		else{
			puts("No");
		}
		return;
	}
	int res = fac(a)+fac(b);
	if(k <= res){
		puts("Yes");
		return;
	}
	puts("No");
}

int main(){
	prework();
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}