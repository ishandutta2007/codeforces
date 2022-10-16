#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<569> a[569];

int main()
{
	long long i,j,c=0;
	bool bad=0;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=n;i;i--)
	{
		for(j=m;j;j--)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='B';
		}
	}
	for(i=n;i;i--)
	{
		for(j=m;j;j--)
		{
			a[i][j]=a[i][j]^a[i-1][j]^a[i][j-1]^a[i-1][j-1];
			c+=a[i][j];
		}
	}
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=m;j++)
		{
			bad|=a[1][1]&&a[i][1]&&a[1][j]&&a[i][j];
		}
	}
	printf("%lld\n",c-bad);
}