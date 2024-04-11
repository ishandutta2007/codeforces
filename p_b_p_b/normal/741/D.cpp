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
struct hh{int t,nxt,c;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t,int c)
{
	edge[++ecnt]=(hh){t,head[f],c};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t],c};
	head[t]=ecnt;
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define v edge[i].t
int size[sz],son[sz],dep[sz],D[sz];
void dfs1(int x,int fa)
{
	size[x]=1;dep[x]=dep[fa]+1;
	go(x) if (v!=fa)
	{
		D[v]=D[x]^(1<<edge[i].c);
		dfs1(v,x);
		size[x]+=size[v];
		if (size[v]>size[son[x]]) son[x]=v;
	}
}
int ans[sz];
int mx[1<<23],now;
void chkmax(int &x,int y){x=max(x,y);}
void add(int x,int fa,int t)
{
	if (t==1) chkmax(mx[D[x]],dep[x]);
	else mx[D[x]]=0;
	go(x) if (v!=fa) add(v,x,t);
}
int cur_ans;
void get_ans(int x,int fa)
{
	if (mx[D[x]]) chkmax(cur_ans,dep[x]+mx[D[x]]-now);
	for (int i=0;i<22;i++) if (mx[D[x]^(1<<i)]) chkmax(cur_ans,dep[x]+mx[D[x]^(1<<i)]-now);
	go(x) if (v!=fa) get_ans(v,x);
}
void dfs2(int x,int fa,bool keep)
{
	int ret=0;
	go(x) if (v!=son[x]&&v!=fa) { dfs2(v,x,0); chkmax(ret,ans[v]); }
	if (son[x]) { dfs2(son[x],x,1); chkmax(ret,ans[son[x]]); }
	cur_ans=0;now=dep[x]<<1;
	go(x) 
		if (v!=fa&&v!=son[x]) 
		{ 
			get_ans(v,x); 
			add(v,x,1); 
		}
	chkmax(cur_ans,mx[D[x]]-dep[x]);
	for (int i=0;i<22;i++) if (mx[D[x]^(1<<i)]) chkmax(cur_ans,mx[D[x]^(1<<i)]-dep[x]);
	chkmax(mx[D[x]],dep[x]);
	ans[x]=max(cur_ans,ret);
	if (!keep) add(x,fa,-1);
}
int main()
{
	file();
	int i,x;
	read>>n;
	char ccc;
	for (i=2;i<=n;i++) read>>x,cin>>ccc,make_edge(x,i,ccc-'a');
	dfs1(1,0);dfs2(1,0,1);
	for (i=1;i<=n;i++) printf("%d ",ans[i]);
}