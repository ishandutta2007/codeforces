#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

int inw (vector <int> &tab)
{
	int n = tab.size();
	int res = 0;
	rep(i,0,n) rep(j,0,i) if (tab[j] > tab[i]) res++;
	return res; 
}

int main ()
{
	int t;
	scanf ("%d", &t);
	rep(q,0,t) {
		int n, m;
		scanf ("%d %d", &n, &m);
		vector <pair <int, int> > P(n*m);
		int czas = 0;
		for (auto &p: P) {
			scanf ("%d", &p.fi);
			p.se = ++czas;
		}
		
		sort(P.begin(), P.end());
		
		int res = 0;
		for (int l = 0; l < n*m; l += m) {
			int r = l + m - 1;
			
			vector <int> tab;
			
			for (int i = l; i <= r; i++) {
				int j;
				for (j = i; j < r and P[j+1].fi == P[i].fi; j++);
				
				for (int k = j; k >= i; k--) tab.pb(P[k].se);
				
				
				i = j;	
			}
			/*
			debug ("Places in row %d: ", l/m);
			for (int y: tab) debug ("%d ", y);
			debug ("\n");
			*/
			reverse(tab.begin(), tab.end());
				
			res += inw(tab);
		}
		
		printf ("%d\n", res);
	}
}