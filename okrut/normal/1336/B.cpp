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
		int r, g, b;
		scanf ("%d %d %d", &r, &g, &b);
		vector <ll> tab[3];
		vector <int> ord(3);
		rep(i,0,3) ord[i] = i;
		
		tab[0].resize(r); tab[1].resize(g); tab[2].resize(b);
		
		rep(i,0,3) 
		{
			for (ll &x: tab[i]) scanf ("%lld", &x); 
			sort(tab[i].begin(), tab[i].end());
		}
		
		ll best = 3.4e18;
		
		do{
			
			int i = ord[0], j = ord[1], k = ord[2];
			for (ll x: tab[i])
			{
				auto yt = lower_bound(tab[j].begin(), tab[j].end(), x);
				if (yt==tab[j].end()) break;
				ll y = *yt;
				auto zt = lower_bound(tab[k].begin(), tab[k].end(), x);
				if (zt!=tab[k].begin() and (zt==tab[k].end() or *zt > x)) zt--;
				ll z= *zt;
				
				ll curr = (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z);
				
				best = min(best, curr);
				
			}
			
		}while(next_permutation(ord.begin(), ord.end()));
		
		printf ("%lld\n", best);
	}
	
}