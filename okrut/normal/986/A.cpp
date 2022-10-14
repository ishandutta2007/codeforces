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

const int N = 1e5+100;
const int inf = 1e6;
vector <int> graf[N], dists[N];
int good[N];

int main ()
{
	int n, m, k, s;
	scanf ("%d %d %d %d", &n, &m, &k, &s);
	rep(i,1,n+1) scanf ("%d", &good[i]);
	
	rep(i,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	rep(g,1,k+1)
	{
		queue <int> kol;
		vector <int> dist(n+1, inf);
		rep(i,1,n+1) if (good[i]==g)
		{
			dist[i] = 0;
			kol.push(i);
		}
		
		while (!kol.empty())
		{
			int v = kol.front();
			kol.pop();
			for (int u: graf[v]) if (dist[u] > dist[v]+1)
			{
				dist[u] = dist[v] +1;
				kol.push(u);
			}
		}
		
		rep(i,1,n+1) dists[i].pb(dist[i]);
	}
	
	rep(i,1,n+1)
	{
		sort(dists[i].begin(), dists[i].end());
		int res= 0;
		rep(j,0,s) res += dists[i][j];
		printf ("%d ", res);
	}
	printf ("\n");
}