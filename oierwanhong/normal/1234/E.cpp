//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
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
#define MAXN 200011
ll a[MAXN],c[MAXN],n,m;
void add(ll l,ll r,ll k)
{
    if(l>r)return;
    c[l]+=k,c[r+1]-=k;
}
void ctrb(ll a,ll b)
{
    if(a>b)std::swap(a,b);
    if(a==b)return;
    add(1,a-1,b-a),add(a,a,b-1),add(a+1,b-1,b-a-1),add(b,b,a),add(b+1,n,b-a);
}
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=m;++i)a[i]=read();
    for(ll i=1;i<m;++i)ctrb(a[i],a[i+1]);
    for(ll i=1;i<=n;++i)c[i]+=c[i-1],printf("%lld ",c[i]);
    return 0;
}