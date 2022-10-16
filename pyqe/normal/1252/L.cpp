#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][100069],faf[100069];

int main()
{
	long long i,j,ii,c=0,z=0;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n[ii]=s.length();
		for(i=1;i<=n[ii];i++)
		{
			a[ii][i]=s[i-1]-'a';
		}
	}
	faf[0]=-1;
	for(i=1;i<=n[1];i++)
	{
		for(j=i-1;j&&a[1][faf[j]+1]!=a[1][i];j=faf[j]);
		faf[i]=faf[j]+1;
	}
	for(i=1;i<=n[0];i++)
	{
		for(;c>=0&&a[1][c+1]!=a[0][i];c=faf[c]);
		c++;
		if(c==n[1])
		{
			z++;
			c=0;
		}
	}
	printf("%lld\n",z);
}