#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(int& a,int t){if(t<=a)return a=t,1;return 0;}
#define MAXN 200011
ll a[MAXN],b[MAXN];
int main()
{
    int task=read();
    while(task--)
    {
        int n=read();
        ll ans=0,h=0;
        for(int i=1;i<=n;++i)a[i]=read();
        for(int i=2;i<=n;++i)b[i]=max(0,a[i-1]-a[i]),umax(a[i],a[i-1]);
        for(int i=2;i<=n;++i)
            if(h>=b[i])h=b[i];
            else ans+=b[i]-h,h=b[i];
        printf("%lld\n",ans);
    }
    return 0;
}