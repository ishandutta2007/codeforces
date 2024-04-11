// Author: Little09
// Problem: F. Intersection and Union
// Contest: Educational Codeforces Round 137 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1743/problem/F
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
vector<int>a[N],b[N];
multiset<int>s;
ll ksm(ll x,ll y)
{
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
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int l,r;
		cin >> l >> r;
		a[l].push_back(i),b[r].push_back(i);
	}
	ll al=ksm(3,n-1),p=ksm(3,mod-2)*2%mod;
	ll ans=0;
	for (int i=0;i<=300000;i++)
	{
		for (int j:a[i]) s.insert(j);
		if (!s.empty()) ans=(ans+ksm(p,min(n-*s.rbegin()+1,n-1)))%mod;
		for (int j:b[i]) s.erase(s.find(j));
	}
	ans=ans*al%mod;
	cout << ans;
	return 0;
}