#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[10][200069],fq[10];
array<long long,10> as[100069];
pair<long long,array<long long,10>> mxe;

inline void ad(array<long long,10> x)
{
	long long i,p=lower_bound(as+1,as+m+1,x)-as,sm=0;
	
	if(p>m||as[p]!=x)
	{
		for(i=0;i<n;i++)
		{
			sm+=a[i][x[i]];
		}
		mxe=max(mxe,{sm,x});
	}
}

int main()
{
	long long i,j;
	array<long long,10> ca={};
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",fq+i);
		for(j=fq[i];j;j--)
		{
			scanf("%lld",&a[i][j]);
		}
		ca[i]=1;
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&as[i][j]);
			as[i][j]=fq[j]+1-as[i][j];
		}
	}
	sort(as+1,as+m+1);
	ad(ca);
	for(i=1;i<=m;i++)
	{
		ca=as[i];
		for(j=0;j<n;j++)
		{
			ca[j]++;
			if(ca[j]<=fq[j])
			{
				ad(ca);
			}
			ca[j]--;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld%c",fq[i]+1-mxe.sc[i]," \n"[i==n-1]);
	}
}