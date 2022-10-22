#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 63;
ll len[MAXN],sig[MAXN];
ll a[MAXN];
void shift(int i,ll k)
{
	a[i]=((a[i]+k)%len[i]+len[i])%len[i];
}
int main()
{
	len[0]=1,sig[0]=1;
	for(int i=1;i<=60;++i)len[i]=1ll<<i,sig[i]=sig[i-1]+len[i];
	int n=read();
	while(n--)
	{
		int op=read();
		if(op==1)
		{
			ll x=read(),k=read();
			int p=std::lower_bound(sig,sig+61,x)-sig;
			shift(p,k);
			if(p+1<=60)shift(p+1,-k-k);
		}
		else if(op==2)
		{
			ll x=read(),k=read();
			int p=std::lower_bound(sig,sig+61,x)-sig;
			shift(p,k);
		}
		else
		{
			ll x=read();
			int p=std::lower_bound(sig,sig+61,x)-sig;
			while(x)
			{
				printf("%lld ",x);
				x=((x-len[p]+a[p])%len[p]+len[p])>>1,--p;
			}
			puts("");
		}
	}
	return 0;
}