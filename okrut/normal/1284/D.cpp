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

const int T = 1<<20;
int sum[T+T], lazy[T+T];

void up (int a, int lewy, int prawy) 
{
	if (lewy<prawy)
	{
		lazy[a*2]+=lazy[a];
		lazy[a*2+1]+=lazy[a];
	}
	sum[a]+=lazy[a];
	lazy[a] = 0;
}
void update (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		lazy[a*2]+=lazy[a];
		lazy[a*2+1]+=lazy[a];
		up(a*2, lewy, mitte);
		up(a*2+1, mitte+1, prawy);
		lazy[a] =0;
		sum[a] = max(sum[a*2], sum[a*2+1]);
	}
	else up(a, lewy, prawy);
}
int suma (int left, int right, int a=1, int lewy=0, int prawy=T-1)
{
	update(a, lewy, prawy);
	if (left <=lewy && right>=prawy) return sum[a];
	else
	{	
		int ret = 0;
		if (left<=mitte) ret = max(ret, suma(left, right, a*2, lewy, mitte));
		if (right>mitte) ret = max(ret, suma(left, right, a*2+1, mitte+1, prawy));
		return ret; 
	}
}
void add (int left, int right, int x, int a=1, int lewy=0, int prawy = T-1)
{
	update(a, lewy, prawy);
	if (left<=lewy && right>=prawy) lazy[a]+=ll(x);
	else
	{
		if (left<=mitte) add(left, right, x, a*2, lewy, mitte);
		if (right>mitte) add(left, right, x, a*2+1, mitte+1, prawy);
	}
	update(a, lewy, prawy);
}

map <int, int> mapa;

int x,n;
bool check (vector <pair <int, int> > &v1, vector <pair <int, int> > &v2)
{
	rep(i,0,T+T) sum[i] = lazy[i] = 0;
	
	vector <pair <int, int> > dod(n), od(n);
	rep(i,0,n)
	{
		dod[i] = {v1[i].fi, i};
		od[i] = {v1[i].se, i};
	}
	sort(dod.begin(), dod.end());
	sort(od.begin(), od.end());
	reverse(dod.begin(), dod.end());
	reverse(od.begin(), od.end());
	
	int stan = 0;
	rep(t,0,x+1)
	{
		while (!dod.empty() && dod.back().fi==t)
		{
			int id = dod.back().se;
			dod.pop_back();
			ll s = suma(v2[id].fi, v2[id].se);
			if (s!=stan) return false; //z kims sie nie przecinam
			
			debug ("%d: dodaj %d na [%d %d]\n", t, id, v2[id].fi, v2[id].se);
			add(v2[id].fi, v2[id].se, 1);
			stan++;
		}
		while (!od.empty() && od.back().fi==t)
		{
			int id = od.back().se;
			od.pop_back();
			
			debug ("%d: usun %d na [%d %d]\n", t, id, v2[id].fi, v2[id].se);
			add(v2[id].fi, v2[id].se, -1);
			stan--;
		}
	}
	return true;
}
int main ()
{
	scanf ("%d", &n);
	vector <int> rob;
	vector <pair <int, int> > v1(n), v2(n);
	rep(i,0,n)
	{
		scanf ("%d %d %d %d", &v1[i].fi, &v1[i].se, &v2[i].fi, &v2[i].se);
		rob.pb(v1[i].fi);
		rob.pb(v1[i].se);
		rob.pb(v2[i].fi);
		rob.pb(v2[i].se);
	}
	sort(rob.begin(), rob.end());
	mapa[rob[0]] = 0;
	x = 0;
	rep(i,1,4*n) if (rob[i] > rob[i-1])
	{
		mapa[rob[i]] = (++x);
	}
	
	for (auto &p: v1) 
	{
		p.fi = mapa[p.fi];
		p.se = mapa[p.se];
	}
	for (auto &p: v2)
	{
		p.fi = mapa[p.fi];
		p.se = mapa[p.se];
	}
	
	if (check(v1, v2) && check(v2, v1)) printf ("YES\n");
	else printf ("NO\n");
}