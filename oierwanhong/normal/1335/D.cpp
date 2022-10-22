//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
char a[100][100];
bool p[15][15];
int main()
{
    ll t=read();
    while(t--)
    {
        memset(p,0,sizeof p);
        for(ll i=0;i<9;++i)scanf("%s",a[i]);
        for(ll i=0;i<9;++i)
            for(ll j=0;j<9;++j)
            {
                if(a[i][j]=='1')
                    if(j%3==2)p[i][j-2]=1;
                    else p[i][j+1]=1;
            }
        for(ll i=0;i<9;++i)
        {
            for(ll j=0;j<9;++j)
                if(p[i][j])putchar('1');
                else putchar(a[i][j]);
            puts("");
        }
    }
    return 0;
}