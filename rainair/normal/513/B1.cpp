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

const int MAXN = 50+5;
int a[MAXN],n;LL m;

int main(){
	scanf("%d%lld",&n,&m);
	int fi = 0,se = n+1;
	FOR(i,1,n-1){
		int r = n-i-1;
		if(m > (1ll<<r)){
			m -= (1ll<<r);
			a[--se] = i;
		}
		else{
			a[++fi] = i;
		}
	}
	FOR(i,1,n) if(!a[i]) a[i] = n;
	FOR(i,1,n) printf("%d ",a[i]);puts("");
	return 0;
}