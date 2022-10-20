#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int dx[6]={1,-1,0,0,0,0};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(long long x,char c='\n')
{
	write(x);
	putchar(c);
}
#define id(x,y,z) (x+(y-1)*n+(z-1)*n*m)
#define out(x,y,z) (!(1<=x&&x<=n&&1<=y&&y<=m&&1<=z&&z<=k))
int n,m,k,a[N];
queue<int>b[N];
void insert(int x,int y,int z,int d,int c);
void erase(int x,int y,int z);
void insert(int x,int y,int z,int d,int c)
{
	if (out(x,y,z))
	{
		if (c){puts("-1");exit(0);}
		return;
	}
	if (!c)
	{
		erase(x,y,z);
		insert(x+dx[d],y+dy[d],z+dz[d],d,c);
	}
	else if (!a[id(x,y,z)]) insert(x+dx[d],y+dy[d],z+dz[d],d,c);
	else if (a[id(x,y,z)]<0||a[id(x,y,z)]==c) a[id(x,y,z)]=c,b[id(x,y,z)].push(d);
	else
	{
		erase(x,y,z);
		insert(x+dx[d],y+dy[d],z+dz[d],d,c);
	}
}
void erase(int x,int y,int z)
{
	while (!b[id(x,y,z)].empty())
	{
		int d=b[id(x,y,z)].front(); b[id(x,y,z)].pop();
		insert(x+dx[d],y+dy[d],z+dz[d],d,a[id(x,y,z)]);
	}
	a[id(x,y,z)]=0;
}

signed main()
{
	memset(a,-1,sizeof(a));
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++)
	for (int j=1;j<=k;j++) insert(1,i,j,0,read());
	for (int i=1;i<=m;i++)
	for (int j=1;j<=k;j++) insert(n,i,j,1,read());
	for (int i=1;i<=n;i++)
	for (int j=1;j<=k;j++) insert(i,1,j,2,read());
	for (int i=1;i<=n;i++)
	for (int j=1;j<=k;j++) insert(i,m,j,3,read());
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) insert(i,j,1,4,read());
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) insert(i,j,k,5,read());
	for (int i=1;i<=n;i++)
	{
		for (int x=1;x<=m;x++)
		for (int y=1;y<=k;y++) print(max(a[id(i,x,y)],0)," \n"[y==k]);
		puts("");
	}
	
	return 0;
}