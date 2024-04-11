#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[2][1069];
bitset<1069> a[1069];

int main()
{
	long long i,j,z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]=='*';
			fq[0][i]+=a[i][j];
			fq[1][j]+=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			z+=(fq[0][i]-1)*(fq[1][j]-1)*a[i][j];
		}
	}
	printf("%lld\n",z);
}