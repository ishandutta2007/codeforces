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

const int N = 5e5;
int Res[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, k;
	scanf ("%d %d", &n, &k);
	vector <ll> tab(n);
	for (auto &p: tab)
	{
		scanf ("%lld", &p);
	}
	
	priority_queue <pair <ll, int> > wor;
	
	ll res = 0;
	
	rep(i,0,k) 
	{
		wor.push({tab[i], i});
	}
	
	rep(i,k,n+k)
	{
		if (i<n) wor.push({tab[i], i});
		
		auto p = wor.top();
		wor.pop();
		
		res += ll(i - p.se) * p.fi;
		
		Res[p.se] = i+1;
	}
	
	printf ("%lld\n", res);
	rep(i,0,n) printf ("%d ", Res[i]);
	printf ("\n");
}