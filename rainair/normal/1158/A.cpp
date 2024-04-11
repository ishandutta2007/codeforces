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
int a[MAXN],b[MAXN];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",a+i);std::sort(a+1,a+n+1);
	FOR(i,1,m) scanf("%d",b+i);std::sort(b+1,b+m+1);
	if(a[n] > b[1]){
		puts("-1");return 0;
	}
	if(a[n] == b[1]){
		LL ans = 0;
		FOR(i,1,m) ans += b[i];
		FOR(i,1,n-1) ans += 1ll*m*a[i];
		printf("%lld\n",ans);
		return 0;
	}
	LL ans = 0;
	FOR(i,1,m) ans += b[i]; 
	ans += a[n];ans -= a[n-1];
	FOR(i,1,n-1) ans += 1ll*a[i]*m;
	printf("%lld\n",ans);
	return 0;
}