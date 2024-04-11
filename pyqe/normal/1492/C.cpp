#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],aa[200069],pst[2][200069];

int main()
{
	long long i,j,ii,u,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	for(i=1;i<=m;i++)
	{
		scanf(" %c",&ch);
		aa[i]=ch-'a';
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(j=1+(n-1)*ii,i=1+(m-1)*ii;i&&i<=m;i+=u)
		{
			for(;a[j]!=aa[i];j+=u);
			pst[ii][i]=j;
			j+=u;
		}
	}
	for(i=2;i<=m;i++)
	{
		z=max(z,pst[1][i]-pst[0][i-1]);
	}
	printf("%lld\n",z);
}