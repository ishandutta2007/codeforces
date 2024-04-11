#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
void umin(ll& a,ll t){if(t<a)a=t;}
const ll INF=1ll<<50;
#define MAXN 1000011
char a[MAXN],b[MAXN];

int main()
{
    ll task=read();
    while(task--)
    {
        std::vector<ll>ans;
        ll n=read();scanf("%s%s",a+1,b+1);
        bool flag=0;
        ll l=1,r=n;
        for(ll i=n;i>1;--i)
            if(flag)
            {
                b[i]^=1;
                if(a[l]!=b[i])
                {
                    if(a[r]==b[i])ans.push_back(1);
                    ans.push_back(r-l+1);flag=0;--r;
                }
                else ++l;
            }
            else
            {
                if(a[r]!=b[i])
                {
                    if(a[l]==b[i])ans.push_back(1);
                    ans.push_back(r-l+1);flag=1;++l;
                }
                else --r;
            }
        //printf("l=%lld,r=%lld\n",l,r);
        if(flag)b[1]^=1;
        if(a[l]!=b[1])ans.push_back(1);
        std::cout<<ans.size()<<' ';
        for(auto x:ans)printf("%lld ",x);
        puts("");
    }
    return 0;
}