//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
#define MAXN 20
ll a[1<<(MAXN+1)],ans[1<<MAXN],num[21];
int main()
{
    ll t=read();
    while(t--)
    {
        ll h=read(),g=read();
        for(ll i=1;i<(1<<h);++i)a[i]=read();
        ll anscnt=0,numcnt=0,pos,now_dep=0;
        for(ll i=1;i<(1<<h);++i)
        {
            if((i&(i-1))==0)++now_dep;
            while(a[i])
            {
                numcnt=0,pos=i;
                while(pos<(1<<h)&&a[pos])
                {
                    num[++numcnt]=pos;
                    if(a[pos<<1]>a[pos<<1|1])pos<<=1;
                    else pos=pos<<1|1;
                }
                if(now_dep+numcnt<=g+1)break;
                ans[++anscnt]=i;
                for(ll j=1;j<numcnt;++j)a[num[j]]=a[num[j+1]];
                a[num[numcnt]]=0;
            }
        }
        ll sum=0;
        for(ll i=1;i<(1<<g);++i)sum+=a[i];
        printf("%lld\n",sum);
        for(ll i=1;i<=anscnt;++i)printf("%lld ",ans[i]);
        puts("");
    }
    return 0;
}