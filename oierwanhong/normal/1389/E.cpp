#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
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
const ll INF=1ll<<50;
#define MAXN 200011
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    int task=read();
    while(task--)
    {
        ll m=read(),d=read(),w=read(),t=min(m,d);
        if(d==1){printf("%lld\n",t*(t-1));}
        else
        {
            w/=gcd(w,d-1);
            printf("%lld\n",t/w*t-(t/w)*((t/w)+1)/2*w);
        }
    }
    return 0;
}