#include<bits/stdc++.h>
#define sz 6666
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
struct hh{ll w;int id;};
inline bool cmp(const hh &x,const hh &y){return x.w<y.w;}
hh a[sz];
int n,m;
vector<hh>w[sz];
bool vis[sz];
ll work(int K)
{
    int i,j,x;
    int cur=w[1].size();
    ll ret=0;
    memset(vis,0,sizeof(vis));
    for (i=0;i<w[1].size();i++) vis[w[1][i].id]=1;
    for (i=2;i<=m;i++) 
        if ((x=w[i].size())>=K)
            for (j=0;x>=K;j++,x--) 
                cur++,ret+=w[i][j].w,vis[w[i][j].id]=1;
    for (i=1;cur<K;i++) 
        if (!vis[a[i].id]) 
            {ret+=a[i].w;cur++;}
    return ret;
}
int main()
{
    file();
    int i,y,z;
    read>>n>>m;
    for (i=1;i<=n;i++)
    {
        read>>y>>z;
        hh x={z,i};
        a[i]=x;w[y].push_back(x);
    }
    sort(a+1,a+n+1,cmp);
    for (i=1;i<=m;i++) sort(w[i].begin(),w[i].end(),cmp);
    ll ans=1e15;
    for (i=1;i<=n;i++) ans=min(ans,work(i)); 
    cout<<ans;
}