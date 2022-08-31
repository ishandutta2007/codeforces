#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m,r,c,x,y;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool vis[2005][2005];
int q[4000005][5],d[2005][2005];
char mp[2005][2005];

void bfs(int nx,int ny){
	int front=0,rear=0;
	q[rear][0]=nx,q[rear][1]=ny,q[rear][2]=0,q[rear][3]=0;
	rear++;
	while(front<rear){
		int nowx=q[front][0],nowy=q[front][1],numx=q[front][2],numy=q[front][3],dx,dy;
		vis[nowx][nowy]=false;
		front++;
		for(int i=0;i<4;i++){
			dx=nowx+dir[i][0],dy=nowy+dir[i][1];
			if(i==1&&numx==x)
				continue;
			if(i==0&&numy==y)
				continue;
			if(dx<1||dx>n||dy<1||dy>m||mp[dx][dy]=='*')
				continue;
			if(d[nowx][nowy]+(i==1)<d[dx][dy]){
				d[dx][dy]=d[nowx][nowy]+(i==1);
				if(!vis[dx][dy]){
					vis[dx][dy]=true;
					q[rear][0]=dx,q[rear][1]=dy,q[rear][2]=d[dx][dy],q[rear][3]=dy-c+d[dx][dy];
					rear++;
				}
			}
		}
	}
}

int main(){
	cin>>n>>m>>r>>c>>x>>y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	memset(d,0x3f,sizeof(d));
	vis[r][c]=true,d[r][c]=0;
	bfs(r,c);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=(d[i][j]!=0x3f3f3f3f?1:0);
	cout<<ans<<endl;
	return 0;
}