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


int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	if (n==1)
	{
		printf ("0\n");
		return 0;
	}
	vector <int> wek(n);
	for (int &x: wek) scanf ("%d", &x);
	
	set <int> wor;
	rep(i,1,n+1) wor.insert(i);
	
	
	for (int x: wek) if (x>0)
	{
		wor.erase(x);
	}
	
	vector <int> parz, nparz;
	for (int x: wor) 
	{
		if (x%2==0) parz.pb(x);
		else nparz.pb(x);
	}
	
	vector <pair <int, int> > niezer;
	vector <int> br[2];
	
	rep(i,0,n) if (wek[i]!=0)
	{
		niezer.pb(mp(wek[i]%2, i));
	}
	
	if ((int)niezer.size()<=1)
	{
		printf ("1\n");
		return 0;
	}
	
	int res = 0;
	rep(i,1,(int)niezer.size())
	{
		if (niezer[i].fi==niezer[i-1].fi)
		{
			br[niezer[i].fi].pb(niezer[i].se - niezer[i-1].se-1);
		}
		else res++;
	}
	//latamy te pomiedzy
	int ile[2] = {(int)parz.size(), (int)nparz.size()};
	rep(i,0,2)
	{
		sort(br[i].begin(),br[i].end());
		
		for (int x: br[i])
		{
			if (x>ile[i]) res+=2;
			else ile[i]-=x;
		}
	}
	
	//koncowki
	pair <int, int> F, L;
	F = niezer[0];
	L = niezer.back();
	L.se = n-1 - L.se;
	
	if (ile[F.fi] < F.se) 
	{
		res++;
	}
	else ile[F.fi]-=F.se;
	
	if (ile[L.fi] < L.se) res++;
	
	printf ("%d\n", res);
}