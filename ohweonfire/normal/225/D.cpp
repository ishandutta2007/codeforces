#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int N=4194303;
char s[17][17];
int dist[17][17][1<<16],n,m,M;
int qx[N+5],qy[N+5],qz[N+5],front,rear;
int px[10],py[10],len,stx,sty;
bool can[4];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=0;i<17;i++)for(int j=0;j<17;j++)
		if(i<1||i>n||j<1||j>m)
			s[i][j]='#';
		else if(s[i][j]>='0'&&s[i][j]<='9')
		{
			len=max(len,s[i][j]-'0');
			px[s[i][j]-'0']=i;
			py[s[i][j]-'0']=j;
		}
	M=1<<(len-1<<1);
	M--;
	int code=0,x,y,z,nx,ny,nz;
	for(int i=1;i<len;i++)
		for(int k=0;k<4;k++)
			if(px[i]+dx[k]==px[i+1]&&py[i]+dy[k]==py[i+1])
				code|=k<<(i-1<<1);
	memset(dist,-1,sizeof(dist));
	qx[rear]=px[1];
	qy[rear]=py[1];
	qz[rear++]=code;
	dist[px[1]][py[1]][code]=0;
	while(front!=rear)
	{
		x=qx[front];
		y=qy[front];
		z=qz[front++];
		front&=N;
		if(s[x][y]=='@')
		{
			printf("%d\n",dist[x][y][z]);
			return 0;
		}
		can[0]=can[1]=can[2]=can[3]=true;
		for(int i=1,curx=x,cury=y,k;i<len-1;i++)
		{
			k=(z>>(i-1<<1))&3;
			curx+=dx[k];
			cury+=dy[k];
			for(int kk=0;kk<4;kk++)if(x+dx[kk]==curx&&y+dy[kk]==cury)
				can[kk]=false;
		}
		for(int k=0;k<4;k++)if(can[k])
		{
			nx=x+dx[k];
			ny=y+dy[k];
			if(s[nx][ny]=='#')continue;
			nz=((z<<2)&M)|(k^1);
			if(dist[nx][ny][nz]!=-1)continue;
			qx[rear]=nx;
			qy[rear]=ny;
			qz[rear++]=nz;
			dist[nx][ny][nz]=dist[x][y][z]+1;
			rear&=N;
		}
	}
	puts("-1");
	return 0;
}