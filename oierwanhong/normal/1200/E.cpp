//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<ctime>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
#define MAXN 1000011
char a[MAXN],b[MAXN];
ll f1[MAXN],f2[MAXN],g1[MAXN],g2[MAXN];
ll pw1[MAXN],pw2[MAXN];
const ll mod1=998244353,mod2=ll(1e9+9);
ll get1(ll l,ll r)
{
    return ((f1[r]-f1[l-1]*pw1[r-l+1])%mod1+mod1)%mod1;
}
ll get2(ll l,ll r)
{
    return ((f2[r]-f2[l-1]*pw2[r-l+1])%mod2+mod2)%mod2;
}
int main()
{
	srand(time(0));rand();
    ll b1=rand(),b2=rand();
    pw1[0]=pw2[0]=1;
    for(ll i=1;i<MAXN;++i)pw1[i]=pw1[i-1]*b1%mod1,pw2[i]=pw2[i-1]*b2%mod2;
    ////
    ll n=read(),len=0;
    while(n--)
    {
        scanf("%s",b+1);
        ll t=strlen(b+1),i,ff1=0,ff2=0,maxpos=0;
        for(i=1;i<=min(t,len);++i)
        {
            ff1=(ff1*b1+b[i])%mod1,ff2=(ff2*b2+b[i])%mod2;
            if(get1(len-i+1,len)==ff1&&get2(len-i+1,len)==ff2)maxpos=i;
        }
        for(ll p=maxpos+1;p<=t;++p)
        {
            a[++len]=b[p];
            f1[len]=(f1[len-1]*b1+b[p])%mod1,f2[len]=(f2[len-1]*b2+b[p])%mod2;
        }
        //printf("len=%lld\n",len);
    }
    puts(a+1);
    return 0;
}