#include <bits/stdc++.h>

using namespace std;

long long n,d,nn=0,ex[100069];
bitset<100069> vtd;

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=2;i<=n;i++)
	{
		if(!vtd[i])
		{
			nn++;
			ex[nn]=i;
			for(j=i*i;j<=n;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	for(i=1;i<nn;i++)
	{
		k=ex[i]+ex[i+1]+1;
		d-=k<=n&&!vtd[k];
	}
	if(d<=0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}