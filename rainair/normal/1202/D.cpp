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

inline LL C(int n){
	return 1ll*n*(n-1)/2;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		std::vector<int> S;
		LL k;scanf("%lld",&k);
		int x1 = 2;
		while(C(x1+1) <= k) ++x1;
		k -= C(x1);
		while(k){
			int x2 = 1;
			while(C(x2+1) <= k) ++x2;
			k -= C(x2);
			S.pb(x2);
		}
		putchar('1');
		FOR(i,1,x1){
			putchar('3');
			while(!S.empty() && i == S.back()) putchar('7'),S.pop_back();
		}
		putchar('7');puts("");
	}
	return 0;
}