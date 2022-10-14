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

const int M = 1e6;
vector <pair <int, int> > pkt[4], wszp;
vector <int> ind[4], wszi;

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n;
	scanf ("%d", &n);
	rep(i,0,n)
	{
		pair <int, int> p;
		scanf ("%d %d", &p.fi, &p.se);
		p.fi += M;
		p.se += M;
		
		int gr = (p.fi & 1) *2 + (p.se & 1);
		pkt[gr].pb(p);
		ind[gr].pb(i+1);
	}
	
	for (;;)
	{
		int pel = 0;
		rep(i,0,4) if ((int)ind[i].size() > 0) pel++;
		if (pel > 1) break;
		
		wszp.clear();
		wszi.clear();
		
		rep(i,0,4) rep(j,0,(int)ind[i].size())
		{
			wszi.pb(ind[i][j]);
			wszp.pb(pkt[i][j]);
		}
		
		rep(i,0,4)
		{
			ind[i].clear();
			pkt[i].clear();
		}
		
		rep(i,0,n)
		{
			auto p = wszp[i];
			p.fi/=2;
			p.se/=2;
			
			int gr = (p.fi & 1) * 2 + (p.se & 1);
			pkt[gr].pb(p);
			ind[gr].pb(wszi[i]);
		}
	}
	
	
	
	if ( (int)ind[0].size() + (int)ind[3].size() > 0 && (int)ind[1].size() + (int)ind[2].size() > 0)
	{
		printf ("%d\n", (int)ind[0].size() + (int)ind[3].size());
		for (int x: ind[0]) printf ("%d ", x);
		for (int x: ind[3]) printf ("%d ", x);
		printf ("\n");
		return 0;
	}
	
	for (int x: ind[1]) ind[0].pb(x);
	for (int x: ind[2]) ind[3].pb(x);
	
	printf ("%d\n", (int)ind[0].size());
	for (int x: ind[0]) printf ("%d ", x);
	printf ("\n");
}