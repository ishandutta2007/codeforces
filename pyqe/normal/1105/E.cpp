#include <bits/stdc++.h>

using namespace std;

const long long d=20;
long long n,nn=0,ca[40],al[40],dp[1ll<<d];
map<string,long long> yk;
bitset<40> vtd;

int main()
{
	long long t,rr,i,j,ii,ky,k,mk,mk2,z=0;
	string s;
	
	scanf("%lld%lld",&t,&n);
	n=0;
	for(rr=0;rr<=t;rr++)
	{
		ky=1;
		if(rr<t)
		{
			scanf("%lld",&ky);
		}
		if(ky==1)
		{
			for(i=0;i<nn;i++)
			{
				for(j=i+1;j<nn;j++)
				{
					if(!(al[ca[i]]>>ca[j]&1))
					{
						for(ii=0;ii<2;ii++)
						{
							al[ca[i]]|=1ll<<ca[j];
							swap(i,j);
						}
					}
				}
			}
			nn=0;
			vtd.reset();
		}
		else
		{
			cin>>s;
			if(!yk[s])
			{
				yk[s]=n+1;
				n++;
			}
			k=yk[s]-1;
			if(!vtd[k])
			{
				vtd[k]=1;
				ca[nn]=k;
				nn++;
			}
		}
	}
	for(mk=0;mk<1ll<<min(n,d);mk++)
	{
		for(i=0;i<min(n,d);i++)
		{
			if((mk>>i&1)&&(mk&al[i]))
			{
				break;
			}
		}
		if(i>=min(n,d))
		{
			dp[mk]=__builtin_popcountll(mk);
		}
	}
	for(i=0;i<min(n,d);i++)
	{
		for(mk=(1ll<<min(n,d))-1;mk+1;mk--)
		{
			dp[mk]=max(dp[mk],dp[mk^1ll<<i]*(mk>>i&1));
		}
	}
	for(mk=0;mk<1ll<<n;mk+=1ll<<min(n,d))
	{
		for(i=min(n,d);i<n;i++)
		{
			if((mk>>i&1)&&(mk&al[i]))
			{
				break;
			}
		}
		if(i<n)
		{
			continue;
		}
		mk2=0;
		for(i=0;i<min(n,d);i++)
		{
			mk2|=(long long)!(mk&al[i])<<i;
		}
		z=max(z,dp[mk2]+__builtin_popcountll(mk));
	}
	printf("%lld\n",z);
}