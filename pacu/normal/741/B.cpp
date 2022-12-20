#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int w[1000],b[1000];

int fid[1000];
int cid[1000];

int dp[1001][1001];

void init()
{
	for(int i=0;i<N;i++) fid[i] = i;
}
int find(int i)
{
	if(fid[i]==i) return i;
	return fid[i] = find(fid[i]);
}
void join(int i,int j)
{
	i = find(i), j = find(j);
	fid[i] = j;
}

bool cmp(int x,int y)
{
	return find(x)<find(y);
}

vector<int> lst[1001];

int main()
{
	int M,W;
	cin >> N >> M >> W;
	for(int i=0;i<N;i++) cin >> w[i];
	for(int i=0;i<N;i++) cin >> b[i];
	int x,y;
	init();
	for(int i=0;i<M;i++)
	{
		cin >> x >> y;
		x--,y--;
		join(x,y);
	}
	for(int i=0;i<N;i++) lst[find(i)+1].push_back(i);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=W;j++)
			dp[i][j] = dp[i-1][j];
		int tw = 0;
		int tb = 0;
		for(int k=0;k<lst[i].size();k++)
		{
			//cout << i << ": " << w[lst[i][k]] << ' ' << b[lst[i][k]] << '\n';
			tw += w[lst[i][k]];
			tb += b[lst[i][k]];
			for(int j=w[lst[i][k]];j<=W;j++)
				dp[i][j] = max(dp[i][j],dp[i-1][j-w[lst[i][k]]]+b[lst[i][k]]);
		}
		for(int j=tw;j<=W;j++)
			dp[i][j] = max(dp[i][j],dp[i-1][j-tw]+tb);
	}
	int ans = 0;
	for(int i=0;i<=W;i++)
		ans = max(ans,dp[N][i]);
	cout << ans << '\n';
}