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
char s[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        scanf("%s",s+1);
        ll n=strlen(s+1),ans=0,pre=1;
        for(ll i=1;i<=n;++i)
            if(s[i]=='1')
            {
                ll f=0;
                for(ll j=i;j<=n;++j)
                {
                    f=((f<<1)+(s[j]=='1'));
                    if(f>n)break;
                    ans+=(j-i+1<=f&&f<=j-pre+1);
                }
                pre=i+1;
            }
        printf("%lld\n",ans);
    }
    return 0;
}