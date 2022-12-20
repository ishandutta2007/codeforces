#include <stdio.h>
#include <algorithm>
#define MN 100000

int n;
int a[MN+5],b[MN+5],c[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=2;i<=n;i++)
		if(a[i]>b[i])
			std::swap(a[i],b[i]);
	long long ans = 0;
	long long tans = b[2]-a[2];
	for(int i=2;i<=n-1;i++){
		tans += 2;
		ans = std::max(ans,tans+c[i]-1);
		if(a[i+1]==b[i+1]){
			tans = 0;
		}else{
			tans = std::max((long long)b[i+1]-a[i+1],tans+a[i+1]-1+c[i]-b[i+1]);
		}
	}
	tans += 2;
	ans = std::max(ans,tans+c[n]-1);
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}