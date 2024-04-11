#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};
struct data
{
	int id,t,dir,x,y;
};
queue<data>q;
int ans,n,t[33];
bool vis[31][6][8][310][310],fil[310][310];
void insert(int id,int t,int dir,int x,int y)
{
	if(vis[id][t][dir][x][y])return;
	if(!fil[x][y])fil[x][y]=1,ans++;
	vis[id][t][dir][x][y]=1;
	q.push({id,t,dir,x,y});
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&t[i]);
	insert(1,t[1],0,151,151);
	for(;!q.empty();)
	{
		data u=q.front();q.pop();
		if(u.t==1)
		{
			if(u.id==n)continue;
			insert(u.id+1,t[u.id+1],(u.dir+7)%8,u.x+dx[(u.dir+7)%8],u.y+dy[(u.dir+7)%8]);
			insert(u.id+1,t[u.id+1],(u.dir+1)%8,u.x+dx[(u.dir+1)%8],u.y+dy[(u.dir+1)%8]);
		}
		else
		{
			insert(u.id,u.t-1,u.dir,u.x+dx[u.dir],u.y+dy[u.dir]);
		}
	}
	printf("%d\n",ans);
	return 0;
}