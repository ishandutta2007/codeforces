#include<cstdio>
#include<algorithm>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
struct queue
{
	int x,y,dir,t;
}que[4000010];
bool vis[1010][1010][4],ok[1010][1010];
int n,m,t,w,Sx,Sy,Tx,Ty;
char ch;
void BFS()
{
	for(int i=0;i<4;i++)
	{
		que[++w]=(queue){Sx,Sy,i,0};
		vis[Sx][Sy][i]=1;
	}
	for(;t<w;)
	{
		queue u=que[++t];
		//printf("%d %d %d %d\n",u.x,u.y,u.dir,u.t);
		if(u.x==Tx&&u.y==Ty&&u.t<=2)
		{
			printf("YES\n");
			exit(0);
		}
		int ndir=u.dir,nt=u.t;
		int nx=u.x+dx[ndir],ny=u.y+dy[ndir];
		if(ok[nx][ny]&&!vis[nx][ny][ndir])
		{
			que[++w]=(queue){nx,ny,ndir,nt};
			vis[nx][ny][ndir]=1;
		}
		ndir=(u.dir+1)%4;nt=u.t+1;
		nx=u.x;ny=u.y;
		if(ok[nx][ny]&&!vis[nx][ny][ndir])
		{
			que[++w]=(queue){nx,ny,ndir,nt};
			vis[nx][ny][ndir]=1;
		}
		ndir=(u.dir+3)%4;nt=u.t+1;
		nx=u.x;ny=u.y;
		if(ok[nx][ny]&&!vis[nx][ny][ndir])
		{
			que[++w]=(queue){nx,ny,ndir,nt};
			vis[nx][ny][ndir]=1;
		}
	}
	printf("NO\n");
}
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch!='*')ok[i][j]=1;
			if(ch=='S')Sx=i,Sy=j;
			if(ch=='T')Tx=i,Ty=j;
		}
		getchar();
	}
	BFS();
	return 0;
}