#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1<<16;
const int K=20;
const int p=998244353;
const int inv2=(p+1)/2;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,ll b)
{
	int ret=1;
	for (;b;a=1LL*a*a%p,b/=2) if (b&1) ret=1LL*ret*a%p;
	return ret;
}
int a[N],inv[K],fact[K],invf[K];
map<vector<int>,int>mp;
vector<int>ln(vector<int>f)
{
	assert(f[0]==1);
	int n=f.size();
	vector<int>g(n);
	g[0]=0;
	for (int i=1;i<n;i++)
	{
		g[i]=f[i];
		for (int j=1;j<=i;j++)
		g[i]=(g[i]-1LL*inv[i]*f[j]%p*g[i-j]%p*(i-j)%p+p)%p;
	}
	return g;
}
vector<int>exp(vector<int>f)
{
	assert(f[0]==0);
	int n=f.size();
	vector<int>g(n);
	g[0]=1;
	for (int i=1;i<n;i++)
	for (int j=0;j<i;j++)
	g[i]=(g[i]+1LL*inv[i]*g[j]%p*f[i-j]%p*(i-j))%p;
	return g;
}
vector<int> operator +(vector<int>a,vector<int>b)
{
	assert(a.size()==b.size());
	vector<int>ret(a.size());
	for (int i=0;i<(int)a.size();i++) ret[i]=(a[i]+b[i])%p;
	return ret;
}
vector<int> operator *(vector<int>a,int b)
{
	vector<int>ret(a.size());
	for (int i=0;i<(int)a.size();i++) ret[i]=1LL*a[i]*b%p;
	return ret;
}
void fwt(vector<int>&a,int n,int type)
{
	for (int mid=1;mid<(1<<n);mid*=2)
	for (int len=mid*2,k=0;k<(1<<n);k+=len)
	for (int i=0;i<mid;i++)
	{
		int x=a[k^i],y=a[k^i^mid];
		a[k^i]=(x+y)%p;
		a[k^i^mid]=(x-y+p)%p;
		if (type<0)
			a[k^i]=1LL*a[k^i]*inv2%p,
			a[k^i^mid]=1LL*a[k^i^mid]*inv2%p;
	}
}

signed main()
{
	inv[0]=inv[1]=1;
	for (int i=2;i<=16;i++) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
	for (int i=fact[0]=1;i<=16;i++) fact[i]=1LL*fact[i-1]*i%p;
	for (int i=invf[0]=1;i<=16;i++) invf[i]=1LL*invf[i-1]*inv[i]%p;
	int n=read(),k=read(),c=read(),sum=0;
	for (int i=1;i<=n;i++)
	{
		sum^=a[i]=read();
		vector<int>tmp;
		for (int j=0;j<=k;j++) tmp.push_back(a[i]^(a[i]-j));
		mp[tmp]++;
	}
	vector<vector<int>>Ln(1<<k,vector<int>(k+1));
	for (int S=0;S<(1<<k);S++)
	{
		vector<int>now(k+1);
		now[0]=1;
		for (int i=0;i<k;i++) now[i+1]=((S>>i&1)?1LL:p-1LL)*invf[i+1]%p;
		Ln[S]=ln(now);
	}
	vector<vector<int>>s(1<<c,vector<int>(k+1));
	for (auto [d,tot]:mp)
	{
		vector<int>a(1<<c);
		for (int i=1;i<=k;i++)
		for (int j=0;j<(1<<c);j++) a[j]|=(__builtin_popcount(j&d[i])%2==0)<<(i-1);
		for (int i=0;i<(1<<c);i++) s[i]=s[i]+Ln[a[i]]*tot;
	}
	vector<int>ans(1<<c);
	for (int i=0;i<(1<<c);i++)
	{
		s[i]=exp(s[i]);
		ans[i]=1LL*s[i][k]*fact[k]%p;
	}
	fwt(ans,c,-1);
	int P=power(n,1LL*k*(p-2));
	vector<int>res(1<<c);
	for (int i=0;i<(1<<c);i++) res[sum^i]=1LL*ans[i]*P%p;
	for (int i=0;i<(1<<c);i++) print(res[i]," \n"[i+1==(1<<c)]);
	
	return 0;
}