//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
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
#define MAXN 100011
std::vector<ll>row[MAXN],col[MAXN];
int main()
{
    ll n=read(),m=read(),k=read();
    for(ll i=1;i<=k;++i)
    {
        ll x=read(),y=read();
        row[x].push_back(y),col[y].push_back(x);
    }
    ll sum=1,x=1,y=1,end=m;
    for(auto pos:row[x])
        if(pos>y)umin(end,pos-1);
    sum+=end-x,y=end;
    ll maxrow=n,minrow=2,maxcol=end-1,mincol=1;
    while("red")
    {
        end=maxrow;
        for(auto pos:col[y])
            if(pos>x)umin(end,pos-1);
        if(end==x)break;
        sum+=end-x,x=end;maxrow=end-1;
        end=mincol;
        for(auto pos:row[x])
            if(pos<y)umax(end,pos+1);
        if(end==y)break;
        sum+=y-end,y=end;mincol=end+1;
        end=minrow;
        for(auto pos:col[y])
            if(pos<x)umax(end,pos+1);
        if(end==x)break;
        sum+=x-end,x=end;minrow=end+1;
        end=maxcol;
        for(auto pos:row[x])
            if(pos>y)umin(end,pos-1);
        if(end==y)break;
        sum+=end-y,y=end;maxcol=end-1;
    }
    puts(sum==n*m-k?"Yes":"No");
    return 0;
}