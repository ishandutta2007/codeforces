//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef int ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 200011
ll a[MAXN],b[MAXN],s[MAXN];
char arr[MAXN],to2[MAXN];
std::string ans;
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),ok=0;scanf("%s",arr+1);
        for(ll x=0;x<=8;++x)
        {
        	ans="";
            ll pre1=0,pre2=x,flag=0;
            for(ll i=1;i<=n;++i)
            {
            	if(arr[i]-'0'==x&&pre2==x)ans+='2';
            	else if(arr[i]-'0'>x)
                {
                    if(arr[i]-'0'<pre2)flag=1;
                    pre2=arr[i]-'0';
                    ans+='2';
                }
                else
                {
                    if(arr[i]-'0'<pre1)flag=1;
                    pre1=arr[i]-'0';
                    ans+='1';
                }
			}
                
            if(flag)continue;
            std::cout<<ans<<'\n';ok=1;break;
        }
        if(!ok)puts("-");
    }
}