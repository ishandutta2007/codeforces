// Author: Little09
// Problem: CF906D Power Tower
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF906D
// Memory Limit: 250 MB
// Time Limit: 4500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x&(-x))
const int N=100005;
int n,m; 
ll a[N],P;
map<int,int>phi;
int getphi(int x)
{
	int t=sqrt(x),res=x;
	for (int i=2;i<=t;i++)
	{
		if (x%i==0)
		{
			res=res/i*(i-1);
			while (x%i==0) x/=i;
		}
	}
	if (x>1) res=res/x*(x-1);
	return res;
}
ll ksm(ll x,ll y,ll mod)
{
	x%=mod;
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll query(int l,int r,ll p)
{
	ll u=a[l];
	if (u%p==0) return 0;
	if (l==r) return u%p;
	if (u==1) return 1;
	int ls=min(l+5,r);
	for (int i=l+1;i<=ls;i++) 
	{
		if (a[i]==1) 
		{
			ls=i;
			break;
		}
	}
	ll las=a[ls];
	for (int i=ls-1;i>=l+1;i--)
	{
		ll w=las,v=a[i];las=1;
		while (w--)
		{
			las=las*v;
			if (las>=phi[p]) return ksm(u,query(l+1,r,phi[p])+phi[p],p);
		}
	}
	return ksm(u,las,p);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> P;
	ll op=P;
	while (1)
	{
		phi[op]=getphi(op);
		if (op==1) break;
		op=phi[op];
	}
	for (int i=1;i<=n;i++) cin >> a[i];
	cin >> m;
	for (int i=1;i<=m;i++)
	{
		ll l,r;
		cin >> l >> r;
		cout << query(l,r,P) << endl;
	}
	return 0;
}