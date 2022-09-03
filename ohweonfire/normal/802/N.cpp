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
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=5011;
const int maxm=5000111;

struct mincost_flow
{
	struct edge{int to,cap,cost;};
	int head[maxn],nxt[maxm<<1],iter[maxn],tot=1;
	edge e[maxm<<1];
	void addedge(int u,int v,int cap,int cost)
	{
//		printf("addedge %d %d %d %d\n",u,v,cap,cost);
		nxt[++tot]=head[u];
		head[u]=tot;
		e[tot]=edge{v,cap,cost};
		nxt[++tot]=head[v];
		head[v]=tot;
		e[tot]=edge{u,0,-cost};
	}
	bool inq[maxn];int q[maxn],pre[maxn];
	LL dist[maxn];
	void spfa(int s)
	{
		for(int i=0;i<maxn;i++)dist[i]=Linf;
		dist[s]=0;int fr=0,rr=0;q[rr++]=s;
		while(fr!=rr)
		{
			int x=q[fr++];if(fr==maxn)fr=0;
			inq[x]=0;
			for(int i=head[x];i;i=nxt[i])if(e[i].cap&&dist[e[i].to]>dist[x]+e[i].cost)
			{
				dist[e[i].to]=dist[x]+e[i].cost;
				pre[e[i].to]=i;
				if(!inq[e[i].to])
				{
					inq[e[i].to]=1;
					if(fr==rr||dist[q[fr]]<=dist[e[i].to])
					{
						q[rr++]=e[i].to;
						if(rr==maxn)rr=0;
					}
					else
					{
						if(fr==0)fr=maxn;
						q[--fr]=e[i].to;
					}
				}
			}
		}
	}
	LL augment(int t,int s,int&f)
	{
		int d=f,cur;
		for(cur=t;cur!=s;cur=e[pre[cur]^1].to)d=min(d,e[pre[cur]].cap);
		f-=d;
		for(cur=t;cur!=s;cur=e[pre[cur]^1].to)
		{
			e[pre[cur]].cap-=d;
			e[pre[cur]^1].cap+=d;
		}
		return dist[t]*d;
	}
	LL mincostflow(int s,int t,int f)
	{
		LL ret=0;
		while(f)
		{
			spfa(s);
			if(dist[t]==inf)return -1;
			ret+=augment(t,s,f);
		}
		return ret;
	}
}thor;

int nn,a[2211],b[2211];
int main()
{
	int k;
	scanf("%d%d",&nn,&k);
	for(int i=1;i<=nn;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=nn;i++)
		scanf("%d",&b[i]);
	int S=nn+1,T=S+1;
	for(int i=1;i<=nn;i++)
	{
		thor.addedge(S,i,1,a[i]);
		thor.addedge(i,T,1,b[i]);
	}
	for(int i=1;i<nn;i++)thor.addedge(i,i+1,k,0);
	cout<<thor.mincostflow(S,T,k)<<endl;
	return 0;
}