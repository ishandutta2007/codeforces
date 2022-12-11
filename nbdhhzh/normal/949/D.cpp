#include<bits/stdc++.h>
using namespace std;
long long n,d,a[100010],i,ans,b;
int main(){
	scanf("%d%d%d",&n,&d,&b);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=n+1>>1;i++)
		ans=max(ans,max(i-a[min(n,1ll*i*(d+1))]/b,i-(a[n]-a[max(0ll,n-1ll*i*(d+1))])/b));
	printf("%d\n",ans);
}