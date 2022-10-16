#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,dp[169][169],inf=1e9;
vector<pair<int,int>> al[169];

int bf(int x,int y)
{
	if(dp[x][y]==-inf)
	{
		int i,sz=al[x].size(),l,ww;
		
		for(i=0;i<sz;i++)
		{
			l=al[x][i].fr;
			ww=al[x][i].sc;
			if(ww>bf(y,l))
			{
				dp[x][y]=max(dp[x][y],ww);
			}
		}
		if(dp[x][y]==-inf)
		{
			dp[x][y]=-1;
		}
	}
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j,k,l;
	char ch;
	
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>k>>l>>ch;
		al[k].push_back({l,ch-'a'});
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=-inf;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<(char)((bf(i,j)==-1)+'A');
		}
		cout<<"\n";
	}
}