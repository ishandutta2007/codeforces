//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,m;
int dis[3011][3011];
int head[10011],nxt[10011],to[10011],tot;
int que[3011],qsz=0;
vector<int>mx1[3011],mx2[3011];
void bfs(int S)
{
	qsz=0;
	que[qsz++]=S;
	dis[S][S]=0;
	int mxdis=0;
	for(int i=0;i<qsz;i++)
	{
		int u=que[i];
		mxdis=max(mxdis,dis[S][u]);
		for(int i=head[u];i;i=nxt[i])
		{
			if(dis[S][to[i]]==-1)
			{
				dis[S][to[i]]=dis[S][u]+1;
				que[qsz++]=to[i];
			}
		}
	}
}
int main()
{
	getii(n,m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
	}
	memset(dis,-1,sizeof(dis));
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++)
	{
		int mxdis=0;
		for(int j=1;j<=n;j++)
		{
			mxdis=max(mxdis,dis[i][j]);
		}
		for(int t=0;t<3;t++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(dis[i][j]==mxdis-t)
				{
					mx1[i].PB(j);
				}
			}
		}
		mxdis=0;
		for(int j=1;j<=n;j++)
		{
			mxdis=max(mxdis,dis[j][i]);
		}
		for(int t=0;t<3;t++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(dis[j][i]==mxdis-t)
				{
					mx2[i].PB(j);
				}
			}
		}
	}
	int ans=0;
	pair<pair<int,int>,pair<int,int> > route;
	#define x1 orzusb
	#define y1 orzusbusb
	for(int x1=1;x1<=n;x1++)
	{
		for(int x2=1;x2<=n;x2++)
		{
			if(x1==x2||dis[x1][x2]==-1)continue;
			bool usb=0;
			if(x1==2&&x2==4)usb=1;
			int cnt=0;
			for(int i=0;i<mx2[x1].size();i++)
			{
				int y1=mx2[x1][i];
				if(y1!=x1&&y1!=x2)
				{
					for(int j=0;j<mx1[x2].size();j++)
					{
						int y2=mx1[x2][j];
						if(y2!=x1&&y2!=x2&&y2!=y1)
						{
							if(dis[y1][x1]==-1||dis[x2][y2]==-1)continue;
							int curdis=dis[x1][x2]+dis[y1][x1]+dis[x2][y2];
							if(curdis>ans)
							{
								ans=curdis;
								route=MP(MP(y1,x1),MP(x2,y2));
							}
							break;
						}
					}
					if(cnt>=1)break;
					cnt++;
				}
			}
		}
	}
	cout<<route.FF.FF<<" "<<route.FF.SS<<" "<<route.SS.FF<<" "<<route.SS.SS<<endl;
	return 0;
}