//Wan Hong 3.1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<set>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
// static char buf[10000000],*p1=buf,*p2=buf;
// #define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,10000000,stdin),p1==p2)?EOF:*p1++
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(int& a,int b){if(b>a)return a=b,1;return 0;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
bool umin(int& a,int b){if(b<a)return a=b,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
#define MAXN 200011
struct one{ll val,dex;}a[MAXN];
bool cmp(one a,one b){return a.val>b.val;}
int main()
{
    int n=read(),s;
    for(int i=1;i<=n;++i)a[i].val=read(),a[i].dex=i;
    if(n==1){printf("%lld\n",a[1].val);return 0;}
    if(n==2){printf("%lld\n",-a[1].val-a[2].val);return 0;}
    if(n==3){printf("%lld\n",max(a[1].val+a[2].val-a[3].val,a[2].val+a[3].val-a[1].val));return 0;}
    std::sort(a+1,a+n+1,cmp);
    if(n%3==0)s=2;
    else if(n%3==1)s=1;
    else s=0;
    ll sum=0,ans=-1e18;
    for(int i=1;i<=s;++i)sum+=a[i].val;
    for(int i=s+1;i<=n;++i)sum-=a[i].val;
    umax(ans,sum);
    while(s+3<=n)
    {
        ++s,sum+=2*a[s].val;
        ++s,sum+=2*a[s].val;
        ++s,sum+=2*a[s].val;
        if((n&1)&&(s==(n+1)/2))
        {
            bool flag=1;
            for(int i=1;i<=s;++i)
                if(!(a[i].dex&1))flag=0;
            if(!flag)umax(ans,sum);
            else umax(ans,sum-2*a[s].val+2*a[s+1].val);
        }
        else umax(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}