#include<bits/stdc++.h>
using namespace std;
int n,a,b,T,f[1000010],g[1000010],i,j,ans;
char s[1000010];
int main()
{
	scanf("%d%d%d%d%s",&n,&a,&b,&T,s+1);
	f[1]=(s[1]=='w')*b+1;
	for(i=2;i<=n;i++)
		f[i]=f[i-1]+(s[i]=='w')*b+1+a;
	for(i=n;i>=1;i--)
		g[i]=g[i+1]+(s[i]=='w')*b+1+a;
	j=n+1;
	for(i=n;i>=1;i--)
	{
		for(;f[i]+g[j-1]+min(i-1,n-j+2)*a<=T&&j-1>i;j--);
		if(f[i]+g[j]+min(i-1,n-j+1)*a<=T)ans=max(ans,i+n-j+1);
	}
	printf("%d\n",ans);
}