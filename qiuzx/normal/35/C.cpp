#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 10000000000
#define N 2020
using namespace std;
ll n,m,num;
bool vis[N][N];
queue<pair<ll,ll> > q;
int main(){
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ll i,j,x,y;
	cin>>n>>m>>num;
	for(i=0;i<num;i++)
	{
		cin>>x>>y;
		vis[x][y]=true;
		q.push(make_pair(x,y));
	}
	if(num==n*m)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	while(!q.empty())
	{
		x=q.front().F;
		y=q.front().S;
		q.pop();
		if(num==n*m-1)
		{
			break;
		}
		if(x-1>0&&(!vis[x-1][y]))
		{
			num++;
			vis[x-1][y]=true;
			q.push(make_pair(x-1,y));
			if(num==n*m-1)
			{
				break;
			}
		}
		if(x+1<=n&&(!vis[x+1][y]))
		{
			num++;
			vis[x+1][y]=true;
			q.push(make_pair(x+1,y));
			if(num==n*m-1)
			{
				break;
			}
		}
		if(y-1>0&&(!vis[x][y-1]))
		{
			num++;
			vis[x][y-1]=true;
			q.push(make_pair(x,y-1));
			if(num==n*m-1)
			{
				break;
			}
		}
		if(y+1<=m&&(!vis[x][y+1]))
		{
			num++;
			vis[x][y+1]=true;
			q.push(make_pair(x,y+1));
			if(num==n*m-1)
			{
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!vis[i][j])
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}