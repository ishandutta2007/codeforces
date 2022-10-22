//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
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
std::set<pll>s;
struct one
{
    ll x,y,f;
    bool operator <(const one& t)
    const
    {
        return f<t.f;
    }
};
std::priority_queue<one>q;
ll mx[]={0,1,0,-1},my[]={1,0,-1,0};
int main()
{
    ll n=read(),m=read(),r=read(),k=read(),sum=0;
    ll x=(n+1)/2,y=(m+1)/2;
    ll f=(min(y+r-1,m)-max(y,r)+1)*(min(x+r-1,n)-max(x,r)+1);
    s.insert(pll(x,y));q.push(one{x,y,f});
    while(k--)
    {
        ll x=q.top().x,y=q.top().y;
        sum+=q.top().f;
        //printf("%lld %lld %lld\n",x,y,q.top().f);
        q.pop();
        for(ll i=0;i<4;++i)
        {
            ll vx=x+mx[i],vy=y+my[i];
            if(vx>0&&vx<=n&&vy>0&&vy<=m&&!s.count(pll(vx,vy)))
            {
                s.insert(pll(vx,vy));
                q.push(one{vx,vy,(min(vy+r-1,m)-max(vy,r)+1)*(min(vx+r-1,n)-max(vx,r)+1)});
            }
        }
    }
    printf("%.10f",(double(sum))/((n-r+1)*(m-r+1)));
    return 0;
}