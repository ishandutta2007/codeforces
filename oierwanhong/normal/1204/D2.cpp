//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
str s,t;
int main()
{
    std::cin>>s;std::reverse(s.begin(),s.end());
    ll bal=0;
    for(ll i=0;i<s.size();++i)
    {
        if(s[i]=='0')++bal,t+=s[i];
        else
        {
            if(bal==0)t+='0';
            else --bal,t+='1';
        }
    }
    std::reverse(t.begin(),t.end());
    std::cout<<t;
}