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
#define MAXN 211
ll l[MAXN],r[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read(),x=read(),m=read();
        for(ll i=1;i<=m;++i)l[i]=read(),r[i]=read();
        ll nowl=x,nowr=x;
        for(ll i=1;i<=m;++i)
            if(((l[i]<=nowl&&r[i]>=nowl)||(l[i]<=nowr&&r[i]>=nowr)))umin(nowl,l[i]),umax(nowr,r[i]);
        printf("%lld\n",nowr-nowl+1);
    }
    return 0;
}