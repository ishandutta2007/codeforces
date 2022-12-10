#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 1005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,x[3],y[3];
int dis[3][N][N],lastx[3][N][N],lasty[3][N][N];

vector<pair<int,int> >v;
pair<int,int> Q[2000005];

int check(int ty,int sx,int sy)
{
		if (sx<0||sy<0||sx>1000||sy>1000) return 0;
		if (dis[ty][sx][sy]>1000000) return 1;
		return 0;
}

int X[]={-1,1,0,0};
int Y[]={0,0,-1,1};

void Work(int ty)
{
		int l,r; int i;
		memset(dis[ty],60,sizeof(dis[ty]));
		dis[ty][x[ty]][y[ty]]=0;
		Q[r=1]=mk(x[ty],y[ty]);
		for (l=1;l<=r;++l)
		{
				int ax=Q[l].fi,ay=Q[l].se;
//				printf("%d %d\n",ax,ay);
				for (i=0;i<4;++i)
					if (check(ty,ax+X[i],ay+Y[i]))
					{
							dis[ty][ax+X[i]][ay+Y[i]]=dis[ty][ax][ay]+1;
							Q[++r]=mk(ax+X[i],ay+Y[i]);
							lastx[ty][ax+X[i]][ay+Y[i]]=ax;
							lasty[ty][ax+X[i]][ay+Y[i]]=ay; 
					}
		}
}

void hy(int x,int y)
{
		int a=x,b=y;
		while (dis[0][x][y]) 
		{
				v.pb(mk(x,y));
				int sx=lastx[0][x][y],sy=lasty[0][x][y];
				x=sx; y=sy;
		}
		v.pb(mk(x,y));
		x=a; y=b;
		while (dis[1][x][y]) 
		{
				v.pb(mk(x,y));
				int sx=lastx[1][x][y],sy=lasty[1][x][y];
				x=sx; y=sy;
		}	
		v.pb(mk(x,y));	
		x=a; y=b;
		while (dis[2][x][y]) 
		{
				v.pb(mk(x,y));
				int sx=lastx[2][x][y],sy=lasty[2][x][y];
				x=sx; y=sy;
		}
		v.pb(mk(x,y));
		sort(v.begin(),v.end());
		int w=unique(v.begin(),v.end())-v.begin();
		printf("%d\n",w);
		for (i=0;i<w;++i) printf("%d %d\n",v[i].fi,v[i].se); 
}

int main()
{
		for (i=0;i<3;++i) scanf("%d%d",&x[i],&y[i]);
		for (i=0;i<3;++i) Work(i);
		int ans=10000000,ans1=-1,ans2=-1;
		for (i=0;i<=1000;++i)
			for (j=0;j<=1000;++j)
			{
					int p=dis[0][i][j]+dis[1][i][j]+dis[2][i][j];
					if (ans>p) ans1=i,ans2=j,ans=p;
			}
		hy(ans1,ans2);
}