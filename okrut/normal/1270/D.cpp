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

const int N = 504;
int tab[N];

pair <int, int> ask (vector <int> &wek)
{
	printf ("?");
	for (int x: wek) printf (" %d", x);
	printf ("\n");
	fflush(stdout);
	
	int a, b;
	scanf ("%d %d", &a, &b);
	tab[a] = b;
	return mp(a,b);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, k;
	scanf ("%d %d", &n, &k);
	
	/*
	if (k*2 <= n+1)
	{
		set <int> wor;
		rep(i,1,n+1) wor.insert(i);
		vector <int> zn;
		rep(i,0,k)
		{
			vector <int> wek;
			for (int x: wor) if ((int)wek.size() < k) wek.pb(x);
			auto p = ask(wek);
			wor.erase(p.fi);
			zn.pb(p.fi);
		}
		auto p = ask(zn);
		int m = 1;
		for (int x: zn) if (tab[x] < p.se) m++;
		printf ("! %d\n",m);
		return 0;
	}*/
	
	pair <int,int> zn1, zn2;
	vector <int> a1;
	rep(i,1,k+1) a1.pb(i);
	zn1 = ask(a1);
	a1.clear();
	rep(i,1,n+1) if (i!=zn1.fi && (int)a1.size() < k) a1.pb(i);
	zn2 = ask(a1);
	
	int l=0, r = 0;
	rep(i,0,k) if (a1[i]!=zn2.fi)
	{
		int c = a1[i];
		a1[i] = zn1.fi;
		
		auto p = ask(a1);
		
		if (zn1.se < zn2.se)
		{
			if (p == zn2) l++;
			else r++;
		}
		
		if (zn1.se > zn2.se)
		{
			if (p==zn2) r++;
			else l++;
		}
		a1[i] = c;
	}
	printf ("! %d\n", l+1);
}