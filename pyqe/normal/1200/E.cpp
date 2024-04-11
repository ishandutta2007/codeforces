#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],sq[1000069],zs=0,faf[1000069];

int main()
{
	long long t,rr,i,j,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1];
		}
		faf[0]=-1;
		for(i=1;i<=n;i++)
		{
			for(j=i-1;j&&a[faf[j]+1]!=a[i];j=faf[j]);
			faf[i]=faf[j]+1;
		}
		c=0;
		for(i=max(zs-n+1,1ll);i<=zs;i++)
		{
			for(;c>=0&&a[c+1]!=sq[i];c=faf[c]);
			c++;
		}
		for(i=c+1;i<=n;i++)
		{
			zs++;
			sq[zs]=a[i];
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%c",(char)sq[i]);
	}
	printf("\n");
}