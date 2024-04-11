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

const int MAXN = 2e5 +5;
int k,n,a[MAXN];
char str[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",a+i);
	scanf("%s",str+1);LL ans = 0;
	for(int l = 1,r = 1;l <= n;l = r+1){
		r = l;while(r <= n && str[r+1] == str[l]) ++r;
		std::vector<int> S;FOR(i,l,r) S.pb(a[i]);
		std::sort(all(S));std::reverse(all(S));
		FOR(i,0,std::min(k,(int)S.size())-1) ans += S[i];
	}
	printf("%lld\n",ans);
	return 0;
}