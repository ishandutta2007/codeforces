#include<bits/stdc++.h>
using namespace std;
char z[2010][2010];
typedef pair<int,int> pii;
deque<pii> q;
int d[2010][2010],v[2010][2010];
int main()
{
	int n,m,x,y,a,b;
	cin>>n>>m>>x>>y>>a>>b;
	for(int i=1;i<=n;i++)
		scanf("%s",z[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			d[i][j]=1050000000;
	d[x][y]=0;
	q.push_back(make_pair(x,y));
	while(!q.empty())
	{
		pii t1=q.front();
		q.pop_front();
		int x=t1.first,y=t1.second;
		if(v[x][y])
			continue;
		v[x][y]=1;
		if(d[x][y]<d[x-1][y]&&z[x-1][y]=='.')
		{
			d[x-1][y]=d[x][y];
			q.push_front(make_pair(x-1,y));
		}
		if(d[x][y]<d[x+1][y]&&z[x+1][y]=='.')
		{
			d[x+1][y]=d[x][y];
			q.push_front(make_pair(x+1,y));
		}
		if(d[x][y]<d[x][y+1]&&z[x][y+1]=='.')
		{
			d[x][y+1]=d[x][y];
			q.push_front(make_pair(x,y+1));
		}			
		if(d[x][y]+1<d[x][y-1]&&z[x][y-1]=='.')
		{
			d[x][y-1]=d[x][y]+1;
			q.push_back(make_pair(x,y-1));
		}	
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			//cout<<i<<' '<<j<<' '<<d[i][j]<<endl;
			if(z[i][j]=='.'&&d[i][j]<=a&&(j-y+d[i][j])<=b)
				ans++;
		}
	cout<<ans;
}