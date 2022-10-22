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
#define MAXN 200011
std::set<pll>len;
struct one
{
    ll pos,len,num;
    bool operator <(const one& t)
    const
    {
        return (pos<t.pos||(pos==t.pos&&len<t.len));
    }
};
std::set<one>seg;
int main()
{
    ll n=read(),pre=read(),cnt=1,ans=0;
    if(n==1){puts("1");return 0;}
    for(ll i=2;i<=n;++i)
    {
        ll x=read();
        if(x==pre)++cnt;
        else
        {
            len.insert(pll(-cnt,i-cnt)),seg.insert(one{i-cnt,cnt,pre});
            pre=x,cnt=1;
        } 
    }
    len.insert(pll(-cnt,n+1-cnt)),seg.insert(one{n+1-cnt,cnt,pre});
    while(!len.empty())
    {
        ++ans;
        ll l=len.begin()->first,pos=len.begin()->second;
        auto place=seg.lower_bound(one{pos,0,0});
        if(place!=seg.begin())
        {
        	auto pre=--place,nxt=++(++place);
	        if(pre!=seg.end()&&nxt!=seg.end())
	        {
	            if(pre->num==nxt->num)
	            {
	                len.insert(pll(-pre->len-nxt->len,pre->pos));
	                len.erase(len.lower_bound(pll(-pre->len,pre->pos)));
	                len.erase(len.lower_bound(pll(-nxt->len,nxt->pos)));
	                seg.insert(one{pre->pos,pre->len+nxt->len,pre->num});
	                seg.erase(pre),seg.erase(nxt);
	            }
	        }
		}
        len.erase(len.lower_bound(pll(l,pos)));
        seg.erase(seg.lower_bound(one{pos,0,0}));
    }
    printf("%lld",ans);
    return 0;
}