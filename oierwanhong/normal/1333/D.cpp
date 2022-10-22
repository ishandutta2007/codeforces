//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<28)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
char s[5011],t[5011];
std::vector<ll>a[15011];
int main()
{
    ll n=read(),k=read(),tot=0,used=0;
    scanf("%s",s+1);
    for(ll i=1;i<=3*n;++i)
    {
        for(ll j=1;j<n;++j)
            if(s[j]=='R'&&s[j+1]=='L')std::swap(s[j],s[j+1]),a[i].push_back(j),++j;
        tot+=a[i].size();
        if(a[i].empty())break;
        ++used;
    }
    if(tot<k||k<used)puts("-1");
    else
    {
        for(ll i=1;i<=3*n;++i)
        {
        	if(a[i].empty())break;
            if(tot-k+1<ll(a[i].size()))
            {
                printf("%lld ",tot-k+1);
                for(ll j=0;j<tot-k+1;++j)printf("%lld ",a[i][j]);
                puts("");
                for(ll j=tot-k+1;j<a[i].size();++j)printf("1 %lld\n",a[i][j]);
                for(ll j=i+1;j<=3*n;++j)
                    if(a[j].size())
                    {
                        for(auto x:a[j])printf("1 %lld\n",x);
                    }
                return 0;
            }
            tot-=a[i].size();--k;
            printf("%lld ",a[i].size());
            for(auto x:a[i])printf("%lld ",x);
            puts("");
        }    
    }
    
    return 0;
}