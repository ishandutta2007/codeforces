#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 202020
    typedef long long ll;
    template<typename T>
    inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.')
        {
            ch=getchar();
            while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();
        }
        t=(f?-t:t);
    }
    template<typename T,typename... Args>
    inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m,Q;
map<pii,int>M;
struct hh{int f,t,w;hh(int ff=0,int tt=0,int ww=0){f=ff,t=tt,w=ww;}}edge[sz<<1];
int bg[sz<<1],ed[sz<<1];

struct HH
{
    int w[34];
    void ins(int x)
    {
        drep(i,30,0) if (x&(1<<i))
        {
            if (!w[i]) { w[i]=x; return; }
            x^=w[i];
        }
    }
    int query(int x){ drep(i,30,0) if ((x^w[i])<x) x^=w[i]; return x; }
}_;

vector<hh>v[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void insert(int k,int l,int r,int x,int y,hh e)
{
    if (x<=l&&r<=y) return (void)v[k].push_back(e);
    int mid=(l+r)>>1;
    if (x<=mid) insert(lson,x,y,e);
    if (y>mid) insert(rson,x,y,e);
}
int qx[sz],qy[sz];
int fa[sz],f[sz],dep[sz];
int getfa(int x){return x==fa[x]?x:getfa(fa[x]);}
int getdis(int x){return x==fa[x]?0:f[x]^getdis(fa[x]);}
struct hhh{int x,y;bool s;};
void solve(int k,int l,int r,HH G)
{
    stack<hhh>S;
    rep(i,0,(int)v[k].size()-1)
    {
        int x=v[k][i].f,y=v[k][i].t,w=v[k][i].w;
        int fx=getfa(x),fy=getfa(y);
        w^=getdis(x)^getdis(y);
        if (fx==fy) G.ins(w);
        else
        {
            if (dep[fx]>dep[fy]) swap(fx,fy),swap(x,y);
            hhh cur=(hhh){fx,fy,0};
            fa[fx]=fy;f[fx]=w;
            if (dep[fx]==dep[fy]) ++dep[fy],cur.s=1;
            S.push(cur);
        }
    }
    if (l==r) printf("%d\n",G.query(getdis(qx[l])^getdis(qy[l])));
    else
    {
        int mid=(l+r)>>1;
        solve(lson,G);solve(rson,G);
    }
    while (!S.empty()) f[fa[S.top().x]=S.top().x]=0,dep[S.top().y]-=S.top().s,S.pop();
}

int main()
{
    file();
    int x,y,z;
    read(n,m);
    rep(i,1,n) fa[i]=i;
    int c=m,tim=1;
    rep(i,1,m) read(x,y,z),M[MP(x,y)]=i,bg[i]=1,ed[i]=-1,edge[i]=hh(x,y,z);
    read(Q);
    rep(i,1,Q)
    {
        read(z,x,y);
        if (z==1)
        {
            read(z);
            M[MP(x,y)]=++c;bg[c]=tim;ed[c]=-1;
            edge[c]=hh(x,y,z);
        }
        else if (z==2) ed[M[MP(x,y)]]=tim-1;
        else qx[tim]=x,qy[tim]=y,++tim;
    }
    --tim;
    rep(i,1,c) if (ed[i]==-1) ed[i]=tim;
    rep(i,1,c) if (bg[i]<=ed[i]) insert(1,1,tim,bg[i],ed[i],edge[i]);
    solve(1,1,tim,_);
    return 0;
}