#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}

int from[MAXN];
struct node
{
	int u;ll dis;
	node(){}
	node(int u,ll dis):u(u),dis(dis) {}
	bool operator< (const node& you)const{return dis>you.dis;}
};
std::priority_queue<node>q;
ll dis[MAXN],f[MAXN];
int main()
{
	int n=read(),m=read(),L=read(),S=read(),T=read();
	for(int i=1;i<=m;++i){int u=read(),v=read(),w=read();adde(u,v,w),adde(v,u,w);}
	//
	memset(dis,0x3f,sizeof dis);
	dis[T]=0,q.push(node(T,0));
	while(q.size())
	{
		node tp=q.top();q.pop();
		int u=tp.u;ll tmp=tp.dis;
		if(dis[u]!=tmp)continue;
		for(int i=last[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w?e[i].w:1;
			if(umin(dis[v],dis[u]+w))q.push(node(v,dis[v]));
		}
	}
	memset(f,0x3f,sizeof f);
	f[S]=0,q.push(node(S,0));
	while(q.size())
	{
		node tp=q.top();q.pop();
		int u=tp.u;ll tmp=tp.dis;
		if(f[u]!=tmp)continue;
		for(int i=last[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w= e[i].w?e[i].w:max(1,L-dis[v]-f[u]);
			if(umin(f[v],f[u]+w))
			{
				q.push(node(v,f[v])),e[i].w=e[i^1].w=w;
			}
		}
	}
	if(f[T]!=L){puts("NO");return 0;}
	puts("YES");
	for(int i=1;i<=m;++i)printf("%d %d %d\n",e[i<<1|1].v,e[i<<1].v,e[i<<1].w?e[i<<1].w:L+1);
	return 0;
}