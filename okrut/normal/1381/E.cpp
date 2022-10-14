#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int inf = 1e8;
const ld eps = 1e-5;

vector <pair <ld, pair <int, ld> > > event; // [time, type, value] 0 - add constant, 1 - add change, 2 +  - query

void mark (pair <ld, pair <int, ld> > p)
{
	debug ("mark[%.2Lf] -> %d %Lf\n", p.fi, p.se.fi, p.se.se);
	event.pb(p);
}

ld full = 0.0;
void wrzuc (ld y, ld l, ld r, ld y1, ld l1, ld r1, ld sign)
{
	full += (y - y1)/2.0 * (r - l + r1 - l1);
	
	ld ml = max(l, l1);
	ld mr = min(r, r1);
	
	ld bl = min(l, l1);
	ld br = max(r, r1);
	
	ld h = (y - y1) * sign;
	
	
	debug ("\nwrzuc %.2Lf: [%.2Lf %.2Lf]    %.2Lf: [%.2Lf %.2Lf]  => %.0Lf\n", y, l, r, y1, l1, r1, h);
	
	if (bl + eps < ml)
	{
		mark({ bl, {1, h/(ml - bl)}});
		mark({ ml, {1, -h/(ml - bl)}});
	}
	else mark({bl, {0, h}});
	
	if (mr + eps < br)
	{
		
		mark({ mr, {1, -h/(br - mr)}});
		mark({ br, {1, h/(br - mr)}});
	}
	else mark({mr, {0,-h}});
}

ll crosspro (pair <ll, ll> a, pair <ll, ll> b, pair <ll, ll> c)
{
	return (a.fi - c.fi) * (b.se - c.se) - (a.se - c.se) * (b.fi - c.fi);
}

bool checkSwap(vector< pair <int, int> > &left, vector <pair <int, int> > &right)
{
	pair <ll, ll> top = left[0], lewy = left[1], prawy = right[1];
	
	return crosspro(lewy, prawy, top) < 0;
	
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	int n, q;
	scanf ("%d %d", &n, &q);
	
	vector <pair <int, int> > pkt(n), left, right;
	for (auto &p: pkt) scanf ("%d %d", &p.fi, &p.se);
	
	vector <ld> ans(q);
	rep(i,0,q)
	{
		int x;
		scanf ("%d", &x);
		event.pb({ ld(x), {2+i, 0.0}});
	}
	
	{
		int lowest = 0, highest = 0;
		rep(i,0,n)
		{
			if (pkt[i].se > pkt[highest].se) highest = i;
			if (pkt[i].se < pkt[lowest].se) lowest = i;
		}
		
		rep(i,0,n) pkt.pb(pkt[i]);
		
		rep(i,lowest,n+n)
		{
			left.pb(pkt[i]);
			if (i==highest or i==highest+n) break;
		}
		rep(i,highest, n+n)
		{
			right.pb(pkt[i]);
			if (i==lowest or i==lowest+n) break;
		}
		
		int l = inf, r = inf;
		for (auto p: left) l = min(l, p.fi);
		for (auto p: right) r = min(r, p.fi);
		
			
	}
	
	debug ("Left: \n");
	for (auto p: left) debug ("(%d %d) ", p.fi, p.se);
	debug ("\n");
	debug ("Right: \n");
	for (auto p: right) debug ("(%d %d) ", p.fi, p.se);
	debug ("\n");
	
	sort(left.begin(), left.end(), [] (pair <int, int> a, pair <int, int> b) {return a.se > b.se;});
			
			sort(right.begin(), right.end(), [] (pair <int, int> a, pair <int, int> b) {return a.se > b.se;});
	
	if (checkSwap(left, right)) 
		{
			swap(left, right);
		}
		
			
	
	debug ("Left: \n");
	for (auto p: left) debug ("(%d %d) ", p.fi, p.se);
	debug ("\n");
	debug ("Right: \n");
	for (auto p: right) debug ("(%d %d) ", p.fi, p.se);
	debug ("\n");	
	
	
	{
		auto lewy = left.begin();
		auto prawy = right.begin();
		
		ld y = lewy->se;
		ld l = lewy->fi, r = prawy->fi;
		
		while (lewy!=left.end() and prawy!=right.end())
		{
			debug ("%d %d and %d %d\n", lewy->fi, lewy->se, prawy->fi, prawy->se);
			auto lnxt = lewy, rnxt = prawy;
			lnxt++; rnxt++;
			
			if (lnxt==left.end() or rnxt==right.end()) break;
			
			ld y1, l1, r1;
			if (lnxt->se > rnxt->se)
			{
				y1 = lnxt->se;
				l1 = lnxt->fi;
				r1 = (rnxt->fi * (prawy->se - y1) + prawy->fi * (y1 - rnxt->se)) / (prawy->se - rnxt->se);
				
				lewy++;
			}
			else if (lnxt->se < rnxt->se)
			{
				y1 = rnxt->se;
				l1 = (lnxt->fi * (lewy->se - y1) + lewy->fi * (y1 - lnxt->se)) / (lewy->se - lnxt->se);
				r1 = rnxt->fi;
				
				prawy++;
			}
			else
			{
				y1 = lnxt->se;
				l1 = lnxt->fi;
				r1 = rnxt->fi;
				
				lewy++; prawy++;
			}
			
			assert(l1 < r1 + eps);
			
			ld m1 = (l1+r1)/2.0;
			ld m = (r+l)/2.0;
			
			wrzuc(y, l, m, y1, l1, m1, -1.0);
			wrzuc(y, m, r, y1, m1, r1, 1.0);
			
			y = y1;
			l = l1;
			r = r1;
		}
	}
	
	
	{
		
		debug ("The whole area is %Lf\n", full);
		
		ld stan = full;
		sort(event.begin(), event.end());
		ld width = 0.0, slope = 0.0;
		
		ld x = -inf;
		
		for (auto &e: event)
		{
			//process the change
			ld dx = e.fi - x;
			ld w2 = width + slope * dx;
			
			debug ("Process %.2Lf (%.2Lf --  %.2Lf) in %.2Lf  slope = %.2Lf  => %.2Lf\n", e.fi, width, w2, dx, slope, stan); 
			
			stan += (width + w2) * dx / 2.0;
			
			width = w2;
			x = e.fi;
			
			if (e.se.fi==0)
			{
				width+=e.se.se;
			}
			else if (e.se.fi==1)
			{
				slope += e.se.se;
			}
			else
			{
				debug ("Query!\n");
				ans[e.se.fi-2] = stan;
			}
		}
		
		assert(abs(slope) < eps);
	}
	
	for (ld x: ans) printf ("%.12Lf\n", x);
}