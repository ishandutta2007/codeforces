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
const ll INF=1ll<<28;
/**********/
#define MAXN 200011
ll f(ll n){return (1+n)*n/2;}
ll a[MAXN],len=18,pw10[21];
void prework()
{
	pw10[0]=1;
	for(ll i=1;i<=18;++i)pw10[i]=pw10[i-1]*10;
	ll k=1,p=10;
    for(ll i=1;i<MAXN;++i)
    {
    	if(i%p==0)p*=10,++k;
    	a[i]=a[i-1]+k;
	}
}
int main()
{
    prework();
    ll task=read();
    while(task--)
    {
        ll n=read(),pos=1;
        while(n>a[pos])n-=a[pos],++pos;
        ll c=1,t=10;
        while(n>0)
        {
        	ll x=t/10*9*c;
        	if(n>x)n-=x,++c,t*=10;
        	else break;
		}
        if((n-1)%c==0)printf("%lld\n",((n-1)/c/pw10[c-1]+1)%10);
        else printf("%lld\n",(n-1)/c/pw10[c-(n-1)%c-1]%10);
    }
    return 0;
}