#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define mod 998244353
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 500500
    typedef long long ll;
    template<typename T>
    inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.')
        {
            ch=getchar();
            while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
        }
        t=(f?-t:t);
    }
    template<typename T,typename... Args>
    inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
    inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;

namespace tree
{

	int rt0,rt1;
	struct hh{int t,nxt;}edge[sz];
	int head[sz],ecnt;
	void make_edge(int f,int t)
	{
		edge[++ecnt]=(hh){t,head[f]};
		head[f]=ecnt;
		edge[++ecnt]=(hh){f,head[t]};
		head[t]=ecnt;
	}
	
	int w[sz],a[sz],id[sz],sum[sz],T;
	void dfs(int x,int fa)
	{
		if (a[x])
		{
			sum[id[x]=++T]=a[x];
			if (fa) sum[id[fa]]-=a[x];
			if (fa&&sum[id[fa]]<0) puts("-1"),exit(0);
		}
		else id[x]=id[fa];
		#define v edge[i].t
		go(x) if (v!=fa) dfs(v,x);
		#undef v
	}
	
	void init()
	{
		read(rt0,rt1);rt1+=n;
		int m,x,y;
		rep(i,1,n) read(w[i]);
		rep(i,1,n-1) read(x,y),make_edge(x,y);
		rep(i,1,n-1) read(x,y),make_edge(x+n,y+n);
		read(m);
		rep(i,1,m) read(x,y),a[x]=y;
		read(m);
		rep(i,1,m) read(x,y),a[x+n]=y;
		dfs(rt0,0);dfs(rt1,0);
	}
	
}
using tree::a;using tree::w;using tree::id;using tree::sum;

struct hh{int t,w,dis,nxt;}edge[sz];
int head[sz],ecnt=1;
void make_edge(int f,int t,int w,int dis)
{
	edge[++ecnt]=(hh){t,w,dis,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,0,-dis,head[t]};
	head[t]=ecnt;
}

int pre[sz],dis[sz],flow[sz];
bool in[sz];
int S,T;
bool SPFA()
{
	queue<int>q;
    memset(dis,~0x3f,sizeof(dis));
    q.push(S);
    dis[S]=0;in[S]=1;
    flow[S]=INT_MAX;
    while (!q.empty())
    {
    	int x=q.front();q.pop();in[x]=0;
    	#define v edge[i].t
    	go(x) if (dis[v]<dis[x]+edge[i].dis&&edge[i].w>0)
    	{
    		dis[v]=dis[x]+edge[i].dis;
    		pre[v]=i;
    		flow[v]=min(flow[x],edge[i].w);
    		if (!in[v]) q.push(v);
    		in[v]=1;
    	}
    	#undef v
    }
	return dis[T]!=dis[0];
}
int L,R;
void build()
{
	S=n*2+1;T=S+1;
	rep(i,1,n) if (a[i]) {make_edge(S,id[i],sum[id[i]],0);L+=sum[id[i]];}
	rep(i,n+1,n<<1) if (a[i]) {make_edge(id[i],T,sum[id[i]],0);R+=sum[id[i]];}
	rep(i,1,n) 
		make_edge(id[i],id[i+n],1,w[i]);
}
int ans,mxflow;
void update(){mxflow+=flow[T];ans+=flow[T]*dis[T];for (int x=T,y;(y=pre[x],x!=S);x=edge[y^1].t) edge[y].w-=flow[T],edge[y^1].w+=flow[T];}
void MCF(){build();while (SPFA()) update();}
int main()
{
	file();
	read(n);
	tree::init();
	MCF();
	printf("%d",L==R&&L==mxflow?ans:-1);
}