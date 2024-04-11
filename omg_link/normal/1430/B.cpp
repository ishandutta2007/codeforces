#include <stdio.h>
#include <algorithm>
#define MN 200000
typedef long long LL;

int n,k,a[MN+5];

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n,std::greater<int>());
	LL ans = 0;
	for(int i=1;i<=k+1;i++)
		ans += a[i];
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}