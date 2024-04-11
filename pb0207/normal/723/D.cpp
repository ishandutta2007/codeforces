#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=5e2+7;

int dx[4]={0,-1,1,0},dy[4]={1,0,0,-1};

int vis[N][N],n,m,k,size[N*N],cnt,in[N][N];

char s[N][N],ans[N][N];

queue<pair<int,int> >q;

bool chk(int x,int y)
{
	return x>=0&&x<=n&&y>=0&&y<=m;
}

void pre()
{
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if(chk(tx,ty)&&s[tx][ty]=='.'&&!vis[tx][ty])
			{
				vis[tx][ty]=true;
				q.push(make_pair(tx,ty));
			}
		}
	}
}

void bfs()
{
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=x+dx[i],ty=y+dy[i];
			if(chk(tx,ty)&&s[tx][ty]=='.'&&!vis[tx][ty])
			{
				size[cnt]++;
				in[tx][ty]=cnt;
				vis[tx][ty]=true;
				q.push(make_pair(tx,ty));
			}
		}
	}
}

struct node{
	int id,v;
}w[N*N];

bool cmp(node a,node b)
{
	return a.v<b.v;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j];
	for(int i=1;i<=n;i++)
	{
		if(s[i][1]=='.')
			q.push(make_pair(i,1)),vis[i][1]=true;
		if(s[i][m]=='.')
			q.push(make_pair(i,m)),vis[i][m]=true;
	}
	for(int i=1;i<=m;i++)
	{
		if(s[1][i]=='.')
			q.push(make_pair(1,i)),vis[1][i]=true;
		if(s[n][i]=='.')
			q.push(make_pair(n,i)),vis[n][i]=true;
	}
	pre();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j]&&s[i][j]=='.')
			{
				q.push(make_pair(i,j));
				vis[i][j]=true;
				size[++cnt]=1;
				in[i][j]=cnt;
				bfs();
			}
	for(int i=1;i<=cnt;i++)
		w[i].id=i,w[i].v=size[i];
	sort(w+1,w+cnt+1,cmp);
	int tot=0;
	for(int t=1;t<=cnt-k;t++)
	{
		tot+=w[t].v;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(in[i][j]==w[t].id)
					ans[i][j]='*';
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!ans[i][j])
				cout<<s[i][j];
			else
				cout<<ans[i][j];
		}
		cout<<endl;
	}
}