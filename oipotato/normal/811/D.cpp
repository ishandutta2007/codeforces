#include<cstdio>
#include<algorithm>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
char button[4]={'U','R','D','L'};
struct queue
{
	int x,y;
}que[10010];
int nowx,nowy,aimx,aimy,t,w,n,m,way[110][110];
bool ok[110][110],vis[110][110];
char ch;
void BFS()
{
	vis[aimx][aimy]=1;
	que[++w]=(queue){aimx,aimy};
	for(;t<w;)
	{
		queue u=que[++t];
		for(int i=0;i<4;i++)
		{
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(ok[nx][ny]&&!vis[nx][ny])
			{
				vis[nx][ny]=1;
				way[nx][ny]=i;
				que[++w]=(queue){nx,ny};
			}
		}
	}
	for(;nowx!=aimx||nowy!=aimy;)
	{
		printf("%c\n",button[way[nowx][nowy]]);
		fflush(stdout);
		scanf("%d%d",&nowx,&nowy);
	}
}
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='.'||ch=='F')ok[i][j]=1;
			if(ch=='F')
			{
				aimx=i;
				aimy=j;
			}
		}
		getchar();
	}
	if(ok[1][2])
	{
		printf("R\n");
		fflush(stdout);
		scanf("%d%d",&nowx,&nowy);
		if(nowy==1)swap(button[1],button[3]);
		printf("%c\n",button[3]);
		fflush(stdout);
		scanf("%d%d",&nowx,&nowy);
		for(;!ok[nowx+1][nowy]&&(nowx!=aimx||nowy!=aimy);)
		{
			printf("%c\n",button[1]);
			fflush(stdout);
			scanf("%d%d",&nowx,&nowy);
		}
		if(nowx==aimx&&nowy==aimy)return 0;
		printf("D\n");
		fflush(stdout);
		scanf("%d%d",&nowx,&nowy);
		if(nowx==1)swap(button[0],button[2]);
	}
	else
	{
		printf("D\n");
		fflush(stdout);
		scanf("%d%d",&nowx,&nowy);
		if(nowx==1)swap(button[0],button[2]);
		printf("%c\n",button[0]);
		fflush(stdout);
		scanf("%d%d",&nowx,&nowy);
		for(;!ok[nowx][nowy+1]&&(nowx!=aimx||nowy!=aimy);)
		{
			printf("%c\n",button[2]);
			fflush(stdout);
			scanf("%d%d",&nowx,&nowy);
		}
		if(nowx==aimx&&nowy==aimy)return 0;
		printf("R\n");
		fflush(stdout);
		scanf("%d%d",&nowx,&nowy);
		if(nowy==1)swap(button[1],button[3]);
	}
	BFS();
	return 0;
}