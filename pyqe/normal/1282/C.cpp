#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ln,fq[2],w[2];
pair<long long,bool> a[200069];

int main()
{
	long long t,rr,i,ii,k,ky,mx,sm,kk,z,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&ln,w,w+1);
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].sc);
			fq[a[i].sc]++;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].fr);
			a[i].fr--;
		}
		a[n+1]={ln,0};
		sort(a+1,a+n+2);
		mx=0;
		sm=0;
		for(i=1;i<=n+1;i++)
		{
			k=a[i].fr;
			ky=a[i].sc;
			if(sm<=k)
			{
				kk=k-sm;
				z=i-1;
				for(ii=0;ii<2;ii++)
				{
					c=min(fq[ii],kk/w[ii]);
					z+=c;
					kk-=w[ii]*c;
				}
				mx=max(mx,z);
			}
			fq[ky]--;
			sm+=w[ky];
		}
		printf("%lld\n",mx);
	}
}