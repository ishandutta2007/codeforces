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

const int MAXN = 2e5 + 5;
int n,a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		LL sm = 0;
		FOR(i,1,n) scanf("%d",a+i),sm += a[i];
		if(sm%n){
			puts("-1");
			continue;
		}
		LL lim = sm/n;int ans = 0;
		FOR(i,1,n) ans += a[i]>lim;
		printf("%d\n",ans);
	}
	return 0;
}