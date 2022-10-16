#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm=26,inf=1e18;
long long n,m,d,nn=0,a[1069],fh[1069],dp[1069];
pair<long long,long long> as[500569];

struct trie
{
	long long dh;
	vector<long long> vl;
	trie *p[mm];
	
	inline void bd(long long x)
	{
		long long i;
		
		dh=x;
		for(i=0;i<mm;i++)
		{
			p[i]=0;
		}
	}
	void ins(long long x)
	{
		vl.push_back(x);
		if(dh<n+1-x)
		{
			long long l=a[x+dh];
			
			if(!p[l])
			{
				p[l]=new trie;
				p[l]->bd(dh+1);
			}
			p[l]->ins(x);
		}
	}
	void trv()
	{
		long long i,k,sz=vl.size();
		
		if(dh)
		{
			for(i=0;i<sz;i++)
			{
				k=vl[i];
				nn++;
				as[nn]={k,dh};
			}
		}
		for(i=0;i<mm;i++)
		{
			if(p[i])
			{
				p[i]->trv();
			}
		}
	}
}
tr;

int main()
{
	long long i,j,k,l,lh,rh,md,zz;
	char ch;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	tr.bd(0);
	for(i=1;i<=n;i++)
	{
		tr.ins(i);
	}
	tr.trv();
	for(lh=1,rh=nn;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n+1;i++)
		{
			fh[i]=inf;
			dp[i]=0;
		}
		for(i=md;i<=nn;i++)
		{
			k=as[i].fr;
			l=as[i].sc;
			fh[k]=min(fh[k],l);
		}
		dp[n+1]=1;
		for(i=1;i<=m;i++)
		{
			for(j=n;j;j--)
			{
				dp[j]=min(dp[j]+dp[j+1],d+1);
			}
			for(j=1;j<=n+1;j++)
			{
				if(fh[j]!=inf)
				{
					dp[j]=dp[j+fh[j]];
				}
				else
				{
					dp[j]=0;
				}
			}
		}
		if(dp[1]>=d)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	k=as[zz].fr;
	l=as[zz].sc;
	for(i=k;i<=k+l-1;i++)
	{
		printf("%c",(char)(a[i]+'a'));
	}
	printf("\n");
}