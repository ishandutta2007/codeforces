#include<bits/stdc++.h>
#define sz 400020
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO
{
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
void file()
{
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void chkmin(int &x,int y){x=min(x,y);}
namespace LCT
{
    #define ls ch[x][0]
    #define rs ch[x][1]
    int fa[sz],ch[sz][2],tag[sz];
	int w[sz],maxv[sz],mv[sz],ans[sz];//self, all, tag, current ans
    void pushdown(int x)
    {
        if (tag[x])
        {
            tag[x]=0;
            if (ls) tag[ls]^=1;
            if (rs) tag[rs]^=1;
            swap(ls,rs);
        }
        if (mv[x]!=-1)
        {
        	int &t=mv[x];
        	if (ls) chkmin(ans[ls],t);if (rs) chkmin(ans[rs],t);
        	if (ls&&(mv[ls]==-1||mv[ls]>t)) mv[ls]=t;
        	if (rs&&(mv[rs]==-1||mv[rs]>t)) mv[rs]=t;
        	t=-1;
        }
    }
    void pushup(int x){maxv[x]=max(w[x],max(maxv[ls],maxv[rs]));}
    bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
    void rotate(int x)
    {
        int y=fa[x],z=fa[y],k=ch[y][1]==x,w=ch[x][!k];
    	if(nroot(y)) ch[z][ch[z][1]==y]=x;
        ch[x][!k]=y;
        ch[y][k]=w;
    	if(w) fa[w]=y;
        fa[y]=x;
        fa[x]=z;
    	pushup(y);pushup(x);
    };
	int st[sz];
    void splay(int x)
    {
        int cnt=1;
        st[cnt]=x;
        for(int i=x;nroot(i);i=fa[i])st[++cnt]=fa[i];
        for(int i=cnt;i;i--) pushdown(st[i]);
        while(nroot(x))
        {
            int y=fa[x],z=fa[y];
            if(nroot(y)) rotate((ch[y][0]==x)^(ch[z][0]==y)?x:y);
            rotate(x);
        }
    }
    void access(int x)
    {
        for (int y=0;x;y=x,x=fa[x])
        {
            splay(x);
            ch[x][1]=y;
            pushup(x);
        }
    }
    void makeroot(int x){access(x);splay(x);tag[x]^=1;}
    int findroot(int x)
    {
        access(x);splay(x);
        while (ls) pushdown(x),x=ls;
        return x;
    }
    bool sameroot(int x,int y){makeroot(x);return findroot(y)==x;}
    void getroad(int x,int y){makeroot(x);access(y);splay(y);}
    void link(int x,int y){makeroot(x);fa[x]=y;}
    #undef ls
    #undef rs
}
using namespace LCT;
int n,m;
struct hh{int f,t,w,id,ans;}edge[sz];
inline bool cmp(const hh &x,const hh &y){return x.w<y.w;}
inline bool cmpOut(const hh &x,const hh &y){return x.id<y.id;}
bool in[sz];
int main()
{
	file();
	memset(mv,-1,sizeof(mv));
	int i,j,k,x,y,z;
	read>>n>>m;
	for (i=1;i<=m;i++) read>>x>>y>>z,edge[i]=(hh){x,y,z,i,0};
	sort(edge+1,edge+m+1,cmp);
	for (i=1;i<=m;i++)
	{
		x=edge[i].f;y=edge[i].t;
		if (sameroot(x,y))
		{
			getroad(x,y);
			edge[i].ans=maxv[y];
			if (mv[y]!=-1) chkmin(mv[y],edge[i].w);
			else mv[y]=edge[i].w;
//			chkmin(ans[y],mv[y]);
		}
		else
		{
			z=edge[i].id+n;
			maxv[z]=w[z]=edge[i].w;ans[z]=1e9+233;
			link(x,z);link(y,z);
			in[z-n]=1;
		}
	}
	sort(edge+1,edge+m+1,cmpOut);
	for (i=1;i<=m;i++)
	{
		if (!in[i]) printf("%d ",edge[i].ans-1);
		else
		{
			makeroot(i+n);
			printf("%d ",ans[i+n]>1e9?-1:ans[i+n]-1);
		}
	}
}