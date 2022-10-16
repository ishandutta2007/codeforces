#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int sqn=58,inf=1e9;
int n,eu[200069],pr[200069],dp[200069],dp2[200069][69],tmp[69],tmp2[69],sq[200069];
vector<int> al[200069],ql[200069];
bitset<200069> vtd;
pair<int,int> qq[200069];

void dfs(int x)
{
	int i,sz=al[x].size(),l;
	
	vtd[x]=1;
	n++;
	eu[n]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
		}
	}
}

int main()
{
	int t,rr,i,j,r,k,l,sz,pz;
	
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	n=0;
	dfs(1);
	scanf("%d",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%d%d",&k,&l);
		qq[rr]={k,l};
		ql[min(l,n/sqn+1)].push_back(rr);
	}
	for(i=0;i<=n/sqn;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[j]=0;
		}
		for(j=n;j;j--)
		{
			k=eu[j];
			dp[pr[k]]+=max(dp[k]-i,1);
		}
		sz=ql[i].size();
		for(j=0;j<sz;j++)
		{
			pz=ql[i][j];
			k=qq[pz].fr;
			sq[pz]=dp[k];
		}
	}
	for(i=n;i;i--)
	{
		k=eu[i];
		for(j=0;j<=sqn;j++)
		{
			if(!j)
			{
				tmp[j]=1;
			}
			else
			{
				tmp[j]=dp2[k][j-1];
			}
			tmp2[j]=-inf;
		}
		for(j=0;j<=sqn;j++)
		{
			for(r=0;r<=sqn-j;r++)
			{
				tmp2[j+r]=max(tmp2[j+r],dp2[pr[k]][j]+tmp[r]);
			}
		}
		for(j=0;j<=sqn;j++)
		{
			dp2[pr[k]][j]=tmp2[j];
		}
	}
	sz=ql[n/sqn+1].size();
	for(i=0;i<sz;i++)
	{
		pz=ql[n/sqn+1][i];
		k=qq[pz].fr;
		l=qq[pz].sc;
		for(j=0;j<=sqn;j++)
		{
			sq[pz]=max(sq[pz],dp2[k][j]-j*l);
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%d\n",sq[rr]);
	}
}