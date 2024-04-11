#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
#define MAXN 1000011
std::vector<pii>q1[MAXN],q2[MAXN];
ll ans[MAXN],L[MAXN],R[MAXN],a[MAXN],s[MAXN],top,lb[MAXN],rb[MAXN];
int n,query;
struct Segment_Tree
{
    struct node
    {
        ll sum,tag;
    }t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void pushdown(un l,un r,un num)
    {
        if(!rt.tag)return;
        un mid=(l+r)>>1;
        tl.sum+=(mid-l+1)*rt.tag,tl.tag+=rt.tag;
        tr.sum+=(r-mid)*rt.tag,tr.tag+=rt.tag;
        rt.tag=0;
    }
    void modify(un ql,un qr,ll k,un l=1,un r=n,un num=1)
    {
        if(ql>qr)return;
        if(ql<=l&&r<=qr){rt.sum+=(r-l+1)*k,rt.tag+=k;return;}
        pushdown(l,r,num);
        un mid=(l+r)>>1;
        if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
        if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
        rt.sum=tl.sum+tr.sum;
    }
    ll Qsum(un ql,un qr,un l=1,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr)return rt.sum;
        pushdown(l,r,num);
        un mid=(l+r)>>1;ll res=0;
        if(ql<=mid)res+=Qsum(ql,qr,l,mid,num<<1);
        if(qr>mid)res+=Qsum(ql,qr,mid+1,r,num<<1|1);
        return res;
    }
}sgt;
int main()
{
    n=read(),query=read();
    for(int i=1;i<=n;++i)a[i]=read();
    top=0;
    for(int i=1;i<=n;++i)
    {
        while(top&&a[s[top]]<a[i])--top;
        L[i]=s[top]+1;
        s[++top]=i;
    }
    s[top=0]=n+1;
    for(int i=n;i;--i)
    {
        while(top&&a[s[top]]<a[i])--top;
        R[i]=s[top]-1;
        s[++top]=i;
    }
    for(int i=1;i<=query;++i)lb[i]=read();
    for(int i=1;i<=query;++i)rb[i]=read(),q1[lb[i]].push_back(pii(rb[i],i)),q2[rb[i]].push_back(pii(lb[i],i));
    for(int i=n;i;--i)
    {
        //printf("Add %d\n",i);
        sgt.modify(i,i,i);
        sgt.modify(i+1,R[i],1);
        for(pii x:q1[i])ans[x.second]+=sgt.Qsum(1,x.first);//,printf("val[%d]=%lld\n",x.first,sgt.Qsum(1,x.first));
    }
    memset(sgt.t,0,sizeof sgt.t);
    for(int i=1;i<=n;++i)
    {
        //printf("Dec %d\n",i);
        sgt.modify(i,i,i+1);
        sgt.modify(L[i],i,-1);
        for(pii x:q2[i])ans[x.second]-=sgt.Qsum(x.first,n);//,printf("val[%d]=%lld\n",x.first,sgt.Qsum(x.first,n));
    }
    for(int i=1;i<=query;++i)printf("%lld ",ans[i]+rb[i]-lb[i]+1);
    return 0;
}