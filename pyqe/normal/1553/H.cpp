#include <bits/stdc++.h>

using namespace std;

long long n,d,a[600069],pst[1ll<<19],ca[19];

struct trie
{
	long long dh;
	trie *p[3];
	
	void bd(long long x)
	{
		long long ii;
		
		dh=x;
		for(ii=-1;ii<=1;ii++)
		{
			p[ii+1]=0;
		}
	}
	void ins()
	{
		if(dh)
		{
			if(!p[ca[dh-1]+1])
			{
				p[ca[dh-1]+1]=new trie;
				p[ca[dh-1]+1]->bd(dh-1);
			}
			p[ca[dh-1]+1]->ins();
		}
	}
	long long qr(long long x)
	{
		if(!dh)
		{
			return 0;
		}
		else
		{
			long long ii,u=!(x>>dh-1&1)*2-1;
			
			for(ii=-u;ii>=-1&&ii<=1;ii+=u)
			{
				if(p[ii+1])
				{
					return p[ii+1]->qr(x)+(1ll<<dh-1)*ii*u;
				}
			}
		}
	}
}
tr[19];

int main()
{
	long long i,j,r,k,mn,mk,p[2],e,z;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	mn=d;
	for(i=1;i<n;i++)
	{
		for(j=d-1;!((a[i]^a[i+1])>>j&1);j--);
		mn=min(mn,j);
	}
	for(i=mn;i<d;i++)
	{
		tr[i].bd(i);
	}
	mk=(1ll<<d)-(1ll<<mn);
	for(i=1;i<=n;i++)
	{
		pst[a[i]&mk]=i;
	}
	for(i=1;i<=n;i++)
	{
		for(j=mn;j<d;j++)
		{
			p[0]=i;
			p[1]=pst[(a[i]&mk)^(1ll<<j+1)-(1ll<<mn)];
			if(!p[1])
			{
				continue;
			}
			e=a[p[1]]>>j&1;
			for(r=0;r<j;r++)
			{
				ca[r]=(a[p[e]]>>r&1)-(a[p[!e]]>>r&1);
			}
			tr[j].ins();
		}
	}
	for(i=0;i<1ll<<d;i++)
	{
		z=1ll<<d;
		for(j=mn;j<d;j++)
		{
			k=i;
			if(k>>j&1)
			{
				k^=(1ll<<d)-1;
			}
			z=min(z,tr[j].qr(k)+(1ll<<j));
		}
		printf("%lld%c",z," \n"[i==(1ll<<d)-1]);
	}
}