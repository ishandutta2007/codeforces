#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll t){if(t>a)return a=t,1;return 0;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

#define MAXN 200011
int n;
struct BIT
{
    #define lowb (i&-i)
    ll t[MAXN];
    void Add(int i,ll k)
    {
        while(i<=n)t[i]+=k,i+=lowb;
    }
    ll Qmax(int i)
    {
        ll res=0;
        while(i)res+=t[i],i-=lowb;
        return res;
    }
    void modify(int l,int r,ll k){Add(l,k),Add(r+1,-k);}
}TB,TC;
ll a[MAXN],b[MAXN];
int main()
{
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    a[0]=-1e16;
    for(int i=1;i<=n;++i)
    {
        ll pre=(i==1?0:TB.Qmax(i-1));
        TB.modify(i,i,pre+max(a[i]-a[i-1],0));
        TC.modify(i,i,a[i]-pre-max(a[i]-a[i-1],0));
    }
    for(int i=n;i;--i)a[i]-=a[i-1];
    ll t=TB.Qmax(n)+TC.Qmax(1);
    if(t>0)printf("%lld\n",(t+1)/2);
    else printf("%lld\n",t/2);
    int query=read();
    while(query--)
    {
        int l=read(),r=read(),x=read();
        ll pre=(l==1?0:TB.Qmax(l-1));
        a[l]+=x;
        ll delta=pre+max(a[l],0)-TB.Qmax(l);
        TB.modify(l,r,delta),TC.modify(l,r,x-delta);
        a[r+1]-=x;
        if(r+1<=n)
        {
            ll pre=(r+1==1?0:TB.Qmax(r));
            ll delta=pre+max(a[r+1],0)-TB.Qmax(r+1);
            TB.modify(r+1,n,delta),TC.modify(r+1,n,-delta);
        }
        ll t=TB.Qmax(n)+TC.Qmax(1);
        if(t>0)printf("%lld\n",(t+1)/2);
        else printf("%lld\n",t/2);
    }
    return 0;
}