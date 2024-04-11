// LUOGU_RID: 90593071
// Author: Little09
// Problem: CF756E Byteland coins
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF756E
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7,inf=1e9+1,bas=100000000;
const int N=3e5+10;
int n;
int a[N],c[N],len,d[N],L=1;
char M[N];
ll dp[N],f[N],s[N],b[N];
int DIV(int x)
{
	if (L>len) return 0;
	int res=0;
	for (int i=L;i<=len;i++)
	{
		ll u=1ll*res*bas+b[i];
		b[i]=u/x;
		res=u%x;
	}
	while (b[L]==0&&L<=len) L++;
	return res;
}
ll num()
{
	if (L>len) return 0;
	ll res=0;
	for (int i=L;i<=len;i++)
	{
		res=res*bas+b[i];
		if (res>inf)
		{
			cout << 0;
			exit(0);
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=2;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> d[i];
	cin >> (M+1);
	len=strlen(M+1);
	a[1]=1;
	int l=(len+7)/8,tot=1;
	for (int i=len;i>=1;i--)
	{
		b[l]+=(M[i]-'0')*tot;
		tot*=10;
		if (tot==bas) l--,tot=1;
	}
	len=(len+7)/8;
	for (int i=2;i<=n;i++) 
	{
		if (a[i]!=1) c[i]=DIV(a[i]);
		if (L>len) n=i;
	}
	// for (int i=1;i<=len;i++) cout << b[i] << " ";
	// cout << endl;
	int lim=0,laslim=0;
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		lim=laslim/a[i]+d[i];
		for (int j=0;j<=lim;j++) f[j]=0;
		for (int j=c[i];j<=laslim;j+=a[i]) f[j/a[i]]=dp[j];
		for (int j=1;j<=lim;j++) f[j]=(f[j]+f[j-1])%mod;
		for (int j=0;j<=lim;j++) 
		{
			if (j-d[i]-1>=0) dp[j]=(f[j]-f[j-d[i]-1]+mod)%mod;
			else dp[j]=f[j];
		}
		laslim=lim;
	}
	ll res=num();
	if (res>lim)
	{
		cout << 0;
		return 0;
	}
	cout << dp[res] << endl;
	return 0;
}