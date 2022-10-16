#include <bits/stdc++.h>

using namespace std;

long long n,fh[300069],dp[300069][18],z;
vector<long long> al[300069];
bitset<300069> vtd;

void bd(long long x)
{
	long long i,j,sz=al[x].size(),l,lh,rh,md,zz,c;
	vector<long long> v;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			fh[x]=max(fh[x],fh[l]+1);
			v.push_back(l);
		}
	}
	sz=v.size();
	dp[x][0]=n;
	for(i=1;i<18;i++)
	{
		for(lh=0,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			c=0;
			for(j=0;j<sz;j++)
			{
				l=v[j];
				c+=md<=dp[l][i-1];
			}
			if(c>=md)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		dp[x][i]=zz;
	}
	z+=fh[x];
}

void bd2(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd2(l);
			for(j=0;j<18;j++)
			{
				dp[x][j]=max(dp[x][j],dp[l][j]);
			}
		}
	}
	l=1;
	for(i=17;i+1;i--)
	{
		z+=max(dp[x][i]-l,0ll)*i;
		l=max(l,dp[x][i]);
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	z=n*n;
	bd(1);
	vtd.reset();
	bd2(1);
	printf("%lld\n",z);
}