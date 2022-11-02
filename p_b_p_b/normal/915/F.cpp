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
    #define sz 1010101
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

int fa[sz],size[sz];
bool vis[sz];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void init(){rep(i,1,n) fa[i]=i,vis[i]=0,size[i]=1;}
ll c[sz];
int id[sz];

ll solve()
{
    init();
    ll ret=0;
    rep(i,1,n)
    {
        int x=id[i];vis[x]=1;ret+=c[x];
        #define v edge[i].t
        go(x) if (vis[v])
        {
            int y=getfa(v);
            ret+=1ll*size[y]*size[x]*c[x];
            size[x]+=size[y];fa[y]=x;
        }
        #undef v
    }
    return ret;
}

inline bool cmp(const int &x,const int &y){return c[x]>c[y];}

int main()
{
    file();
    int x,y;
    read(n);
    rep(i,1,n) read(c[i]);
    rep(i,1,n-1) read(x,y),make_edge(x,y);
    rep(i,1,n) id[i]=i;
    sort(id+1,id+n+1,cmp);
    ll mn=solve();
    reverse(id+1,id+n+1);
    ll mx=solve();
    cout<<mx-mn;
    return 0;
}