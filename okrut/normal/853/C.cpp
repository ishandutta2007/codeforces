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
typedef pair <int, int> pii;
const int N = 2e5+10;
const int T = 1<<19;

int tree[T+T];
void mark (int a)
{
	a+=T;
	while (a>0)
	{
		tree[a]++;
		a/=2;
	}
}
ll query (int l, int r)
{
	l+=T;
	r+=T;
	int ret = 0;
	while (l<r)
	{
		if (l % 2 ==1) ret += tree[l];
		if (r%2==0) ret += tree[r];
		l = (l+1)/2;
		r = (r-1)/2;
	}
	if (l==r) ret += tree[l];
	return ret;
} 
ll Res[N];
int L[N], R[N], D[N], U[N];
int n;
void policz (vector <pair <int, int> > &pkt, vector <pair <pii, pii> > &ask, bool y = false)
{
	
	debug ("\nnext angle\n");	
	
	if (y) for (auto &p: pkt) swap(p.fi, p.se);
	
	sort(pkt.begin(), pkt.end());
	sort(ask.begin(), ask.end());
	
	rep(i,0,T+T) tree[i] = 0;
	
	auto p = pkt.begin();
	auto a = ask.begin();
	ll suma = 0;
	
	//for (auto p: ask) debug ("%d %d %d %d\n", p.fi.fi, p.fi.se, p.se.fi, p.se.se);
	
	rep(x,1,n+1)
	{
		while (a!=ask.end() && a->fi.fi==x)
		{
			ll minus = (suma * (suma-1));
			ll r1 = query(0, a->se.fi-1), r2 =  query(a->se.se+1, n);
			ll plus = r1 * (r1-1) + r2 * (r2-1);
			
			debug ("query %d: -%lld + %lld\n", a->fi.se, minus, plus/2LL);
			
			Res[a->fi.se] -= minus;
			Res[a->fi.se] += plus/2LL;
			a++;
		}
		
		while (p!=pkt.end() && p->fi==x)
		{
			mark(p->se);
			suma++;
			p++;
		}
	}
	
	if (y) for (auto &g: pkt) swap(g.fi, g.se);
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int q;
	scanf ("%d %d", &n, &q);
	
	vector <pii> pkt;
	rep(x,1,n+1)
	{
		int y;
		scanf ("%d", &y);
		pkt.pb({x, y}); 
	}
	
	rep(i,0,q) scanf ("%d %d %d %d", &L[i], &D[i], &R[i], &U[i]);
	
	rep(i,0,q) Res[i] = (ll(n) * ll(n-1));
	
	vector <pair <pii, pii> > ask(q);
	
	rep(i,0,q) ask[i] = { { L[i], i}, {D[i], U[i]} };
	
	policz(pkt, ask);
	
	rep(i,0,q) ask[i] = { { D[i], i}, {L[i], R[i]} };
	
	policz(pkt, ask, true);
	
	rep(i,0,q) 
	{
		debug ("mamy %d\n", R[i]);
		ask[i] = { { n+1 - R[i], i}, {D[i], U[i]} };
	}
	for (auto &p: pkt) p.fi = n+1 - p.fi;
	
	policz(pkt, ask);
	
	rep(i,0,q) ask[i] = { { n+1 - U[i], i}, {L[i], R[i]}};
	
	for (auto &p: pkt)
	{
		p.fi = n+1 - p.fi;
		p.se = n+1 - p.se;
	}
	
	policz(pkt, ask, true);
	
	rep(i,0,q) printf ("%lld\n", Res[i]/2LL);
}