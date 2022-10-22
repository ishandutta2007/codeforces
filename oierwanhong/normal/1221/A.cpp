//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
const ll INF=1ll<<28;
/**********/
std::set<ll>s;
bool ins(ll x)
{
    if(x==2048)return 1;
    if(!s.count(x)){s.insert(x);return 0;}
    else
    {
        s.erase(x);
        return ins(x<<1);
    }
}
int main()
{
    ll t=read();
    while(t--)
    {
        s.clear();
        ll n=read(),flag=0;
        while(n--)flag|=ins(read());
        puts(flag?"YES":"NO");
    }
}