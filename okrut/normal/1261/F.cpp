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

const ll mod = 998244353;

ll pot (ll a, int wyk)
{
	ll ret = 1LL;
	while (wyk>0)
	{
		if (wyk%2==1) ret = a* ret % mod;
		a = a*a % mod;
		wyk/=2;
	}
	return ret;
}
const int L = 61;
const int t = 20;
const int T = 1<<t;
vector <ll> A[2][L], Aux[2][L]; 
vector <pair <ll, ll> > dzialy;

void przelicz (int lvl, vector <ll> &w1, vector <ll> &w2)
{
	for (auto pp: w1) for (auto q: w2)
	{
		auto p = pp;
		int l = lvl;
		p -= p & ((1LL<<l)-1);
		q -= q & ((1LL<<l)-1);
		ll pref = p ^ q;
		
		//mamy juz to:
		dzialy.pb(mp(pref, pref+ (1LL<<l)));
	}
}

int main ()
{
	ll dwa = pot(2, mod-2);
	rep(k,0,2)
	{
		int n;
		scanf ("%d", &n);
		rep(i,0,n)
		{
			ll a, b;
			scanf ("%lld %lld", &a, &b);
			while (a<=b)
			{
				int l = 59;
				for (;l>0; l--) if ((a & ((1LL<<l)-1)) == 0LL)
				{
					if (a+(1LL<<l)<=b+1LL) break;
				}
				A[k][l].pb(a);
				a+=(1LL<<l);
			}
		}
		
		rep(i,0,60)
		{
			if (!A[k][i].empty())
			{
				//kompresja
				sort(A[k][i].begin(), A[k][i].end());
				vector <ll> rob;
				rob.pb(A[k][i][0]);
				rep(j,1,(int)A[k][i].size()) if (A[k][i][j-1] < A[k][i][j])
				{
					rob.pb(A[k][i][j]);
				}
				A[k][i] = rob;
			}
			
			//add Auxilary stuff
			for (ll x: A[k][i])
			{
				rep(j,i+1,60) 
				{
					ll pref = x;
					pref -= x & ((1LL<<j)-1);
					Aux[k][j].pb(pref);
				}
			}
			
			if (!Aux[k][i].empty())
			{
				//kompresja
				sort(Aux[k][i].begin(), Aux[k][i].end());
				vector <ll> rob;
				rob.pb(Aux[k][i][0]);
				rep(j,1,(int)Aux[k][i].size()) if (Aux[k][i][j-1] < Aux[k][i][j])
				{
					rob.pb(Aux[k][i][j]);
				}
				Aux[k][i] = rob;
			}
			
		}
	}
	
	
	dzialy.reserve(1000000);
	
	rep(l,0,60) 
	{
		przelicz(l, A[1][l], Aux[0][l]);
		przelicz(l, A[0][l], Aux[1][l]);
		przelicz(l, A[0][l], A[1][l]);
	}
	
	
	sort(dzialy.begin(), dzialy.end());
	
	ll res = 0LL, from = 0LL;
	for (auto p: dzialy)
	{
		p.fi = max(p.fi, from);
		if (p.se>p.fi)
		{
			res+= (p.fi + p.se-1LL) % mod * ((p.se-p.fi) % mod) % mod * dwa % mod;
			res%=mod;
		}
		from = max(from, p.se);
	}
	printf ("%lld\n", res);
}