#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;

vector <vector <int> > graf;

int s, g;
int n, k;
vector <bool> vst;
void dfs (int a)
{
	vst[a] = false;
	if (a <=n) s++;
	else g++;
	for (int p: graf[a]) if (vst[p]) dfs(p);
}

int main ()
{
	scanf ("%d %d", &n, &k);
	graf.resize(n+k+1);
	vst.resize(n+k+1, true);
	
	int x, y;
	rep(i,1,k+1)
	{
		scanf ("%d %d", &x, &y);
		graf[x].pb(n+i);
		graf[y].pb(n+i);
		graf[n+i].pb(x);
		graf[n+i].pb(y);
	}
	int res = 0;
	rep(i,1,n+1) if (vst[i])
	{
		s = 0;
		g = 0;
		dfs(i);
		res+=s-1;
		debug ("snack %d: %d %d\n", i, s, g);
	}
	printf ("%d\n", k-res);
}