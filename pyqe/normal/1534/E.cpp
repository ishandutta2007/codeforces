#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,nn,nr[569],pr[569],ca[569];
queue<long long> q;
bitset<569> vtd;

int main()
{
	long long i,k,p,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<=n;i++)
	{
		nr[i]=inf;
	}
	q.push(0);
	nr[0]=0;
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		for(i=0;i<=n;i++)
		{
			if((k+d+i)%2==0&&(k+d+i)/2<=n&&(k+d-i)/2>=0&&(k+d-i)/2<=min(d,k))
			{
				if(nr[k]+1<nr[i])
				{
					q.push(i);
					nr[i]=nr[k]+1;
					pr[i]=k;
				}
			}
		}
	}
	if(nr[n]==inf)
	{
		printf("-1\n");
		fflush(stdout);
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		vtd[i]=i;
	}
	for(p=n;p;p=pr[p])
	{
		k=(p+d-pr[p])/2;
		nn=0;
		for(i=1;i<=n;i++)
		{
			if(vtd[i]&&nn<k)
			{
				nn++;
				ca[nn]=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!vtd[i]&&nn<d)
			{
				nn++;
				ca[nn]=i;
			}
		}
		printf("?");
		for(i=1;i<=nn;i++)
		{
			printf(" %lld",ca[i]);
			vtd[ca[i]]=!vtd[ca[i]];
		}
		printf("\n");
		fflush(stdout);
		scanf("%lld",&k);
		z^=k;
	}
	printf("! %lld\n",z);
	fflush(stdout);
}