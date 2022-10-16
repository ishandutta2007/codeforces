#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int sqn=1100;
int n,m=0,dp[100069],fh[100069],sq[100069];
pair<int,int> ed[200069];
vector<int> al[100069];
bitset<100069> vtd;

void rtd(int x)
{
	int i,sz=al[x].size(),l;
	vector<int> v;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			rtd(l);
			v.push_back(l);
		}
	}
	sz=v.size();
	for(i=0;i<sz;i++)
	{
		l=v[i];
		m++;
		ed[m]={x,l};
	}
	m++;
	ed[m]={x,0};
}

inline int slv(int x)
{
	int i,k,l,mx[2]={0,0};
	
	for(i=1;i<=n;i++)
	{
		dp[i]=0;
		fh[i]=0;
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(l)
		{
			dp[k]+=dp[l];
			fh[k]=max(fh[k],fh[l]+1);
			mx[1]=max(mx[1],min(mx[0],fh[l]+1));
			mx[0]=max(mx[0],fh[l]+1);
		}
		else
		{
			if(mx[0]+mx[1]+1>=x)
			{
				dp[k]++;
				fh[k]=-1;
			}
			mx[0]=0;
			mx[1]=0;
		}
	}
	return dp[1];
}

int main()
{
	int i,k,l,lh,rh,md,zz;
	
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	rtd(1);
	for(i=1;i<=min(n/sqn,n);i++)
	{
		for(lh=1,rh=n/i;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(slv(md)>=i)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		sq[zz]=i;
	}
	for(i=n-1;i;i--)
	{
		sq[i]=max(sq[i],sq[i+1]);
	}
	for(i=1;i<=min(sqn,n);i++)
	{
		sq[i]=slv(i);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d\n",sq[i]);
	}
}