#include <stdio.h>
#include <algorithm>
#define MN 300000
typedef long long LL;
int n,a[MN+5];
LL ans=0,tot=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	for(int i=n,j=n;i>=1;i--){
		j=std::min(j,i);
		while(a[i]>=2){
			while((j>0)&&(!(a[j]&1))) j--;
			if(j==0) break;
			--a[j]; a[i]-=2;
			tot-=3,ans++;
		}
		if(j==0) break;
		tot-=a[i];
	}
	ans+=tot/3;
	printf("%lld\n",ans);
}