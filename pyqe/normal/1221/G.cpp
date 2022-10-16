#include <bits/stdc++.h>

using namespace std;

const long long d=20;
long long n,m,dsu[80],cc[80],al[40],dp[1ll<<d];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,ii,k,l,mk,mk2,z[4]={1,1,1,0};
	
	scanf("%lld%lld",&n,&m);
	if(!m)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<n*2;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		k--;
		l--;
		for(ii=0;ii<2;ii++)
		{
			if(fd(k)!=fd(n+l))
			{
				cc[fd(k)]+=cc[fd(n+l)];
				dsu[fd(n+l)]=fd(k);
			}
			al[k]|=1ll<<l;
			swap(k,l);
		}
	}
	for(i=0;i<n*2;i++)
	{
		z[0]*=i>=n||fd(i)!=fd(n+i);
	}
	for(i=0;i<n;i++)
	{
		if(fd(i)!=fd(n+i))
		{
			cc[fd(i)]+=cc[fd(n+i)];
			dsu[fd(n+i)]=fd(i);
		}
	}
	for(i=0;i<n*2;i++)
	{
		if(fd(i)==i)
		{
			z[0]*=2;
			z[1]*=2;
			z[2]*=1+(fd(i)==i&&cc[i]==2);
		}
	}
	for(mk=0;mk<1ll<<min(d,n);mk++)
	{
		for(i=0;i<min(d,n);i++)
		{
			if((mk>>i&1)&&(mk&al[i]))
			{
				break;
			}
		}
		dp[mk]+=i>=min(d,n);
	}
	for(i=0;i<min(d,n);i++)
	{
		for(mk=(1ll<<min(d,n))-1;mk+1;mk--)
		{
			dp[mk]+=dp[mk^1ll<<i]*(mk>>i&1);
		}
	}
	for(mk=0;mk<1ll<<n;mk+=1ll<<min(d,n))
	{
		for(i=min(d,n);i<n;i++)
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
		for(i=0;i<min(d,n);i++)
		{
			mk2|=(long long)!(mk&al[i])<<i;
		}
		z[3]+=dp[mk2];
	}
	printf("%lld\n",(1ll<<n)-z[1]-z[3]*2+z[0]+z[2]*2);
}