#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 600000

LL t,n,m,a[N],f[N],g[N],ans;
map<LL,LL> mp;

LL rd(){return (LL)rand()*rand();}

int main(){
	srand((unsigned long long)new char+time(NULL));
	scanf("%lld",&t);
	while (t--){
		scanf("%lld%lld",&n,&m);
		for (LL i=1;i<=n;++i) scanf("%lld",a+i);
		for (LL i=1;i<=n;++i){
			f[i]=rd()<<30|rd();
			g[i]=0;
		}
		for (LL i=1;i<=m;++i){
			LL x,y; scanf("%lld%lld",&x,&y);
			g[y]^=f[x];
		}
		mp.clear();
		for (LL i=1;i<=n;++i)
			if (g[i]!=0) mp[g[i]]+=a[i];
		ans=0;
		for (auto i:mp) ans=__gcd(ans,i.second);
		printf("%lld\n",ans);
	}
	
	return 0;
}