//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXN 400011
ll n;
struct Segment_Tree
{
    struct node
    {
        ll maxv,tag;
    }t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void pushdown(un num)
    {
        if(rt.tag)
        {
            tl.maxv+=rt.tag,tl.tag+=rt.tag;
            tr.maxv+=rt.tag,tr.tag+=rt.tag;
            rt.tag=0;
        }
    }
    void modify(un ql,un qr,ll k,un l=1,un r=n<<1,un num=1)
    {
        if(ql<=l&&r<=qr)
        {
            rt.maxv+=k,rt.tag+=k;
            return;
        }
        pushdown(num);
        un mid=(l+r)>>1;
        if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
        if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
        rt.maxv=max(tl.maxv,tr.maxv);
    }
    ll Qmax(un ql,un qr,un l=1,un r=n<<1,un num=1)
    {
        if(ql<=l&&r<=qr)return rt.maxv;
        pushdown(num);
        un mid=(l+r)>>1;ll ans=0;
        if(ql<=mid)umax(ans,Qmax(ql,qr,l,mid,num<<1));
        if(qr>mid)umax(ans,Qmax(ql,qr,mid+1,r,num<<1|1));
        return ans;
    }
}sgt;
ll l[MAXN],r[MAXN],s[MAXN],a[MAXN];
void calc_border(ll n)
{
    ll top=0;
    for(ll i=1;i<=n;++i)
    {
        while(top&&a[s[top]]>a[i])--top;
        l[i]=s[top]+1;
        s[++top]=i;
    }
    s[top=0]=n+1;
    for(ll i=n;i;--i)
    {
        while(top&&a[s[top]]>a[i])--top;
        r[i]=s[top]-1;
        s[++top]=i;
    }
}
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)a[n+i]=a[i]=read();
    calc_border(n<<1);
    for(ll i=1;i<=n;++i)sgt.modify(l[i],r[i],1);
    //for(ll i=1;i<=(n<<1);++i)printf("%lld %lld\n",l[i],r[i]);
    //puts("");
    ll ans=n,f=1;
    for(ll x=1;x<=n;++x)
    {
        if(umin(ans,sgt.Qmax(x,x+n-1)))f=x;
        sgt.modify(l[x],r[x],-1),sgt.modify(l[n+x],r[n+x],1);
    }
    printf("%lld %lld",ans,f-1);
    return 0;
}