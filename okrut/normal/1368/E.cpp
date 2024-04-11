#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int t;
	scanf ("%d", &t);
	
	rep(q,0,t)
	{
		int n, m;
		scanf ("%d %d", &n, &m);
		vector <bool> on(n+1, true);
		vector <vector <int> > go(n+1);
		vector <int> ans, Gs(n+1, 0), indeg(n+1, 0);
		
		rep(i,0,m)
		{
			int x, y;
			scanf ("%d %d", &x, &y);
			go[x].pb(y);
			indeg[y]++;
		}
		
		rep(v,1,n+1) if (on[v])
		{
			for (int s: go[v])
			{
				for (int gs: go[s])
				{
					Gs[gs]++;
				}
			} 
		}
		
		
		rep(v,1,n+1) if (Gs[v]>0)
		{
			ans.pb(v);
			
			for (int s: go[v])
			{
				for (int gs: go[s])
				{
					Gs[gs]--;
				}
			}
			
			for (int s: go[v])
			{
				Gs[s]-=indeg[v];
				indeg[s]--;
			}
		}
		
		int k  = ans.size();
		
		assert(k*7 <= 4*n);
		
		printf ("%d\n", (int)ans.size());
		for (int v: ans) printf ("%d ", v);
		printf ("\n");
	}
	
}