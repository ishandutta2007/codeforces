#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) // fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n; scanf ("%d", &n);
		
		vector <vector <int> > help(n+1);
		vector <int> dep(n+1, 0);
		
		set <int> kol;
		
		rep(i,1,n+1) {
			int k;
			scanf ("%d", &k);
			dep[i] = k;
			rep(j,0,k) {
				int a;
				scanf ("%d", &a);
				help[a].pb(i);
			}
			
			if (k == 0) kol.insert(i);	
		}
		
		int cnt = 0;
		int done = 0;
		
		while (done < n and !kol.empty()) {
			cnt++;
			
			debug ("\nReading %d\n", cnt);
			
			int c = 0;
			
			while (kol.upper_bound(c) != kol.end()) {
				c = *kol.upper_bound(c);
				done++;
				debug ("Got %d\n", c);
				for (int x: help[c]) if (!(--dep[x])) kol.insert(x);
				kol.erase(c);
			}
			

		}
		
		
		if (done == n) printf ("%d\n", cnt);
		else printf ("-1\n");
		
	}
}