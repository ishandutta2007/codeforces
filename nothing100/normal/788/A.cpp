#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,k,a[100010],min1,min2,sum1,sum2,tmp,ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld",&a[i]);
	ans=sum1=abs(a[1]-a[0]);
	tmp=1;
	for (int i=1;i<n-1;i++){
		sum1+=abs(a[i+1]-a[i])*tmp*-1;
		sum2+=abs(a[i+1]-a[i])*tmp;
		ans=max(ans,sum1-min1);
		ans=max(ans,sum2-min2);
		min1=min(min1,sum1);
		min2=min(min2,sum2);
		tmp=-tmp;
	}
	printf("%lld\n",ans);
}