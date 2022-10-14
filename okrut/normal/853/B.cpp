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
typedef pair <int, int> pii;
const int K = 1e6+100;
const ll inf = 1e12+100;
ll Left[K], Right[K]; //start/end at day

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	
	rep(i,0,K) Left[i] = Right[i] = ll(n) * inf;
	
	vector <pair < pii, pii > > tab(m);
	for (auto &p: tab) scanf ("%d %d %d %d", &p.fi.fi, &p.se.fi, &p.se.se, &p.fi.se);
	
	sort(tab.begin(), tab.end());
	
	ll cost = inf * ll(n);
	vector <ll> mem(n+1, inf);
	for (auto &p: tab) if (p.se.se==0)
	{
		int f = p.se.fi;
		ll c = p.fi.se;
		int t = p.fi.fi;
		
		cost -=mem[f];
		mem[f] = min(mem[f], c);
		cost += mem[f];
		
		Left[t] = cost;
	}
	
	reverse(tab.begin(), tab.end());
	
	cost = inf * ll(n);
	for (auto &p: mem) p = inf;
	
	for (auto &p: tab) if (p.se.fi==0)
	{
		int to = p.se.se;
		ll c = p.fi.se;
		int t = p.fi.fi;
		
		cost -=mem[to];
		mem[to] = min(mem[to], c);
		cost += mem[to];
		
		Right[t] = cost;
	}
	
	Left[0] = inf * ll(n);
	
	rep(i,1,K) Left[i] = min(Left[i-1], Left[i]);
	
	for (int i=K-1; i>0; i--) Right[i-1] = min(Right[i-1], Right[i]);
	
	ll res = inf;
	rep(i,0,K-k-1)
	{
		res = min(res, Left[i] + Right[i+k+1]);
	}
	
	if (res==inf) res = -1;
	printf ("%lld\n", res);
}