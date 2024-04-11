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

const int MAXN = 2e5 + 5;
int a[MAXN],n,k;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		FOR(i,1,n) scanf("%d",a+i);
		std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
		LL ans = a[1];int t = 0;
		FOR(i,2,n){
			if(t == k) break;
			ans += a[i];
			++t;
		}
		printf("%lld\n",ans);
	}
	return 0;
}