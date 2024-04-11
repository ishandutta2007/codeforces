#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sq[200069],zs=0,inf=1e9;
map<long long,bool> vtd;

int main()
{
	long long i,k,l;
	
	zs++;
	sq[zs]=1;
	vtd[1]=1;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(i-1)
		{
			k=abs(a[i]-a[i-1]);
			if(!k)
			{
				printf("NO\n");
				return 0;
			}
			if(!vtd[k])
			{
				zs++;
				sq[zs]=k;
				vtd[k]=1;
			}
		}
	}
	if(zs>2)
	{
		printf("NO\n");
		return 0;
	}
	sort(sq+1,sq+zs+1,greater<long long>());
	if(zs==2)
	{
		for(i=2;i<=n;i++)
		{
			k=a[i];
			l=a[i-1];
			if(k>l)
			{
				swap(k,l);
			}
			if(k%sq[1]==0&&l==k+1)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n%lld %lld\n",inf,sq[1]);
}