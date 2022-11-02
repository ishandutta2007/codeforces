#include<bits/stdc++.h>
#define sz 1000020
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
int n;
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
int fa[sz][20],dep[sz],size[sz],son[sz];
void upd(int x){for (int i=1;i<20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];}
void dfs1(int x,int f)
{
	dep[x]=dep[fa[x][0]=f]+1;size[x]=1;upd(x);
	go(x) if (v!=f)
	{
		dfs1(v,x);
		size[x]+=size[v];
		if (size[v]>size[son[x]]) son[x]=v;
	}
}
int getfa(int x,int k)
{
	if (k>=dep[x]) return -1;
	for (int i=0;i<20;i++) if (k&(1<<i)) x=fa[x][i];
	return x;
}
int sum[sz];
bool s[sz];
void add(int x,int fa,int t)
{
	sum[dep[x]]+=t;
	go(x) if (v!=fa&&!s[v]) add(v,x,t);
}
#define pii pair<int,int>
#define MP make_pair
#define fir first
#define sec second
vector<pii>q[sz];
int ans[sz];
bool vis[sz];
void dfs2(int x,int fa,bool keep)
{
	vis[x]=1;
	go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,0);
	s[son[x]]=1;
	if (son[x]) dfs2(son[x],x,1);
	add(x,fa,1);
	for (int i=0;i<q[x].size();i++) ans[q[x][i].fir]=sum[q[x][i].sec];
	s[son[x]]=0;
	if (!keep) add(x,fa,-1); 
}
int main()
{
	file();
	int i,j,k,x,y,z,m;
	read>>n;
	for (i=1;i<=n;i++) { read>>x; if (x) make_edge(x,i); }
	for (i=1;i<=n;i++) if (!size[i]) dfs1(i,0);
	read>>m;
	for (i=1;i<=m;i++)
	{
		read>>x>>y;
		if ((z=getfa(x,y))!=-1) q[z].push_back(MP(i,dep[x]));
		else ans[i]=1;
	}
	for (i=1;i<=n;i++) if (!fa[i][0]) dfs2(i,0,0);
	for (i=1;i<=m;i++) printf("%d ",ans[i]-1);
}