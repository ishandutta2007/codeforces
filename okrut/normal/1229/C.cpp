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

const int N = 1e5+1;
vector <int> graf[N]; //mam tylko wychodzace
ll indeg[N], outdeg[N];

int main ()
{
	int n, m, q;
	scanf ("%d %d", &n, &m);
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		if (a>b) swap(a,b);
		graf[a].pb(b);
		outdeg[a]++;
		indeg[b]++;
	}
	ll stan = 0;
	rep(i,1,n+1) stan+=indeg[i] * outdeg[i];
	
	scanf ("%d", &q);
	printf ("%lld\n", stan);
	rep(co,0,q)
	{
		int v;
		scanf ("%d", &v);
		for (int w: graf[v])
		{
			graf[w].pb(v);
			stan-=indeg[w]*outdeg[w];
			indeg[w]--;
			outdeg[w]++;
			stan+=indeg[w]*outdeg[w];
		}
		graf[v].clear();
		stan-=indeg[v]*outdeg[v];
		indeg[v]+=outdeg[v]; //wszystkie pokazuja na v
		outdeg[v] = 0;
		printf ("%lld\n", stan);
	}
}