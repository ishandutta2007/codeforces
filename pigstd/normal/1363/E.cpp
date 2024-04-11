#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define pb push_back
#define maxn 200005
int n,res;
struct edge{
	int to,nxt;
}e[maxn<<1];
int tot,head[maxn];
inline void adde(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}
int a[maxn],sum1,sum2;
bool t1[maxn],t2[maxn];
vector<int>v0,v1;

int fa[maxn],val[maxn],sz0[maxn],sz1[maxn];
void dfs(int u)
{
	val[u]=a[u];
	if(fa[u])val[u]=min(a[u],val[fa[u]]);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
		sz0[u]+=sz0[v],sz1[u]+=sz1[v];
	}
	int mn=min(sz0[u],sz1[u]);
	res+=val[u]*mn;
	sz0[u]-=mn,sz1[u]-=mn;
}

signed main()
{
	n=read();
	For(i,1,n){
		a[i]=read(),t1[i]=read(),t2[i]=read();
		if(t1[i]&&!t2[i])v1.pb(i),sz1[i]++;
		if(!t1[i]&&t2[i])v0.pb(i),sz0[i]++;
		sum1+=t1[i],sum2+=t2[i];
	}
	if(sum1!=sum2){puts("-1");return 0;}
	For(i,2,n){
		int u=read(),v=read();
		adde(u,v);adde(v,u);
	}
	dfs(1);
	cout<<res*2;
    return 0;
}