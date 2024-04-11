#include <stdio.h>
#include <set>
#define MN 200000
typedef long long LL;
int n,a[MN+5];
LL pre[MN+5][2],suf[MN+5][2];
LL ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		pre[i][0] = pre[i-1][0];
		pre[i][1] = pre[i-1][1];
		pre[i][i&1] += a[i];
	}
	for(int i=n;i>=1;i--){
		suf[i][0] = suf[i+1][0];
		suf[i][1] = suf[i+1][1];
		suf[i][i&1] += a[i];
	}
	//1,n
	ans = pre[n][1];
	for(int i=1;i<=n-1;i++){
		ans = std::max(ans,a[i]+a[i+1]+pre[i-1][i&1]+suf[i+2][(i+1)&1]);
	}
	printf("%lld\n",ans);
}