#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
typedef std::vector<int> Poly;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(int& a,int t){if(t>a)return a=t,1;return 0;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

#define MAXN 400011
const int mod=998244353;
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*a%mod;
        a=a*a%mod,p>>=1;
    }
    return res;
}
ll Inv(ll x){return Qpow(x,mod-2);}
int status[MAXN];
ll RT[MAXN],IRT[MAXN],inv2[MAXN];
int upd(int x){return x>=mod?x-mod:x;}
void prework()
{
    int all=1<<18;
    for(int i=1;i<all;i<<=1)
    {
        ll rt=Qpow(3,(mod-1)/(i<<1)),irt=Inv(rt);
        RT[i]=IRT[i]=1;
        for(int j=i+1;j<(i<<1);++j)RT[j]=RT[j-1]*rt%mod,IRT[j]=IRT[j-1]*irt%mod;
    }
    for(int i=1;i<all;i<<=1)inv2[i]=Inv(i);
}
void DFT(Poly& a,int len,int type)
{
    for(int i=0;i<len;++i)
        if(status[i]>i)std::swap(a[i],a[status[i]]);
    for(int cur=1;cur<len;cur<<=1)
    {
        for(int j=0;j<len;j+=cur<<1)
        {
            ll w=1;
            for(int k=0;k<cur;++k)
            {
                ll x=a[j+k],y=(type==1?RT[cur+k]:IRT[cur+k])*a[j+cur+k]%mod;
                a[j+k]=upd(x+y),a[j+cur+k]=upd(x-y+mod);
            }
        }
    }
    if(type!=-1)return;
    ll inv_len=inv2[len];
    for(int i=0;i<len;++i)a[i]=a[i]*inv_len%mod;
}
Poly Mul(Poly a,Poly b)
{
    int len=1,n=a.size(),m=b.size();
    while(len<n+m)len<<=1;
    for(int i=0;i<len;++i)
        status[i]=(status[i>>1]>>1)+((i&1)*(len>>1));
    a.resize(len),DFT(a,len,1);
    b.resize(len),DFT(b,len,1);
    for(int i=0;i<len;++i)a[i]=1ll*a[i]*b[i]%mod;
    DFT(a,len,-1);
    a.resize(n+m-1);
    return a;
}
Poly Add(Poly a,Poly b)
{
    a.resize(max(a.size(),b.size()));
    for(int i=0;i<b.size();++i)a[i]=upd(a[i]+b[i]);
    return a;
}
//------------------//
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=0,last[MAXN];
void adde(int u,int v){e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}
int fa[MAXN],mson[MAXN],lson[MAXN],size[MAXN];
void dfs1(int u)
{
    size[u]=1;
    for(int i=last[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa[u])continue;
        fa[v]=u;
        dfs1(v);
        size[u]+=size[v];
        if(size[v]>size[mson[u]])lson[u]=mson[u],mson[u]=v;
        else lson[u]=v;
    }
}

Poly a[MAXN],seq[MAXN];
std::pair<Poly,Poly> solve(int l,int r)//first:Sum second:Product
{
    if(l==r)return std::make_pair(seq[l],seq[l]);
    int mid=(l+r)>>1;
    std::pair<Poly,Poly> LP=solve(l,mid),RP=solve(mid+1,r);
    return std::make_pair(Add(Mul(LP.second,RP.first),LP.first),Mul(LP.second,RP.second));
}
Poly dfs2(int u)
{
    for(int v=u;v;v=mson[v])
    {
        if(lson[v])a[v]=dfs2(lson[v]);//brute force for light son
        if(a[v].empty())a[v].push_back(1);//F(1)=1
        a[v][0]=1,a[v].insert(a[v].begin(),0);//F(0)=0
    }
    int c=0;
    for(int v=u;v;v=mson[v])seq[++c].swap(a[v]);
    return solve(1,c).first;
}
int main()
{
    prework();
    int n=read();ll x=read();
    for(int i=1;i<n;++i){int u=read(),v=read();adde(u,v),adde(v,u);}
    dfs1(1);
    Poly res=dfs2(1);
    ll ans=0,mul=1;
    for(int i=1;i<=n;++i)ans=(ans+mul*res[i])%mod,mul=mul*((x+i)%mod)%mod*Inv(i)%mod;
    printf("%lld",(ans+mod)%mod);
    return 0;
}