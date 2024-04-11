#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[1000069],sq[1069][1069];

int main()
{
	long long i,j,ls=1,p=0;
	string s;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	cin>>s;
	for(i=1;i<=n*m;i++)
	{
		a[i]=s[i-1]-'a';
	}
	sort(a+1,a+n*m+1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			sq[i][j]=-1;
		}
	}
	for(j=1;j<=m;j++)
	{
		for(i=ls;i<=d;i++)
		{
			p++;
			sq[i][j]=a[p];
			if(p==1||a[p]!=a[p-1])
			{
				ls=i;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(sq[i][j]==-1)
			{
				p++;
				sq[i][j]=a[p];
			}
			printf("%c",sq[i][j]+'a');
		}
		printf("\n");
	}
}