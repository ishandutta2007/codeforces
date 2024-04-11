#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int k[MAXN][MAXN],br=1,n,m,sz;
long long st[MAXN][MAXN];
int c[MAXN][MAXN],dist[MAXN][MAXN];
bool vi[MAXN][MAXN],stab[MAXN*MAXN];
queue<pair<int,int> > q;
void dfs(int x,int y,int px,int py)
{
	if(k[x][y]!=0) return;
	if(c[px][py]!=c[x][y]) return;
	if(x>n || x<=0) return;
	if(y>m || y<=0) return;
	k[x][y]=br; sz++;
	dfs(x+1,y,x,y); dfs(x-1,y,x,y); dfs(x,y+1,x,y); dfs(x,y-1,x,y);
}
void adq(int x,int y,int px,int py)
{
	if(vi[x][y]) return;
	if(x>n || x<=0) return;
	if(y>m || y<=0) return;
	if(c[x][y]==c[px][py]) return;
	dist[x][y]=dist[px][py]+1;
	vi[x][y]=true;
	if(!stab[k[x][y]]) k[x][y]=k[px][py];
	q.push({x,y});
}
void bfs()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(stab[k[i][j]]) {vi[i][j]=true; q.push({i,j});}
	while(!q.empty())
	{
		pair<int,int> pe=q.front();
		q.pop();
		int x=pe.first,y=pe.second;
		vi[x][y]=true;
		adq(x+1,y,x,y); adq(x-1,y,x,y); adq(x,y+1,x,y); adq(x,y-1,x,y); 
	}
}
int main()
{
	int q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++) c[i][j+1]=s[j]-'0';
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(k[i][j]==0)
	{
		dfs(i,j,i,j);  
		if(sz>1) stab[br]=true;
		sz=0; br++;
	}
	bfs();
	while(q--)
	{
		int x,y; long long p;
		cin>>x>>y>>p;
		if(!stab[k[x][y]]) {printf("%d\n",c[x][y]); continue;}
		if(p<dist[x][y]) printf("%d\n",c[x][y]);
		else
		{
			if(p%2==dist[x][y]%2) printf("%d\n",c[x][y]);
			else printf("%d\n",1-c[x][y]);
		}
	}
}