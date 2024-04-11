// Author: Little09
// Problem: D. Counting Arrays
// Contest: Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1749/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000005; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=300005;
ll n,m; 
int a[N];

ll ksm(ll x,ll y)
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	ll res=m%mod,ans=0,sum=m%mod,tot=1;
	for (int i=1;i<=n;i++) ans=(ans+ksm(m,i))%mod;
	for (int i=2;i<=n;i++)
	{
		if (a[i]==0) tot*=i;
		if (tot>m) break;
		res=res*((m/tot)%mod)%mod,sum=(sum+res)%mod;
		if (a[i]==0) for (int j=2;i*j<=n;j++) a[i*j]=1;
	}
	cout << (ans-sum+mod)%mod;
	return 0;
}