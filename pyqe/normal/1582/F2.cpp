#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int d=13,ma=5e3;
int n,nn,pst[1ll<<d],sq[100069],zs=0;
vector<int> vl[5069];
pair<int,int> dp[1ll<<d];

int main()
{
	int i,j,r,k,l,sz;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		vl[k].push_back(i);
	}
	nn=1;
	dp[0]={0,0};
	for(i=1;i<=ma;i++)
	{
		if(i>=nn)
		{
			for(j=i;j<i*2;j++)
			{
				dp[nn]={n+1,j};
				pst[j]=nn;
				nn++;
			}
		}
		sz=vl[i].size();
		for(r=nn-1,j=sz-1;j+1;j--)
		{
			k=vl[i][j];
			for(;r+1&&dp[r].fr>k;r--);
			for(;r+1&&(!j||dp[r].fr>vl[i][j-1]);r--)
			{
				l=dp[r].sc;
				dp[pst[l^i]].fr=min(dp[pst[l^i]].fr,k);
			}
		}
		sort(dp,dp+nn);
		for(j=0;j<nn;j++)
		{
			k=dp[j].sc;
			pst[k]=j;
		}
	}
	for(i=0;i<1ll<<d;i++)
	{
		if(dp[pst[i]].fr<=n)
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%d\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%d%c",sq[i]," \n"[i==zs]);
	}
}