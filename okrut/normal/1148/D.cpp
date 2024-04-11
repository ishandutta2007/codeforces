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
typedef pair <pair <int, int>, int> para;
vector <pair <int, int> > tab;
vector <para> mal, ros, rob; //our curr
int n;
const int T = 1<<21;
const int N = 3e5+100;
int tree[T +T];
int maks (int left, int right, int a=1, int lewy = 0, int prawy = N*2)
{
	if (left <=lewy && right>=prawy) return tree[a];
	else
	{
		int r1=-1, r2=-1;
		if (left <=mitte) r1 = maks (left, right, a*2, lewy, mitte);
		if (right >mitte) r2 = maks(left, right, a*2+1, mitte+1, prawy);
		
		if (r1==-1) return r2;
		if (r2==-1) return r1;
		
		if (rob[r1].fi.se>rob[r2].fi.se) return r1;
		else return r2;
	}
}
void mark (int x, int y, int a=1, int lewy = 0, int prawy = N*2)
{
	if (lewy==prawy) 
	{
		tree[a] = y; //indeks
		debug ("%d %d zaznacz w %d: %d (%d)\n", x, y, lewy, a, tree[a]);
	}
	else
	{
		if (x<=mitte) mark (x, y, a*2, lewy, mitte);
		else mark(x, y, a*2+1, mitte+1, prawy);
		
		if (tree[a*2]==-1) tree[a] = tree[a*2+1];
		else if (tree[a*2+1]==-1) tree[a] = tree[a*2];
		else if (rob[tree[a*2]].fi.se>rob[tree[a*2+1]].fi.se) tree[a] = tree[a*2];
		else tree[a] = tree[a*2+1];
	}
}
int solve (vector <int> &res)
{
	
	rep(i,0,T+T) tree[i] = -1;
	res.clear();
	if ((int)rob.size()==0) return 0;
	rep(i,0,(int)rob.size()) mark(rob[i].fi.fi, i);
	
	//zaznaczamy wzystko
	int f = maks (0, N*2);
	
	debug ("pierwszy indeks: %d\n", f);
	
	while (f!=-1)
	{
		res.pb(rob[f].se);
		debug ("para %d %d\n", rob[f].fi.fi, rob[f].fi.se);
		mark(rob[f].fi.fi, -1); //usuwam cie
		f = maks(0, rob[f].fi.se);
	}
	return (int)res.size();
}
int main ()
{
	scanf ("%d", &n);
	tab.resize(n);
	rep(i,0,n) scanf ("%d %d", &tab[i].fi, &tab[i].se);
	rep(i,0,n) 
	{
		if (tab[i].fi<tab[i].se)
		{
			ros.pb(mp(tab[i], i));
		}
		else
		{
			pair <int, int> p = mp(6e5+1 - tab[i].fi, 6e5 +1 - tab[i].se);
			mal.pb(mp(p, i));
		}
	}
	
	vector <int> r1, r2;
	rob = ros;
	solve(r1);
	rob = mal;
	solve(r2);
	if ((int)r1.size()>(int)r2.size())
	{
		printf ("%d\n", (int)r1.size());
		for (int v: r1) printf ("%d ", v+1);
		printf ("\n");
	}
	else
	{
		printf ("%d\n", (int)r2.size());
		for (int v: r2) printf ("%d ", v+1);
		printf ("\n");
	}
}