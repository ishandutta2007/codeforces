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
LL a[MAXN];
int n;

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",a+i);
	if(n == 1){
		printf("%d %d\n%lld\n1 1\n0\n1 1\n0\n",1,1,-a[1]);
		return 0;
	}
	printf("%d %d\n",1,n);
	FOR(i,1,n){
		printf("%lld ",1ll*((n-1)-a[i]%(n-1))*n);
		a[i] += ((n-1)-a[i]%(n-1))*n;
	}
	puts("");
	printf("%d %d\n",1,n-1);
	FOR(i,1,n-1){
		printf("%lld ",-a[i]);
	}
	puts("");
	printf("%d %d\n",n,n);
	printf("%lld\n",-a[n]);
	return 0;
}