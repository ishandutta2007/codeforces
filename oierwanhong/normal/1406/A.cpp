#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll t){if(t>a)return a=t,1;return 0;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

int c[211];
int main()
{
    int task=read();
    while(task--)
    {
        memset(c,0,sizeof c);
        ll n=read(),ans=0;
        for(int i=1;i<=n;++i)++c[read()];
        for(int i=0;i<=100;++i)
            if(!c[i]){ans+=i;break;}
            else --c[i];
        for(int i=0;i<=100;++i)
            if(!c[i]){ans+=i;break;}
        printf("%lld\n",ans);
    }
    return 0;
}