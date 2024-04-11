// Author: Little09
// Problem: E2. Rubik's Cube Coloring (hard version)
// Contest: Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/E2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];
map<string,int>p;
map<ll,ll>dp[6];
map<ll,int>ppp;
map<ll,bool>used;
ll d[N];
set<ll>s;
inline ll dis(ll x)
{
	ll res=0;
	while (x) x/=2,res++;
	return res;
}
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
	cin >> n >> m;
	d[1]=6;
	ll tmp=ksm(9,mod-2),tm=ksm(3,mod-2);
	for (int i=2;i<=60;i++)
	{
		d[i]=24*d[i-1]%mod*d[i-1]%mod*tmp%mod;
	}
	p["white"]=0,p["yellow"]=5;
	p["green"]=1,p["blue"]=4;
	p["red"]=2,p["orange"]=3;
	for (int i=1;i<=m;i++)
	{
		ll x;
		string y;
		cin >> x >> y;
		int z=p[y];
		s.insert(-x);
		ppp[x]=z+1;
	}
	s.insert(-1);
	while (!s.empty())
	{
		ll u=-*s.begin();
		s.erase(s.begin());
		//cout << u << endl;
		if (used[u]) continue;
		used[u]=1;
		if (u!=1) s.insert(-(u/2));
		ll o=dis(u);
		if (o==n)
		{
			dp[ppp[u]-1][u]=1;
			continue;
		}
		//cout << u << endl;
		for (int i=0;i<6;i++)
		{
			if (ppp[u]!=0&&i!=ppp[u]-1) continue;
			//cout << n-o << endl;
			ll res=0;
			if (used[u*2])
			{
				for (int j=0;j<6;j++)
				{
					if (i!=j&&i+j!=5) res=(res+dp[j][u*2])%mod;
				}	
			}
			else
			{
				res=d[n-o]*2%mod*tm%mod;
			}
			//cout << n-o << endl;
			ll resy=0;
			if (used[u*2+1])
			{
				for (int j=0;j<6;j++)
				{
					if (i!=j&&i+j!=5) resy=(resy+dp[j][u*2+1])%mod;
				}	
			}
			else
			{
				resy=d[n-o]*2%mod*tm%mod;
			}
			//cout << n-o << endl;
			dp[i][u]=res*resy%mod;
		}
	}
	ll ans=0;
	for (int i=0;i<6;i++) ans=(ans+dp[i][1])%mod;
	cout << ans;
	return 0;
}