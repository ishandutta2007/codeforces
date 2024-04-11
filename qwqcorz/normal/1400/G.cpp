#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<m||m<0) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}
int id[N],cnt=0,u[N],v[N];
bool is[N];
vector<int>ins[N],era[N];

signed main()
{
	ysgs(3e5);
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int l=read(),r=read();
		ins[l].push_back(i);
		era[r+1].push_back(i);
	}
	for (int i=0;i<m;i++)
	{
		u[i]=read(),v[i]=read();
		is[u[i]]=is[v[i]]=1;
	}
	for (int i=1;i<=n;i++) if (is[i]) id[i]=cnt++;
	vector<pair<ll,int>>a(1<<m);
	for (int S=0;S<(1<<m);S++)
	{
		ll T=0;
		for (int i=0;i<m;i++) if (S>>i&1) T|=(1LL<<id[u[i]])|(1LL<<id[v[i]]);
		a[S]={T,__builtin_popcountll(S)%2?-1:1};
	}
	ll S=0;
	int ans=0;
	vector<int>t(cnt+1);
	for (auto [T,v]:a) if (!(~S&T)) t[__builtin_popcountll(S&T)]+=v;
	for (int i=1,now=0;i<=n;i++)
	{
		ll last=S;
		for (int j:ins[i])
		{
			now++;
			if (is[j]) S^=1LL<<id[j];
		}
		for (int j:era[i])
		{
			now--;
			if (is[j]) S^=1LL<<id[j];
		}
		if (last!=S)
		{
			t=vector<int>(cnt+1);
			for (auto [T,v]:a) if (!(~S&T)) t[__builtin_popcountll(S&T)]+=v;
		}
		for (int j=0;j<=cnt;j++) ans=(ans+1LL*t[j]*C(now-j,i-j)%p+p)%p;
	}
	print(ans);
	
	return 0;
}