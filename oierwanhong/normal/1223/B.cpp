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
int main()
{
    ll t=read();
    while(t--)
    {
        str s,t;std::cin>>s>>t;
        char ans=0;
        for(ans='a';ans<='z';++ans)
        {
            bool f1=0,f2=0;
            for(auto x:s)if(x==ans)f1=1;
            for(auto x:t)if(x==ans)f2=1;
            if(f1&f2)break;
        }
        puts(ans<='z'?"YES":"NO");
    }
}