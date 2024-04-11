#include <bits/stdc++.h>
#define N 5010
using namespace std;
int dp[N][N],path[N][N],n,m,T;
vector<int> vp[N],t[N],ans;
priority_queue<pair<int,pair<int,int> > > q;
void ptpath(int p)
{
	int x,i;
	ans.push_back(n);
	x=path[p][n-1];
	while(x!=-1)
	{
		ans.push_back(x+1);
		p--;
		x=path[p][x];
	}
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return;
}
int main(){
	int i,j,k,x,y,z;
	cin>>n>>m>>T;
	for(i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		x--;
		y--;
		vp[x].push_back(y);
		t[x].push_back(z);
	}
	memset(dp,63,sizeof(dp));
	memset(path,-1,sizeof(path));
	dp[1][0]=0;
	q.push(make_pair(0,make_pair(1,0)));
	while(q.size())
	{
		x=-q.top().first;
		y=q.top().second.first;
		z=q.top().second.second;
		q.pop();
		if(x!=dp[y][z])
		{
			continue;
		}
		for(i=0;i<vp[z].size();i++)
		{
			if(dp[y+1][vp[z][i]]>x+t[z][i])
			{
				dp[y+1][vp[z][i]]=x+t[z][i];
				path[y+1][vp[z][i]]=z;
				q.push(make_pair(-dp[y+1][vp[z][i]],make_pair(y+1,vp[z][i])));
			}
		}
	}
	for(i=n;i>=1;i--)
	{
		if(dp[i][n-1]>T)
		{
			continue;
		}
		ptpath(i);
		break;
	}
	return 0;
}