#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std; 
typedef long long ll;
typedef long double ld;

const int N = 2e5+100;
vector <pair <int,ll> > Rec[N];

int main ()
{
	int n;
	scanf ("%d", &n);
	vector <pair <pair <ll, ll>, ll> > tab(n);
	for (auto &p: tab) scanf ("%lld %lld %lld", &p.fi.fi, &p.fi.se, &p.se);
	
	
	ll GCD = 0;
	for (auto p: tab) GCD = __gcd(GCD, p.se);
	
	int X = 1;
	set <ll> wor;
	map <ll, int> mapa;
	for (auto p: tab) wor.insert(p.fi.fi);
	for (ll x: wor) 
	{
		mapa[x] = X++;
	}
	for (auto &p: tab) p.fi.fi = mapa[p.fi.fi];
	
	int Y = 1;
	wor.clear();
	mapa.clear();
	for (auto p: tab) wor.insert(p.fi.se);
	for (ll y: wor) 
	{
		mapa[y] = Y++;
	}
	for (auto &p: tab) p.fi.se = mapa[p.fi.se];
	
	for (auto p: tab)
	{
		Rec[p.fi.fi].pb({p.fi.se, p.se});
	}
	
	rep(i,1,X) sort(Rec[i].begin(), Rec[i].end());
	rep(i,2,X) 
	{
		if (Rec[i].size() != Rec[i-1].size())
		{
			printf ("0\n");
			return 0;
		}
		rep(j,0,(int)Rec[i].size()) if (Rec[i][j].fi!=Rec[i-1][j].fi)
		{
			printf ("0\n");
			return 0;
		}
	}
	
	vector <ll> R;
	ll g = 0;
	for (auto p: Rec[1])
	{
		g = __gcd(g, p.se);
		R.pb(p.se);
	}
	for (auto &r: R) r/=g;
	
	rep(i,2,X)
	{
		vector <ll> Q;
		ll q = 0;
		for (auto p: Rec[i])
		{
			q = __gcd(q, p.se);
			Q.pb(p.se);
		}
		for (auto &r: Q) r/=q;
		
		rep(j,0,(int)Q.size()) if (R[j]!=Q[j])
		{
			printf ("0\n");
			return 0;
		}
	}
	
	int res = 0;
	for (ll p = 1; p*p <=GCD; p++)
	{
		if (GCD % p ==0LL)
		{
			if (GCD > p*p) res+=2;
			else res++;
		}
	}
	printf ("%d\n", res);
}