#pragma GCC optimize "O3"
#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 998244353;
const int N = 2e5+100;
const int L = 30;


vector <int> graf[N*L];
pair <int, int> Dist[N*L];

// is a < b
bool cmp (const pair <int, int> &a, const pair <int, int> &b)
{
	if (a.fi==b.fi) return a.se < b.se;
	
	if (a.fi<20 and b.fi<20) {
		return (a.se + (1<<a.fi) < b.se + (1<<b.fi)); 
	}
	
	return a.fi < b.fi;
}

bool good_cmp (const pair  <pii, int> &a, const pair <pii, int> &b)
{	
	if (cmp(a.fi, b.fi)) return true;
	if (cmp(b.fi, a.fi)) return false;
	return a.se < b.se;
}

ll calc(pii a) 
{
	ll res = a.se;
	ll len = 1;
	
	rep(i,0,a.fi) 
	{
		res += len;
		res%=mod;
		len = len*2LL % mod;
	}
	return res%mod;
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m;
	scanf ("%d %d", &n, &m);
	
	rep(e,0,m)
	{
		int a, b;
		scanf ("%d %d", &a, &b);
		
		rep(i,0,L) {
			if (i&1) {
				graf[b*L+i].pb(a*L+i);
			} else {
				graf[a*L+i].pb(b*L+i);
			}
		}
	}
	
	set <pair <pii, int> , bool(*)(const pair <pii, int> &lhs, const pair <pii, int> &rhs)> kol(&good_cmp);
	
	
	rep(i,0,N*L) Dist[i].fi = N;
	
	kol.insert({ {0,0}, L});
	Dist[L] = {0,0};
	
	while (!kol.empty()) 
	{
		auto p = *kol.begin();
		kol.erase(p); //kol.pop();
		
		if (cmp(Dist[p.se],p.fi)) continue;
		
		if ( (p.se/L) == n) {
			printf ("%lld\n", calc(p.fi));
			return 0;
		}
		
		int v = p.se;
		
		debug ("Processing %d with <%d, %d>\n", v, p.fi.fi, p.fi.se);
		
		auto q = p.fi;
		q.fi++;
		
		int nxt;
		
		
		if (q.fi<L-2) {
			nxt = v+1;
		} else {
			nxt = v^1;
		}
		
		
		if (cmp(q,Dist[nxt])) {
			Dist[nxt] = q;
			debug ("Goto %d with <%d %d>\n", nxt, q.fi, q.se);
			kol.insert({q, nxt});
		}
		
		for (int s: graf[v]) {
			q = p.fi;
			q.se++;
			debug ("Goto %d\n", s);
			if (cmp(q, Dist[s])) {
				Dist[s] = q;
				kol.insert({q, s});
			}
		}
	}
	
	assert(0);
	
}