#include<bits/stdc++.h> 
using namespace std;
int n,i,a[300010],f[35],g[35],j;
int main(){
	scanf("%d",&n);
	for(i=1;i<=31;i++)g[i]=1e9;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]/=100;
		f[0]=f[1]=1e9;
		for(j=a[i]/10;j<=31;j++)
			f[j]=g[j-a[i]/10]+a[i];
		for(j=a[i];j<=31;j++)
			f[j-a[i]]=min(f[j-a[i]],g[j]);
		for(j=1;j<a[i];j++)
			f[0]=min(f[0],g[j]+a[i]-j);
		for(j=0;j<=31;j++)g[j]=f[j];
	}
	for(j=1;j<=31;j++)if(g[j]<g[0])g[0]=g[j];
	printf("%d\n",g[0]*100);
}