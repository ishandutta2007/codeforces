#include<bits/stdc++.h>
#define y1 shdkfljhwelkjflnkjnvkljsdblkjblzsebjh
using namespace std;

const int M=3005;
int n,m,q,ans;
int fa[M*M*2],flag[M][M*2];

const int fx[]={1,0,-1,0,1,1,-1,-1};
const int fy[]={0,1,0,-1,1,-1,1,-1};

int f(int x,int y)
{
	return (x-1)*2*m+y;
}

int find(int x)
{
	if (fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}

bool ok(int &x,int &y)
{
	if (y==0)y=2*m;
	if (y==2*m+1)y=1;
	return x>0&&x<=n&&flag[x][y];
}

bool check(int x1,int y1)
{
	int x2=x1,y2=y1+m;
	for (int i=0;i<8;i++)
	{
		int tx=x1+fx[i],ty=y1+fy[i];
		if (ok(tx,ty))
		{
			for (int j=0;j<8;j++)
			{
				int bx=x2+fx[j],by=y2+fy[j];
				if (ok(bx,by)&&find(f(bx,by))==find(f(tx,ty)))
					return 0;
			}
		}
	}
	return 1;
}

void deal(int x,int y)
{
	for (int i=0;i<8;i++)
	{
		int tx=x+fx[i],ty=y+fy[i];
		if (ok(tx,ty))
			fa[find(f(x,y))]=find(f(tx,ty));
	}
	flag[x][y]=1;
}

int main()
{
	cin>>n>>m>>q;
	if (m==1)return puts("0"),0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m*2;j++)
			fa[f(i,j)]=f(i,j);
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if (check(x,y))
			deal(x,y),deal(x,y+m),ans++;
//		cout<<i<<':'<<endl;
//		for (int i=1;i<=n;i++)
//		{
//			for (int j=1;j<=m*2;j++)
//				printf("%2d:%2d ",f(i,j),fa[f(i,j)]);
//			cout<<endl;
//		}
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}