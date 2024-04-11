#include<bits/stdc++.h>

#define fi first
#define se second
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

inline LL gcd(LL x,LL y){
	return !y ? x : gcd(y,x%y);
}

inline LL lcm(LL x,LL y){
	return x*y/gcd(x,y);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL x,y,k;scanf("%lld%lld%lld",&x,&y,&k);
		if(x > y) std::swap(x,y);
		LL g = gcd(x,y);
		LL ans = 1+(y-1-g)/x;
		puts(ans < k ? "OBEY" : "REBEL");
	}
	return 0;
}