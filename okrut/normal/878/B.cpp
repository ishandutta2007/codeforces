#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	int n, k, m;
	vector <pair <int, int> > tab;
	int a;
	scanf ("%d %d %d", &n, &k, &m);
	pair <int,int> curr = mp(-1,0);
	
	rep(i,0,n)
	{
		scanf ("%d", &a);
		if (curr.fi==a) curr.se++;
		else 
		{
			if (curr.se%k!=0) tab.pb(mp(curr.fi, curr.se%k));
			else
			{
				if (!tab.empty() && tab.back().fi==a) 
				{
					curr = tab.back();
					tab.pop_back();
					curr.se++;
					continue;
				}
			}
			curr.fi = a;
			curr.se = 1;
		}
	}
	
	if (curr.se%k!=0) tab.pb(mp(curr.fi, curr.se%k));
	
	if (m==1)
	{
		int sum = 0;
		for (auto p: tab) sum+=p.se;
		printf ("%d\n", sum);
		return 0;
	}
	
	ll prefsum = 0;
	ll sufsum = 0;
	ll insum = 0;
	ll prem = 0;
	
	int l = 0, r = (int)tab.size()-1;
	while (l<r)
	{
		if (tab[l].fi==tab[r].fi)
		{
			int x = tab[l].se+tab[r].se;
			if (x%k==0) {
				l++;
				r--;
			}
			else 
			{
				prem = (x/k) * k;
				break;
			}
		}
		else break;
	}
	
	debug ("%d: %d %d\n", (int)tab.size(), l, r);
	
	
	rep(i,0,(int)tab.size())
	{
		if (i<l) prefsum+=tab[i].se;
		else if (i>r) sufsum+=tab[i].se;
		else insum+=tab[i].se;
	}
	
	debug ("%lld %lld %lld %lld\n", insum, prefsum, sufsum, prem);
	ll res;
	if (l==r)
	{
		insum*=ll(m);
		insum%=ll(k);
		res = prefsum+insum+sufsum;
		
		if (insum==0LL) res = 0;
	}
	else res = prefsum+sufsum + ll(m) * insum - ll(m-1) * prem;
	
	printf ("%lld\n", res);
}