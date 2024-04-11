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

int n;LL c,d;
int a[MAXN],b[MAXN];
int suf[MAXN],lst[2];

int main(){
	scanf("%d%lld%lld",&n,&c,&d);
	FOR(i,1,n){
		char str[23];scanf("%d%s",a+i,str+1);
		b[i] = (str[1]=='P');
	}
	scanf("%d",a+n+1);
	LL ans = 1ll*d*n;
	lst[0] = lst[1] = n+1;
	ROF(i,n,1){
		suf[i] = lst[!b[i]];
		lst[b[i]] = i;
	}
	LL sm = 0;
	ROF(i,n,1){
		if(i+1 <= n){
			if(b[i+1] == b[i]) sm += std::min(d,c*(a[suf[i+1]]-a[i+1]));
			else sm += c*(a[suf[i+1]]-a[i+1]);
		}
		ans = std::min(ans,sm+(i-1)*d+c*(a[suf[i]]-a[i]));
	}
	printf("%lld\n",ans);
	return 0;
}