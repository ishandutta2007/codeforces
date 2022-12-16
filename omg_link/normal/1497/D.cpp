#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 5000
typedef long long LL;

int n,t[MN+5],s[MN+5];
LL f[MN+5],g[MN+5];

void solve(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	LL ans = 0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++)
			if(t[i]!=t[j])
				g[i] = std::max(g[i],std::max(g[j],f[j])+std::abs(s[i]-s[j]));
		LL best = 0;
		for(int j=i-1;j>=1;j--){
			if(t[i]==t[j]) continue;
			LL tfj = std::max(f[j],g[j]);
			f[j] = std::max(f[j],best+std::abs(s[i]-s[j]));
			best = std::max(best,tfj+std::abs(s[i]-s[j]));
		}
	}
	for(int i=0;i<=n;i++)
		ans = std::max(ans,std::max(f[i],g[i]));
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}