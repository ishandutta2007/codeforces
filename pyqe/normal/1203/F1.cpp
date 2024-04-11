#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,m[2];
pair<long long,long long> a[2][100069];

bool dif(pair<long long,long long> p1,pair<long long,long long> p2)
{
	long long df1,df2;
	
	df1=p1.fr+p1.sc;
	df2=p2.fr+p2.sc;
	if(df1==df2)
	{
		return p1.fr>p2.fr;
	}
	else
	{
		return df1>df2;
	}
}
int main()
{
	long long i,ii,k,l,p;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		p=l<0;
		m[p]++;
		a[p][m[p]]={k,l};
	}
	sort(a[0]+1,a[0]+m[0]+1);
	sort(a[1]+1,a[1]+m[1]+1,dif);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=m[ii];i++)
		{
			k=a[ii][i].fr;
			l=a[ii][i].sc;
			if(d<k)
			{
				printf("NO\n");
				return 0;
			}
			d+=l;
		}
	}
	if(d<0)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}