#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
#define ll long long
#define inf 1000000000
#define re register
struct po
{
    int from,to,dis,nxt,w;
}edge[250001];
int head[250001],cur[1000001],dep[60001],n,m,s,t,u,num=-1,x,y,l,tot,sum,k,fa[10001];
int dis[5001],b[5001],xb[5001],flow[5001];
inline void add_edge(int from,int to,int w,int dis)
{
    edge[++num].nxt=head[from];
    edge[num].from=from;
    edge[num].to=to;
    edge[num].w=w;
    edge[num].dis=dis;
    head[from]=num;
}
inline void add(int from,int to,int w,int dis)
{
    add_edge(from,to,w,dis);
    add_edge(to,from,0,-dis);
}
inline bool bfs()
{
    memset(dis,100,sizeof(dis));
    memset(b,0,sizeof(b));
    queue<int> q;
    while(!q.empty())
    q.pop();
    for(re int i=1;i<=n;i++)
    {
        fa[i]=-1;
    }
    b[s]=1;dis[s]=0;fa[s]=0;
    flow[s]=inf;q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        b[u]=0;
        for(re int i=head[u];i!=-1;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(edge[i].w>0&&dis[v]>dis[u]+edge[i].dis)
            {
                dis[v]=dis[u]+edge[i].dis;
                fa[v]=u;
                xb[v]=i;
                flow[v]=min(flow[u],edge[i].w);
                if(!b[v]){b[v]=1,q.push(v);}
            }
        }
    }
    return dis[t]<inf;
}
vector<int> V;
vector<int> S;
inline void max_flow()
{
    while(bfs())
    {
        int k=t;
        while(k!=s)
        {
            edge[xb[k]].w-=flow[t];
            edge[xb[k]^1].w+=flow[t];
            k=fa[k];
        }
        tot+=flow[t];
        for (int i=0;i<flow[t];i++) V.pb(dis[t]);
        sum+=flow[t]*dis[t];
    }
}
int main()
{
    memset(head,-1,sizeof(head));
    n=read();m=read();s=1;t=n;
    for(re int i=1;i<=m;i++)
    {
        x=read();y=read();l=1;
        int d=read();
        add(x,y,l,d);
    }
    max_flow();
    S.resize(V.size());
    S[0]=V[0];
    for (int i=1;i<V.size();i++) S[i]=S[i-1]+V[i];
    int q=read();
    while (q--){
    	int x;
    	x=read();
    	int lo=0,hi=V.size();
    	while (hi-lo>1){
    		int mid=lo+hi>>1;
    		if (S[mid-1]+x>=V[mid]*(mid)) lo=mid;
    		else hi=mid;
		}
		int tmp=(lo==0)?0:(V[lo]*(lo)-S[lo-1]);
		x-=tmp;
	//	cerr<<"FUCK"<<' '<<x<<' '<<tmp<<' '<<lo<<endl;
		double ans=V[lo]+(double)x/(lo+1);
		printf("%.10lf\n",ans);
	}
	return 0;
}