#include <bits/stdc++.h>

using namespace std;

const long long d=18,prt=3,dv=998244353;
long long n,fc[250069],ifc[250069],pc[1ll<<d],fq[250069],pwk;
vector<long long> al[250069],dp[250069];
bitset<250069> vtd;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

inline long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

vector<long long> fft(long long nn,vector<long long> ca,bool iv)
{
	long long i,j,r,k,l,p;
	
	for(i=0;i<nn;i++)
	{
		k=i;
		p=0;
		for(j=0;1ll<<j<nn;j++)
		{
			p=p<<1|k&1;
			k>>=1;
		}
		if(i<p)
		{
			swap(ca[i],ca[p]);
		}
	}
	for(i=1;1ll<<i<=nn;i++)
	{
		for(j=0;j<nn;j+=1ll<<i)
		{
			for(r=0;r<1ll<<i-1;r++)
			{
				k=ca[j+r];
				l=ca[j+r+(1ll<<i-1)];
				p=r<<d-i;
				if(!iv)
				{
					l=l*pc[p]%dv;
				}
				else
				{
					l=l*pc[(1ll<<d)-p]%dv;
				}
				ca[j+r]=(k+l)%dv;
				ca[j+r+(1ll<<i-1)]=(k+dv-l)%dv;
			}
		}
	}
	if(iv)
	{
		k=pw(nn,dv-2);
		for(i=0;i<nn;i++)
		{
			ca[i]=ca[i]*k%dv;
		}
	}
	return ca;
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			fq[x]++;
		}
	}
}

void dnc(long long lh,long long rh)
{
	if(lh==rh)
	{
		dp[lh].push_back(1);
		dp[lh].push_back(fq[lh]);
	}
	else
	{
		long long i,sz,sz2,sz3,md=(lh+rh)/2;
		
		dnc(lh,md);
		dnc(md+1,rh);
		sz=dp[lh].size();
		sz2=dp[md+1].size();
		for(sz3=1;sz3<sz+sz2-1;sz3<<=1);
		for(i=0;i<sz3-sz;i++)
		{
			dp[lh].push_back(0);
		}
		for(i=0;i<sz3-sz2;i++)
		{
			dp[md+1].push_back(0);
		}
		dp[lh]=fft(sz3,dp[lh],0);
		dp[md+1]=fft(sz3,dp[md+1],0);
		for(i=0;i<sz3;i++)
		{
			dp[lh][i]=dp[lh][i]*dp[md+1][i]%dv;
		}
		dp[lh]=fft(sz3,dp[lh],1);
		for(i=0;i<sz3-(sz+sz2-1);i++)
		{
			dp[lh].pop_back();
		}
	}
}

int main()
{
	long long i,k,l,u,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	pc[0]=1;
	k=pw(prt,dv-1>>d);
	for(i=1;i<=1ll<<d;i++)
	{
		pc[i]=pc[i-1]*k%dv;
	}
	dnc(1,n);
	for(i=0;i<=n;i++)
	{
		u=(!(i%2)*2+dv-1)%dv;
		z=(z+dp[1][i]*fc[n-i]%dv*u)%dv;
	}
	printf("%lld\n",z);
}