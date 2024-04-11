#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
typedef std::string str;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/

const int MAXN = 200011,mod = 998244353;
char s[MAXN];
ll fac[MAXN],inv[MAXN];
ll C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
void init(int n)
{
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=n;++i)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;++i)inv[i]=inv[i-1]*inv[i]%mod;
}
int main()
{
	init(2e5);
	int task=read();
	while(task--)
	{
		int n=read(),c0=0,cp=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
			if(s[i]=='0')++c0;
			else if(s[i]=='1'&&s[i+1]=='1')++cp,++i;
		if(cp==0)puts("1");
		else printf("%lld\n",C(c0+cp,cp));
	}
	return 0;
}