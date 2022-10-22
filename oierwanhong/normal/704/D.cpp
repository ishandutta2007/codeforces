#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 3000011;
const ll LINF = 1.233e18;
namespace Flow
{
	struct edge{int v,nxt;ll w;}e[MAXN<<1|1];
	int cnt=1,last[MAXN],cur[MAXN];
	void add_single_edge(int u,int v,ll w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
	void adde(int u,int v,ll w)
	{
		//printf("Addedge %d %d %lld\n",u,v,w);
		add_single_edge(u,v,w),add_single_edge(v,u,0);
	}
	void clear(){cnt=1;memset(last,0,sizeof last);}
	int Q[MAXN],dep[MAXN];
	bool bfs(int st,int ed,int n)
	{
		for(int i=1;i<=n;++i)cur[i]=last[i],dep[i]=0;
		int h=0,t=0;
		Q[t++]=st,dep[st]=1;
		while(h<t)
		{
			int u=Q[h++];
			for(int i=last[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				if(e[i].w&&!dep[v])
				{
					dep[v]=dep[u]+1,Q[t++]=v;
					if(v==ed)return 1;
				}
			}
		}
		return 0;
	}
	ll ex_flow(int u,int t,ll flow=LINF)
	{
		if(u==t)return flow;
		ll f=0;
		for(int &i=cur[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].w&&dep[v]==dep[u]+1)
			{
				ll tmp=ex_flow(v,t,min(e[i].w,flow-f));
				e[i].w-=tmp,e[i^1].w+=tmp;
				f+=tmp;
				if(f==flow)return f;
			}
		}
		return f;
	}
	ll Dinic(int st,int ed,int n)
	{
		ll res=0;
		while(bfs(st,ed,n))res+=ex_flow(st,ed);
		return res;
	}
}

int fx[MAXN],diff=0;
pii a[MAXN];
int place(int val){return std::lower_bound(fx+1,fx+diff+1,val)-fx;}

int S,T,ss,tt;
int deg[MAXN];
ll lims=0;
void Addedge(int u,int v,ll low,ll up)
{
	//printf("Addedge %d %d [%lld,%lld]\n",u,v,low,up);
	if(low>up){puts("-1");exit(0);}
	if(!low)Flow::adde(u,v,up);
	else lims+=low,Flow::adde(u,v,up-low),Flow::adde(u,T,low),Flow::adde(S,v,low);
}

ll force[MAXN];
char way[MAXN];
int main()
{
	int n=read(),m=read();
	int r=read(),b=read();
	for(int i=1;i<=n;++i)fx[++diff]=a[i].first=read(),fx[++diff]=a[i].second=read();
	std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
	for(int i=1;i<=n;++i)a[i].first=place(a[i].first),a[i].second=diff+place(a[i].second);
	ss=diff*2+1,tt=ss+1;
	S=tt+1,T=S+1;
	//printf("Diff=%d\n",diff);
		//use red at first
		for(int i=1;i<=n;++i)
		{
			Addedge(a[i].first,a[i].second,0,1);
			++deg[a[i].first],++deg[a[i].second];
		}
		for(int i=1;i<=diff;++i)force[i]=force[diff+i]=LINF;// Addedge(ss,i,0,LINF),Addedge(diff+i,tt,0,LINF);
		Addedge(tt,ss,0,LINF);
		for(int i=1;i<=m;++i)
		{
			int op=read(),x=read();
			ll k=read();
			int p=place(x);
			if(fx[p]!=x)continue;
			//printf("Consider op=%d,x=%d,k=%lld\n",op,x,k);
			if(op==1)
			{
				umin(force[p],k);
			}
			else
			{
				umin(force[diff+p],k);
			}
		}
		for(int u=1;u<=diff;++u)Addedge(ss,u,max((deg[u]-force[u]+1)/2,0),(deg[u]+force[u])/2);
		for(int u=diff+1;u<=2*diff;++u)
		{
			//printf("Force[%d]=%d\n",u,force[u]);
			Addedge(u,tt,max((deg[u]-force[u]+1)/2,0),(deg[u]+force[u])/2);
		}

		ll res=Flow::Dinic(S,T,T);
		if(res<lims)puts("-1");
		else
		{
			res=Flow::Dinic(ss,tt,T);
			if(r>=b)
			{
				printf("%lld\n",ll(n-res)*r+ll(res)*b);
				for(int i=1;i<=n;++i)way[i]='r';
				for(int u=1;u<=diff;++u)
					for(int i=Flow::last[u];i;i=Flow::e[i].nxt)
					{
						int v=Flow::e[i].v;
						if(diff<v&&v<=diff*2&&!Flow::e[i].w)
						{
							way[i>>1]='b';
						}
					}
				puts(way+1);
			}
			else
			{
				printf("%lld\n",ll(res)*r+ll(n-res)*b);
				for(int i=1;i<=n;++i)way[i]='b';
				for(int u=1;u<=diff;++u)
					for(int i=Flow::last[u];i;i=Flow::e[i].nxt)
					{
						int v=Flow::e[i].v;
						if(diff<v&&v<=diff*2&&!Flow::e[i].w)
						{
							way[i>>1]='r';
						}
					}
				puts(way+1);
			}
		}
	return 0;
}