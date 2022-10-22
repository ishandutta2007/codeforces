#include<cstdio>
#include<iostream>
using namespace std;

int n,a[1001],f[1001],ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[i]=f[i-1]+a[i];
	ans=361;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans=min(ans,max(360-2*(f[j]-f[i-1]),2*(f[j]-f[i-1])-360));
		cout<<ans;
}