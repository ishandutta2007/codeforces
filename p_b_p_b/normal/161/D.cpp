#include<bits/stdc++.h>
#define sz 100020
#define mod 998244353
using namespace std;
typedef long long ll;
struct FastIO{
    inline FastIO& operator>>(int& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
    {
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
    {
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
            while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file(){
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n,K;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define v edge[i].t
int root;
int size[sz],sum,mn;
bool vis[sz];
void Getroot(int x,int fa)
{
	size[x]=1;int cur=0;
	go(x) if (v!=fa&&!vis[v]) { Getroot(v,x); size[x]+=size[v]; cur=max(cur,size[v]); }
	cur=max(size[x],sum-size[x]);
	if (cur<mn) mn=cur,root=x;
}
void getroot(int x){root=-1;sum=mn=size[x];Getroot(x,0);}
int cnt[sz];
ll ans;
int p[sz],c;
int q[sz],cc;
void getdis(int x,int fa,int d)
{
	p[++c]=d;
	go(x) if (v!=fa&&!vis[v]) getdis(v,x,d+1);
}
void getans(int x)
{
	cnt[0]=1;
	go(x) if (!vis[v])
	{
		getdis(v,0,1);
		for (int j=1;j<=c;j++) if (p[j]<=K) ans+=cnt[K-p[j]];
		for (int j=1;j<=c;j++) cnt[p[j]]++,q[++cc]=p[j];
		c=0;
	}
	for (int i=1;i<=cc;i++) cnt[q[i]]=0;
	cnt[0]=0;cc=0;
}
void dfs(int x)
{
	vis[x]=1;getans(x);
	go(x) if (!vis[v])
	{
		getroot(v);
		dfs(root);
	} 
}
int main()
{
	file();
	int i,x,y;
	read>>n>>K;
	for (i=1;i<n;i++) read>>x>>y,make_edge(x,y);
	getroot(1);
	dfs(1);
	cout<<ans;
}