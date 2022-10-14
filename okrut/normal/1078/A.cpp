#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef double ld;
ll A, B, C;
pair <ll, ll> e, f;
vector <pair <pair <ld, ld>, ld> > jed, dru; //punkty na przekatnej i kary
ld getx (ll y)
{
	return -(ld(B*y+C))/(ld)A;
}
ld gety (ll x)
{
	return -(ld(A*x+C))/(ld)B;
}
int main ()
{
	//ios_base::sync_with_stdio(false);
	cin>>A >>B >>C;
	cin>>e.fi >>e.se >>f.fi >>f.se;
	ld res=abs(e.fi-f.fi)+abs(e.se-f.se); //podstawowy wynik
	//
	ld y, x;
	if (B!=0)
	{
		y=gety(e.fi);
		jed.pb(mp(mp(e.fi, y), abs(e.se-y)));
		y=gety(f.fi);
		dru.pb(mp(mp(f.fi, y), abs(f.se-y)));
	}
	if (A!=0)
	{
		x=getx(e.se);
		jed.pb(mp(mp(x, e.se), abs(e.fi-x)));
		x=getx(f.se);
		dru.pb(mp(mp(x,f.se), abs(f.fi-x)));
	}
	rep(i,0,(int)jed.size()) rep(j,0,(int)dru.size())
	{
		res=min(res, jed[i].se+dru[j].se+sqrt( (jed[i].fi.fi-dru[j].fi.fi)*(jed[i].fi.fi-dru[j].fi.fi)+(jed[i].fi.se-dru[j].fi.se)*(jed[i].fi.se-dru[j].fi.se)));
	}
	
	printf ("%.10lf\n", res);
}