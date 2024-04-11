#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
char s[55];
ll C2(ll n){return n*(n-1)/2;}
ll C3(ll n){return n*(n-1)*(n-2)/6;}
int main()
{
	ll n=read();
	scanf("%s",s+1);
	ll x=0,y=1,fl=0;
	int len=strlen(s+1);
	for(int i=1;i<=len;++i)
	{
		if(s[i]=='.')fl=1;
		else if(!fl)
		{
			x=x*10+(s[i]-'0');
		}
		else x=x*10+(s[i]-'0'),y*=10;
	}
	ll l=0,r=n;
	x*=C3(n)*2;
	while(l<r)
	{
		ll a=(l+r)>>1,b=n-a;
		ll f=C3(a)*2+C2(a)*b*2+a*C2(b);
		if(f*y>=x)r=a;
		else l=a+1;
	}
	printf("%lld\n",l);
	return 0;
}