#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[1069],sk[1069],zs=0;
array<long long,1069> a[1069];
map<array<long long,1069>,long long> ls;

int main()
{
	long long i,j,pn=0;
	string s;
	array<long long,1069> tmp;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=0;j<1069;j++)
		{
			a[i][j]=0;
			tmp[j]=0;
		}
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]-'a';
			tmp[m+1-j]=a[i][j];
		}
		if(ls[tmp])
		{
			zs++;
			sq[zs]=i;
			sk[zs]=ls[tmp];
		}
		ls[a[i]]=i;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]!=a[i][m+1-j])
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			pn=i;
		}
	}
	printf("%lld\n",(zs*2+!!pn)*m);
	for(i=1;i<=zs;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%c",(char)a[sq[i]][j]+'a');
		}
	}
	if(pn)
	{
		for(i=1;i<=m;i++)
		{
			printf("%c",(char)a[pn][i]+'a');
		}
	}
	for(i=zs;i;i--)
	{
		for(j=1;j<=m;j++)
		{
			printf("%c",(char)a[sk[i]][j]+'a');
		}
	}
}