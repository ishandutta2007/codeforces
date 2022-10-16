#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sm[100069],mn[100069],mx[100069],fq[400069],inf=1e18;
pair<long long,long long> as[200069];

int main()
{
	long long t,rr,i,j,k,w,tg,z;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n/2;i++)
		{
			sm[i]=0;
			mn[i]=inf;
			mx[i]=-inf;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			tg=min(i,n+1-i);
			sm[tg]+=k;
			mn[tg]=min(mn[tg],-k+1);
			mx[tg]=max(mx[tg],d-k);
		}
		for(i=1;i<=n/2;i++)
		{
			as[i*2-1]={sm[i]+mn[i],-1};
			as[i*2]={sm[i]+mx[i]+1,1};
			fq[sm[i]]++;
		}
		sort(as+1,as+n+1);
		z=inf;
		w=n;
		for(j=1,i=2;i<=d*2;i++)
		{
			for(;j<=n&&as[j].fr<=i;j++)
			{
				w+=as[j].sc;
			}
			z=min(z,w-fq[i]);
		}
		printf("%lld\n",z);
		for(i=1;i<=n/2;i++)
		{
			fq[sm[i]]--;
		}
	}
}