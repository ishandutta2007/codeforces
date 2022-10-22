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
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
char a[200011];
int main()
{
    ll n=read(),cnt=0;scanf("%s",a+1);
    bool flag=0;
    for(ll i=1;i<=n;++i)
        if(a[i]=='(')++cnt;
        else
        {
            if(!cnt)
            {
                if(flag){puts("NO");return 0;}
                flag=1;
            }
            else --cnt;
        }
    if((!flag&&!cnt)||(flag&&cnt==1))puts("YES");
    else puts("NO");
}