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

vector <ll> t;
vector <pair <ll, int> > delt, s;
vector <pair <pair <int, int>, ll> >op;
int main ()
{
	int n;
	scanf ("%d", &n);
	t.resize(n);
	s.resize(n);
	delt.resize(n);
	rep(i,0,n) 
	{
		scanf ("%lld", &s[i].fi);
		s[i].se = i;
	}
	rep(i,0,n) scanf ("%lld", &t[i]);
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	
	ll sum=0;
	rep(i,0,n)
	{
		delt[i].fi = t[i] - s[i].fi;
		delt[i].se = s[i].se;
		sum+=delt[i].fi;
		if (sum<0LL)
		{
			printf ("NO\n");
			return 0;
		}
	}
	if (sum!=0LL) 
	{
		printf ("NO\n");
		return 0;
	}
	
	vector <pair <int, ll> > dod;
	
	rep(i,0,n)
	{
		if (delt[i].fi>0LL) dod.pb(mp(delt[i].se, delt[i].fi));
		
		//teraz przesuwamy
		while (delt[i].fi<0LL)
		{
			if (dod.back().se+delt[i].fi<0LL)
			{
				op.pb(mp(mp(dod.back().fi, delt[i].se), dod.back().se));
				delt[i].fi+=dod.back().se;
				dod.pop_back();
			}
			else
			{
				op.pb(mp(mp(dod.back().fi, delt[i].se), -delt[i].fi));
				dod[(int)dod.size()-1].se+=delt[i].fi;
				delt[i].fi=0LL;
			}
		}
	}
	printf ("YES\n%d\n", (int)op.size());
	for (auto p: op) printf ("%d %d %lld\n", p.fi.fi+1, p.fi.se+1, p.se);
}