#include<cstdio>
#include<iostream>
using namespace std;
int n,a[100010],p,sum1,sum2,ans;
int mod(int x,int p){
	return (x%p+p)%p;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum2=mod(sum2+a[i],p);
	}
	sum1=a[1];
	sum2-=a[1];
	sum1=mod(sum1,p);
	sum2=mod(sum2,p);
	ans=sum1+sum2;
	for(int i=2;i<=n-1;i++){
		sum1=mod(sum1+a[i],p);
		sum2=mod(sum2-a[i],p);
		ans=max(ans,sum1+sum2);
	}
	printf("%d\n",ans);
}