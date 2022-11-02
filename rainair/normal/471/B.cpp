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

const int MAXN = 2000+5;
int n;
P a[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i].fi),a[i].se = i;
	std::sort(a+1,a+n+1);
	int c = 0;
	FOR(i,2,n){
		if(a[i].fi == a[i-1].fi) ++c;
	}
	if(c <= 1){
		puts("NO");
		return 0;
	}	puts("YES");
	FOR(i,1,n) printf("%d ",a[i].se);puts("");
	FOR(i,2,n){
		if(a[i].fi == a[i-1].fi){
			std::swap(a[i],a[i-1]);
			break;
		}
	}
	FOR(i,1,n) printf("%d ",a[i].se);puts("");
	ROF(i,n,2){
		if(a[i].fi == a[i-1].fi){
			std::swap(a[i],a[i-1]);
			break;
		}
	}
	FOR(i,1,n) printf("%d ",a[i].se);puts("");
	return 0;
}