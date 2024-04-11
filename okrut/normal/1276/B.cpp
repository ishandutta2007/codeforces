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

const int N = 2e5+100;
vector <vector <int> > graf;
void dfs (int a, int b, int zkz, vector <int> &id)
{
	id[a] = b;
	for (int s: graf[a]) if (id[s]==-1 && s!=zkz) dfs(s, b, zkz, id);
}

int main ()
{
	int tests;
	scanf ("%d", &tests);
	rep(q,0,tests)
	{
		int n, m, f1, f2;
		graf.clear();
		scanf ("%d %d %d %d", &n, &m, &f1, &f2);
		graf.resize(n+1);
		rep(i,0,m)
		{
			int a, b;
			scanf ("%d %d", &a, &b);
			graf[a].pb(b);
			graf[b].pb(a);
		}
		vector <int> id1(n+1, -1), id2(n+1, -1), m1(n+1, 0), m2(n+1, 0);
		
		rep(i,1,n+1) if (i!=f1 && id1[i]==-1) dfs(i, i, f1, id1);
		rep(i,1,n+1) if (i!=f2 && id2[i]==-1) dfs(i,i, f2, id2);
		id1[f1] = f1;
		id2[f2] = f2;
		
		ll res = 0LL;
		rep(i,1,n+1) m1[id1[i]]++;
		rep(i,1,n+1) m2[id2[i]]++;
		map <pair <int, int>, int> mapa;
		rep(i,1,n+1) mapa[mp(id1[i], id2[i])] ++;
		
		rep(i,1,n+1) if (i!=f1 && i!=f2)
		{
			int ile = m1[id1[i]] + m2[id2[i]] - mapa[mp(id1[i], id2[i])];
			
			if (id2[f1]!=id2[i]) ile++;
			if (id1[f2]!=id1[i]) ile++; 
			
			res += ll(n - ile);
		}
		printf ("%lld\n", res/2LL);
	}
}