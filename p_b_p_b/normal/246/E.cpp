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
int dep[sz],size[sz],son[sz],fa[sz];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;size[x]=1;
	go(x) if (v!=fa)
	{
		dfs1(v,x);
		size[x]+=size[v];
		if (size[v]>size[son[x]]) son[x]=v;
	}
}
map<string,int>S[sz];
int sum[sz];
string a[sz];
bool s[sz];
void add(string s,int d,int t)
{
	if (!S[d][s]) ++sum[d];
	S[d][s]+=t;
	if (!S[d][s]) --sum[d];
}
void add(int x,int fa,int t)
{
	add(a[x],dep[x],t);
	go(x) if (v!=fa&&!s[v]) add(v,x,t);
}
#define pii pair<int,int>
#define MP make_pair
#define fir first
#define sec second
vector<pii>q[sz];
int ans[sz];
void dfs2(int x,int fa,bool keep)
{
	go(x) if (v!=fa&&v!=son[x]) dfs2(v,x,0);
	s[son[x]]=1;
	if (son[x]) dfs2(son[x],x,1);
	add(x,fa,1);
	for (int i=0;i<(int)q[x].size();i++) ans[q[x][i].fir]=sum[q[x][i].sec];
	s[son[x]]=0;
	if (!keep) add(x,fa,-1); 
}
int main()
{
	file();
	int i,x,y,m;
	read>>n;
	for (i=1;i<=n;i++) { cin>>a[i]; read>>fa[i]; if (x=fa[i]) make_edge(x,i); }
	for (i=1;i<=n;i++) if (!fa[i]) dfs1(i,0);
	read>>m;
	for (i=1;i<=m;i++)
	{
		read>>x>>y;
		q[x].push_back(MP(i,dep[x]+y));
	}
	for (i=1;i<=n;i++) if (!fa[i]) dfs2(i,0,0);
	for (i=1;i<=m;i++) printf("%d\n",ans[i]);
}