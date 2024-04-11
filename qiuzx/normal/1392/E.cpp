#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 30
using namespace std;
int n;
ll grid[N][N],k;
vector<pair<int,int> > ans;
void construct()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i%2==1)
			{
				grid[i][j]=0;
			}
			else
			{
				grid[i][j]=((ll)1<<(i-1+j));
			}
		}
	}
	grid[0][0]=grid[n-1][n-1]=0;
	return;
}
void query(int x,int y)
{
	ans.push_back(make_pair(x,y));
	k^=grid[x][y];
	if(x==n-1&&y==n-1)
	{
		return;
	}
	if(x==n-1)
	{
		query(x,y+1);
	}
	else if(y==n-1)
	{
		query(x+1,y);
	}
	else
	{
		if(grid[x+1][y]==0)
		{
			if(k&grid[x][y+1])
			{
				query(x,y+1);
			}
			else
			{
				query(x+1,y);
			}
		}
		else
		{
			if(k&grid[x+1][y])
			{
				query(x+1,y);
			}
			else
			{
				query(x,y+1);
			}
		}
	}
	return;
}
int main(){
	int i,j,q;
	scanf("%d",&n);
	construct();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lld ",grid[i][j]);
		}
		puts("");
	}
	fflush(stdout);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld",&k);
		ans.clear();
		query(0,0);
		for(i=0;i<ans.size();i++)
		{
			printf("%d %d\n",ans[i].F+1,ans[i].S+1);
		}
		fflush(stdout);
	}
	return 0;
}