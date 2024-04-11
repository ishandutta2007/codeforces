#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[500069][20],bl[500069];
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,j,k,l,mx=-1e18,z;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	sort(a+1,a+n+1);
	for(j=1,i=0;i<=500000;i++)
	{
		for(;j<=n&&a[j].fr<=i;j++)
		{
			mx=max(mx,a[j].sc);
		}
		mx=max(mx,i);
		pr[i][0]=mx;
	}
	for(i=500000;i>=0;i--)
	{
		if(pr[i][0]!=i)
		{
			for(j=1;j-1<bl[pr[i][j-1]];j++)
			{
				pr[i][j]=pr[pr[i][j-1]][j-1];
			}
			bl[i]=j;
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=0;
		for(i=19;i>=0;i--)
		{
			if(i<bl[k]&&pr[k][i]<l)
			{
				k=pr[k][i];
				z+=1<<i;
			}
		}
		z++;
		if(pr[k][0]<l)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}