#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int a[MAXN];LL sm[MAXN];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",a+i);
	std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
	FOR(i,1,n) sm[i] = sm[i-1]+a[i];
	FOR(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		printf("%lld\n",sm[x]-sm[x-y]);
	}
	return 0;
}