#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+4;
int Sub[N];
vector <int> graf[N];
vector <ll> cities;

void dfs0 (int a, int b, int d)
{
	Sub[a] = 1;
	for (int s: graf[a]) if (s!=b)
	{
		dfs0(s, a, d+1);
		Sub[a]+=Sub[s];
		
	}
	
	cities.pb(Sub[a] - d);
}


int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, k;
	scanf ("%d %d", &n, &k);
	rep(i,1,n)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	dfs0(1,0,1);
	
	sort(cities.begin(), cities.end());
	
	ll res = 0;
	
	while ((int)cities.size() > k)
	{
		res += cities.back();
		cities.pop_back();
	}
	printf ("%lld\n", res);
	
}