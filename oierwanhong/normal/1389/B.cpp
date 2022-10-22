#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(int& a,int t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
#define MAXN 100011
ll a[MAXN];
int main()
{
    int task=read();
    while(task--)
    {
        int n=read(),k=read(),z=read(),ans=0;
        for(int i=1;i<=n;++i)a[i]=read();
        for(int t=0;t<=z;++t)
        {
            if(k+1-2*t<1)break;
            int now=0,maxv=0;
            for(int i=1;i<=k+1-2*t;++i)now+=a[i],umax(maxv,a[i]+a[i+1]);
            umax(ans,now+maxv*t);
        }
        printf("%d\n",ans);
    }
    return 0;
}