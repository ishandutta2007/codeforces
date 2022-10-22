//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef int ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 200011
struct node
{
    ll lson,rson;
    ll size;
}t[MAXN<<5|1];
ll root[MAXN],cnt=0,n;
#define rt t[num]
#define tl t[rt.lson]
#define tr t[rt.rson]
void insert(ll pre,ll& num,ll x,un l=1,un r=n)
{
    num=++cnt;
    rt=t[pre];
    if(l==r){++rt.size;return;}
    un mid=(l+r)>>1;
    if(x<=mid)insert(t[pre].lson,rt.lson,x,l,mid);
    else insert(t[pre].rson,rt.rson,x,mid+1,r);
    rt.size=tl.size+tr.size;
}
ll Qkth(ll num,ll k,un l=1,un r=n)
{
    if(l==r)return l;
    un mid=(l+r)>>1;
    if(k<=tl.size)return Qkth(rt.lson,k,l,mid);
    else return Qkth(rt.rson,k-tl.size,mid+1,r);
}

ll a[MAXN];
std::priority_queue<pll>q;
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)a[i]=read(),q.push({a[i],-i});
    for(ll i=1;i<=n;++i)
		insert(root[i-1],root[i],-q.top().second),q.pop();
    ll Q=read();
    while(Q--)
    {
        ll k=read(),pos=read();
        printf("%d\n",a[Qkth(root[k],pos)]);
    }
    return 0;
}