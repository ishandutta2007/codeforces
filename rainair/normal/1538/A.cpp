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

const int MAXN = 100 + 5;
int n,a[MAXN];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		FOR(i,1,n) scanf("%d",a+i);
		int p1 = std::min_element(a+1,a+n+1)-a,p2 = std::max_element(a+1,a+n+1)-a;
		if(p1 > p2) std::swap(p1,p2);
		printf("%d\n",std::min({p2,n-p1+1,p1+n-p2+1}));
	}
	return 0;
}