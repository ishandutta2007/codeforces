#include<bits/stdc++.h>
#define sz 201010
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
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,head[t]};
    head[t]=ecnt;
}
ll dn[3][sz],up[3][sz];
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define o edge[i].t
void dfs(int x,int fa)
{
    dn[2][x]=1;
    go(x) if (o!=fa)
    {
        dfs(o,x);
        dn[1][x]+=dn[2][o],dn[2][x]+=dn[1][o],dn[0][x]+=dn[0][o]+dn[2][o];
    }
}
void dfs_(int x,int fa)
{
//	up[2][x]++;
    go(x) if (o!=fa)
    {
        up[1][o]=up[2][x]+dn[2][x]-dn[1][o];
        up[2][o]=up[1][x]+dn[1][x]-dn[2][o];
        up[0][o]=up[0][x]+up[2][x]+1 + dn[0][x]-dn[0][o]-dn[2][o]+dn[2][x]-dn[1][o]-1;
        dfs_(o,x);
    }
}
int main()
{
    file();
    int n,i,j,k,x,y,z;
    ll ans=0;
    read>>n;
    for (i=1;i<n;i++) read>>x>>y,make_edge(x,y);
    dfs(1,0);dfs_(1,0);
    for (i=1;i<=n;i++) ans+=dn[0][i]+up[0][i];
    cout<<ans/2;
}