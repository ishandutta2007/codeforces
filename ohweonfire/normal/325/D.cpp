#include<bits/stdc++.h>
#define ID(x,y) (((x)-1)*(c*2)+(y))
using namespace std;
const int maxn=3005;
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};
int f[maxn*maxn*2],r,c,n;
int ff[maxn*maxn*2];
bool bo[maxn][maxn*2];
int gf(int x)
{
	if(f[x]==x)return x;
	return f[x]=gf(f[x]);
}
void add(int x,int y)
{
	bo[x][y]=true;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<1||nx>r)continue;
		if(ny<1)ny=c+c;
		if(ny>c+c)ny=1;
		if(!bo[nx][ny])continue;
		f[gf(ID(nx,ny))]=gf(ID(x,y));
	}
}
int main()
{
	scanf("%d%d%d",&r,&c,&n);
	int x,y,nx,ny,ans=0;
	if(c==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c*2;j++)
			f[ID(i,j)]=ID(i,j);
	for(int _=1;_<=n;_++)
	{
		scanf("%d%d",&x,&y);
		bool ok=false;
		for(int i=0;i<8;i++)
		{
			nx=x+dx[i];
			ny=y+dy[i];
			if(nx<1||nx>r)continue;
			if(ny<1)ny=c+c;
			if(ny>c+c)ny=1;
			if(!bo[nx][ny])continue;
			ff[gf(ID(nx,ny))]=_;
		}
		for(int i=0;i<8&&!ok;i++)
		{
			nx=x+dx[i];
			ny=y+c+dy[i];
			if(nx<1||nx>r)continue;
			if(ny<1)ny=c+c;
			if(ny>c+c)ny=1;
			if(!bo[nx][ny])continue;
			ok|=(ff[gf(ID(nx,ny))]==_);
		}
		if(ok)continue;
		ans++;
		add(x,y);
		add(x,y+c);
	}
	cout<<ans<<endl;
	return 0;
}
/*
3 4 9
2 2
3 2
2 3
3 4
3 1
1 3
2 1
1 1
1 4
*/