#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k,a[100010],t[100010],sum[100010];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	int maxp=1;
	for(int i=1;i<=k;i++)
		if(!t[i]) sum[1]+=a[i];
	for(int i=2;i<=n-k+1;i++){
		sum[i]=sum[i-1];
		if(!t[i-1]) sum[i]-=a[i-1];
		if(!t[i+k-1]) sum[i]+=a[i+k-1];
		if(sum[i]>sum[maxp]) maxp=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(t[i] || (i>=maxp && i<=maxp+k-1)) ans+=a[i];
	printf("%d\n",ans);
}