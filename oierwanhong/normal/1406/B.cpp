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

#define MAXN 200011
ll posi[MAXN],negi[MAXN];
int main()
{
    int task=read();
    while(task--)
    {
        ll n=read(),ans=-1e18,cp=0,cn=0;
        for(int i=1;i<=n;++i)
        {
            ll x=read();
            if(x>0)posi[++cp]=x;
            else if(x<0)negi[++cn]=x;
            else ans=0;
        }
        std::sort(posi+1,posi+cp+1),std::sort(negi+1,negi+cn+1);
        for(int x=0;x<=5;++x)
        {
            if(x>cn||5-x>cp)continue;
            if(x&1)
            {
                ll mul=1;
                for(int i=cn;i>=cn-x+1;--i)mul*=negi[i];
                for(int i=1;i<=5-x;++i)mul*=posi[i];
                umax(ans,mul);
            }
            else
            {
                ll mul=1;
                for(int i=1;i<=x;++i)mul*=negi[i];
                for(int i=cp;i>=cp-(5-x)+1;--i)mul*=posi[i];
                umax(ans,mul);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}