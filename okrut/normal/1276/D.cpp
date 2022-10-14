#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353LL;
const int N = 2e5+10;
vector <int> L[N], R[N];
vector <int> kol;
vector <pair <int, int> > graf[N];
ll przed[N], po[N], gora[N], nie[N];

ll turn (ll a)
{
	int k = mod-2;
	ll ret = 1;
	a%=mod;
	while (k>0)
	{
		if (k%2==1) ret = ret * a % mod;
		a = a*a % mod;
		k/=2;
	}
	return ret;
}

void dfs (int a, int ind)
{
	for (auto s: graf[a])
	{
		if (s.se < ind)
		{
			L[a].pb(s.fi);
			dfs(s.fi, s.se);
		}
		if (s.se > ind)
		{
			R[a].pb(s.fi);
			dfs(s.fi, s.se);
		}
	}
	kol.pb(a);
}

int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,1,n)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(mp(b,i));
		graf[b].pb(mp(a,i));
	}
	
	rep(i,1,n+1)
	{
		sort(graf[i].begin(), graf[i].end(), [](pair <int, int> a, pair <int, int>b){return a.se < b.se;});
	}
	dfs(1, 0);
	
	for (int v: kol)
	{
		//policz przed
		ll ilo = 1LL;
		for (int s: R[v]) ilo = ilo * (przed[s] + po[s] + nie[s]) % mod;
		for (int s: L[v]) ilo = ilo * (przed[s] + po[s] + nie[s]) % mod;
		
		for (int s: L[v])
		{
			ilo = ilo * turn(przed[s] + po[s] + nie[s]) % mod;
			przed[v] += ilo * (po[s] + nie[s]) % mod;
			ilo = ilo * (przed[s] + gora[s]) % mod;
		}
		przed[v] %=mod;
		
		//policz po
		ilo = 1LL;
		for (int s: L[v]) ilo = ilo * (przed[s] + gora[s]) % mod;
		for (int s: R[v]) ilo = ilo * (przed[s] + po[s] + nie[s]) % mod;
		for (int s: R[v])
		{
			ilo = ilo * turn (przed[s] + po[s] + nie[s]) % mod;
			po[v] += ilo * (po[s] + nie[s]) % mod;
			ilo = ilo * (przed[s] + gora[s]) % mod;
		}
		po[v]%=mod;
		
		//policz gora
		ilo = 1LL;
		for (int s: L[v]) ilo = ilo * (przed[s] + gora[s]) % mod;
		for (int s: R[v]) ilo = ilo * (przed[s] + po[s] + nie[s]) % mod;
		gora[v] = ilo;
		
		//policz nie
		ilo = 1LL;
		for (int s: L[v]) ilo = ilo * (przed[s] + gora[s]) % mod;
		for (int s: R[v]) ilo = ilo * (przed[s] + gora[s]) % mod;
		nie[v] = ilo;
	}
	
	printf ("%lld\n", (po[1] + nie[1]) % mod);
}