#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long nn[2],n[2],faf[200069];
pair<long long,long long> a[2][200069];

int main()
{
	long long i,j,ii,k,c=0,z=0;
	char ch;
	
	scanf("%lld%lld",nn,nn+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=nn[ii];i++)
		{
			scanf("%lld %c %c",&k,&ch,&ch);
			if(i==1||a[ii][n[ii]].sc!=ch-'a')
			{
				n[ii]++;
			}
			a[ii][n[ii]].sc=ch-'a';
			a[ii][n[ii]].fr+=k;
		}
	}
	if(n[1]==1)
	{
		for(i=1;i<=n[0];i++)
		{
			if(a[0][i].sc==a[1][1].sc)
			{
				z+=max(a[0][i].fr-a[1][1].fr+1,0ll);
			}
		}
		printf("%lld\n",z);
	}
	else
	{
		faf[0]=-1;
		for(i=1;i<=n[1]-2;i++)
		{
			for(j=i-1;j&&a[1][faf[j]+2]!=a[1][i+1];j=faf[j]);
			faf[i]=faf[j]+1;
		}
		for(i=1;i<=n[0]-1;i++)
		{
			for(;c>=0&&(c+1>n[1]-2||a[1][c+2]!=a[0][i]);c=faf[c]);
			c++;
			if(c==n[1]-2)
			{
				if(i-n[1]+2&&a[0][i-n[1]+2].sc==a[1][1].sc&&a[0][i-n[1]+2].fr>=a[1][1].fr&&a[0][i+1].sc==a[1][n[1]].sc&&a[0][i+1].fr>=a[1][n[1]].fr)
				{
					z++;
				}
				c=faf[c];
			}
		}
		printf("%lld\n",z);
	}
}