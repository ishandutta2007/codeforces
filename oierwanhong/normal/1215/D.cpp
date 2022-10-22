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
int main()
{
    std::ios::sync_with_stdio(0),std::cin.tie(0);
    ll n,cnt=0,x=0;std::cin>>n;
    for(ll i=1;i<=n/2;++i)
    {
        char op;std::cin>>op;
        if(op=='?')++cnt;
        else x+=op-'0';
    }
    for(ll i=1;i<=n/2;++i)
    {
        char op;std::cin>>op;
        if(op=='?')--cnt;
        else x-=op-'0';
    }
    //printf("%lld %lld\n",cnt,x);
    if(cnt==0)puts(x==0?"Bicarp":"Monocarp");
    else
    {
        if(x%9||x*cnt>0)puts("Monocarp");
        else
        {
            cnt=cnt/2+x/9;
            puts(cnt&1?"Monocarp":"Bicarp");
        }
    }
    
}