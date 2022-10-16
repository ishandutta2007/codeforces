#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sz=0,a[300069],fq[300069],ls[300069],c=0;
queue<pair<long long,long long>> q;

int main()
{
	long long t,rr,ky,k,i,mx=0;
	
	scanf("%lld%lld",&n,&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			q.push({k,rr});
			fq[k]++;
			sz++;
		}
		else if(ky==2)
		{
			sz-=fq[k];
			fq[k]=0;
			ls[k]=rr;
		}
		else if(ky==3)
		{
			for(i=mx+1;i<=k;i++,q.pop())
			{
				if(ls[q.front().fr]<q.front().sc)
				{
					fq[q.front().fr]--;
					sz--;
				}
				mx=k;
			}
		}
		printf("%lld\n",sz);
	}
}