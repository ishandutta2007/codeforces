#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<cassert>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
const int N=200010;
struct Node
{
    int mx,cnt,mx2;
    ll sum;
    void init(int x){mx=sum=x;cnt=1;mx2=-1000000;}
    Node& operator+=(const Node&a)
    {
        if(mx>a.mx)mx2=max(mx2,a.mx);
        else if(mx<a.mx)mx2=max(mx,a.mx2),mx=a.mx,cnt=a.cnt;
        else cnt+=a.cnt,mx2=max(mx2,a.mx2);
        sum+=a.sum;
        return (*this);
    }
    void putmin(int x)
    {
        if(mx<=x)return;
        sum-=1ll*cnt*(mx-x);
        mx=x;
    }
}tree[N<<2];
void build(int p,int le,int ri,int a[])
{
    if(le==ri){tree[p].init(-a[le]);return;}
    int mid=(le+ri)>>1;
    build(p<<1,le,mid,a);
    build(p<<1|1,mid+1,ri,a);
    (tree[p]=tree[p<<1])+=tree[p<<1|1];
}
void modify(int p,int le,int ri,int ll,int rr,int x)
{
    if(tree[p].mx<=x)return;
    if(ll<=le&&ri<=rr&&tree[p].mx2<x){tree[p].putmin(x);return;}
    tree[p<<1].putmin(tree[p].mx);tree[p<<1|1].putmin(tree[p].mx);
    int mid=(le+ri)>>1;
    if(ll<=mid)modify(p<<1,le,mid,ll,rr,x);
    if(rr>mid)modify(p<<1|1,mid+1,ri,ll,rr,x);
    (tree[p]=tree[p<<1])+=tree[p<<1|1];
}
ll getsum(int p,int le,int ri,int ll,int rr)
{
    if(ll<=le&&ri<=rr)return tree[p].sum;
    tree[p<<1].putmin(tree[p].mx);tree[p<<1|1].putmin(tree[p].mx);
    int mid=(le+ri)>>1;
    ::ll ans=0;
    if(ll<=mid)ans+=getsum(p<<1,le,mid,ll,rr);
    if(rr>mid)ans+=getsum(p<<1|1,mid+1,ri,ll,rr);
    return ans;
}
ll ans;
vector<pair<int,int>>g[N];
int a[N],L[N],R[N],fir[N],fir2[N],la[N],la2[N],n;
void updatel(int&l1,int&l2,int x)
{
    if(x<l1)l2=l1,l1=x;
    else if(x<l2)l2=x;
}
void updater(int&r1,int&r2,int x)
{
    if(x>r1)r2=r1,r1=x;
    else if(x>r2)r2=x;
}
int main()
{
    scanf("%d",&n);
    rep(i,n)
    {
        scanf("%d",&a[i]);
        if(!fir[a[i]])fir[a[i]]=i;
        else if(!fir2[a[i]])fir2[a[i]]=i;
        la2[a[i]]=la[a[i]];la[a[i]]=i;
    }
    L[2]=R[n-1]=1;
    rep(i,200000)
    if(i!=1)
    {
        int l1=n+1,l2,r1=0,r2;
        for(int j=i;j<=200000;j+=i)
        {
            if(fir[j])updatel(l1,l2,fir[j]),updater(r1,r2,la[j]);
            if(fir2[j])updatel(l1,l2,fir2[j]),updater(r1,r2,la2[j]);
        }
        if(l1<=n)
        {
            g[l1].pb(mp(r1,i));
            L[l2]=max(L[l2],i);
            R[r2]=max(R[r2],i);
        }
    }
    rep(i,n)L[i]=max(L[i],L[i-1]);
    for(int i=n;i;i--)R[i]=max(R[i],R[i+1]);
    build(1,1,n,R);
    rep(i,n)
    {
        modify(1,1,n,1,n,-L[i-1]);
        if(i>1&&i+1<=n)modify(1,1,n,i+1,n,-1);
        ans+=L[i-1];
        if(i<n)ans-=getsum(1,1,n,i+1,n);
        for(auto j:g[i])modify(1,1,n,1,j.first,-j.second);
    }
    printf("%lld\n",ans);
    return 0;
}