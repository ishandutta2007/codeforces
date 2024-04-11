#include <stdio.h>
#include <algorithm>
#define MN 100
typedef long long LL;

int n,k;
LL a[MN+5];

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	LL cur = a[1];
	LL ans = 0;
	for(int i=2;i<=n;i++){
		LL v = std::max(0ll,(a[i]*100+k-1)/k-cur);
		cur += v;
		ans += v;
		cur += a[i];
	}
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}