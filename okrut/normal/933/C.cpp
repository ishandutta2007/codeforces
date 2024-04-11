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

int ile[1<<3];
pair <ll, ll> S[3];
ll R[3];
const ll L = 4000;
const ld eps = 1e-8;
ll kw (ll a)
{
	return a*a;
}
vector <pair <ld, ld> > pkt[4];

void dod (ld x, ld y, int a)
{
	bool ok = true;
	for (auto p: pkt[a]) if ( (p.fi-x)*(p.fi-x) + (p.se-y)*(p.se-y) < eps) ok = false;
	if (ok) 
	{
		if (a==0) debug ("wrzucam do 0 %Lf %Lf\n", x, y);
		pkt[a].pb(mp(x,y));
	}
}
int type (ll x1, ll y1, ll r1, ll x2, ll y2, ll r2, int a, int b)
{
	debug ("type %d %d\n", a, b);
	ll d= kw(x1-x2) + kw(y1-y2);
	if ( d> kw(r1+r2)) return 0;
	if (d < kw(max(r1,r2) - min(r1,r2))) return 0;
	
	
	ld cosa = ld(d + r1*r1 - r2*r2) / ld(2.0 * sqrt(ld(d)) * r1);
	ld l1 = ld(r1) * cosa;
	ld h = sqrt ( ld(kw(r1)) - l1*l1);
	
	ld wx = x2 - x1, wy = y2 - y1;
	ld len = sqrt(wx * wx + wy*wy);
	ld px = wy, py = -wx;
	wx*=l1/len;
	wy*=l1/len;
	px*=h/len;
	py*=h/len;
	
	ld cx = ld(x1) + wx + px;
	ld cy = ld(y1) + wy + py;
	ld dx = ld(x1) + wx - px;
	ld dy = ld(y1) + wy - py;
	
	debug ("%d %d crossing: (%Lf %Lf) (%Lf %Lf)\n", a, b, cx, cy, dx, dy);
	
	dod(cx,cy,a);
	dod(cx,cy,b);
	dod(cx,cy,3);
	
	dod(dx,dy,a);
	dod(dx,dy,b);
	dod(dx,dy,3);
	
	if (d == kw(r1+r2)) return 1;
	
	if (d == kw(max(r1,r2) - min(r1,r2))) return 1;
	
	return 2;
}


int main ()
{
	int n;
	scanf ("%d", &n);
	rep(i,0,n) 
	{
		scanf ("%lld %lld %lld", &S[i].fi, &S[i].se, &R[i]);
	}
	
	int lacz = 0;
	int c, e=0, v;
	rep(i,0,n) rep(j,i+1,n) if (type(S[i].fi, S[i].se, R[i], S[j].fi, S[j].se, R[j], i, j) >0)
	{
		 lacz++;
	}
	
	if (n==1) c=1;
	if (n==2) 
	{
		if (lacz==1) c = 1;
		else c = 2;
	}
	if (n==3)
	{
		if (lacz==1) c = 2;
		if (lacz>1) c = 1;
		if (lacz==0) c=3;
	}
	
	v = pkt[3].size();
	
	rep(i,0,n) 
	{
		debug ("%d: %d\n", i, (int)pkt[i].size());
		for (auto p: pkt[i]) debug ("(%Lf %Lf) ", p.fi, p.se);
		debug ("\n");
		e+=(int)pkt[i].size();
	}
	debug ("on the whole c = %d, e = %d, v = %d\n", c, e, v);
	
	printf ("%d\n", 1+c+e-v);
}