// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=1111;
const int maxm=100111;

struct max_flow
{
	struct edge{int to;LL cap;};
	int head[maxn],nxt[maxm<<1],iter[maxn],tot;
	edge e[maxm<<1];
	void clear()
	{
		memset(head,0,sizeof(head));
		tot=1;
	}
	max_flow(){clear();}
	void addedge(int u,int v,LL cap)
	{
		nxt[++tot]=head[u];
		head[u]=tot;
		e[tot]=edge{v,cap};
		nxt[++tot]=head[v];
		head[v]=tot;
		e[tot]=edge{u,0};
	}
	
	int lvl[maxn],q[maxn];
	bool bfs(int s,int t)
	{
		memset(lvl,-1,sizeof(lvl));
		lvl[s]=0;int rr=0;q[rr++]=s;
		for(int fr=0;fr<rr;fr++)
		{
			int x=q[fr];if(x==t)return true;
			for(int i=head[x];i;i=nxt[i])if(e[i].cap&&lvl[e[i].to]==-1)
			{
				lvl[e[i].to]=lvl[x]+1;
				q[rr++]=e[i].to;
			}
		}
		return false;
	}
	LL dfs(int x,int t,LL f)
	{
		if(x==t||f==0)return f;
		int ret=0;
		for(int&i=iter[x];i;i=nxt[i])if(e[i].cap&&lvl[e[i].to]==lvl[x]+1)
		{
			LL d=dfs(e[i].to,t,min(f,e[i].cap));
			e[i].cap-=d;e[i^1].cap+=d;
			f-=d;ret+=d;
			if(!f)break;
		}
		return ret;
	}
	LL maxflow(int s,int t)
	{
		LL flow=0;
		while(bfs(s,t))
		{
			memcpy(iter,head,sizeof(head));
			flow+=dfs(s,t,Linf);
		}
		return flow;
	}
}thor;

int n,m,x[55],y[55],xx[55],yy[55];
bool have[111][111];

int main()
{
	get2(n,m);
	vector<int> vx,vy;vx.pb(1);vx.pb(n+1);vy.pb(1);vy.pb(n+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",x+i,y+i,xx+i,yy+i);
		xx[i]++;yy[i]++;
		vx.pb(x[i]);vx.pb(xx[i]);
		vy.pb(y[i]);vy.pb(yy[i]);
	}
	sort(vx.begin(),vx.end());vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());vy.erase(unique(vy.begin(),vy.end()),vy.end());
	int W=(int)vx.size()-1,H=(int)vy.size()-1;
	for(int i=1;i<=m;i++)
	{
		x[i]=lower_bound(vx.begin(),vx.end(),x[i])-vx.begin()+1;
		y[i]=lower_bound(vy.begin(),vy.end(),y[i])-vy.begin()+1;
		xx[i]=lower_bound(vx.begin(),vx.end(),xx[i])-vx.begin()+1;
		yy[i]=lower_bound(vy.begin(),vy.end(),yy[i])-vy.begin()+1;
		for(int j=x[i];j<xx[i];j++)for(int k=y[i];k<yy[i];k++)have[j][k]=1;
	}
	int S=W+H+1,T=S+1;
	for(int i=1;i<=W;i++)for(int j=1;j<=H;j++)if(have[i][j])
		thor.addedge(i,j+W,1ll*(vx[i]-vx[i-1])*(vy[j]-vy[j-1]));
	for(int i=1;i<=W;i++)thor.addedge(S,i,vx[i]-vx[i-1]);
	for(int j=1;j<=H;j++)thor.addedge(j+W,T,vy[j]-vy[j-1]);
	printf("%lld\n",thor.maxflow(S,T));
	return 0;
}