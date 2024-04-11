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

const int MAXN  = 1e5 + 5;
P a[MAXN];
int n;
int mn[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	std::sort(a+1,a+n+1);mn[n+1] = 1e9;
	ROF(i,n,1) mn[i] = std::min(mn[i+1],a[i].se);
	FOR(i,1,n-1){
		if(a[i].se > mn[i+1]){
			puts("Happy Alex");return 0;
			}
	}
	puts("Poor Alex");
	return 0;
}