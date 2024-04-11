#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	 ll x=0;bool f=0;char c=getchar();
	 while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	 while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	 return f?-x:x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 1200011;
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}

struct node
{
	int u,dis;
	node(){}
	node(int u,int dis):u(u),dis(dis){}
	bool operator< (const node& you)const{return dis>you.dis;}
};
std::priority_queue<node>q;
int dis[MAXN],pre[MAXN];
void Dij(int s)
{
	memset(dis,0x3f,sizeof dis);
	dis[s]=0,q.push(node(s,0));
	while(q.size())
	{
		node tp=q.top();q.pop();
		int u=tp.u;
		if(dis[u]!=tp.dis)continue;
		for(int i=last[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(umin(dis[v],dis[u]+e[i].w))pre[v]=u,q.push(node(v,dis[v]));
		}
	}
}
int a[MAXN];
int main()
{
	int n=read(),L = n+1;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		adde(i,L+i-a[i],1),adde(L+i-1,L+i,0);
	}
	for(int i=1;i<=n;++i)
	{
		int x=read();
		adde(L+i,i+x,0);
	}
	Dij(n);
	if(dis[L]>int(1e8))
	{
		puts("-1");return 0;
	}
	printf("%d\n",dis[L]);
	std::vector<int>res;
	int u=L;
	while(u!=n)
	{
		res.push_back(u-L);
		while(u>=L)u=pre[u];
		if(u==n)break;
		u=pre[u];
	}
	std::reverse(res.begin(),res.end());
	for(auto x:res)printf("%d ",x);
	puts("");
	return 0;
}