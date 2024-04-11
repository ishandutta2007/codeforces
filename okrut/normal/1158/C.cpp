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
vector <int> per, nast;
vector <int> tree;
int n;
int best (int a, int b)
{
	if (nast[a]>=nast[b]) return a;
	else return b;
}
void maketree (int a=1, int lewy=0, int prawy = n-1)
{
	if (a==1) tree.resize(n*5+1000, n+1);
	assert(a<(int)tree.size());
	if (lewy<prawy)
	{
		maketree(a*2, lewy, mitte);
		maketree(a*2+1, mitte+1, prawy);
		tree[a]=best(tree[a*2], tree[a*2+1]);
	}
	else tree[a] = lewy;
	
}

void usun (int x, int a=1, int lewy=0, int prawy=n-1)
{
	while (lewy<prawy)
	{
		a*=2;
		if (x<=mitte) prawy = mitte;
		else 
		{
			lewy = mitte+1;
			a++;
		}
	}
	tree[a] = n+1; //wartosc najmniejsza
	while (a>1)
	{
		a/=2;
		tree[a] = best(tree[a*2], tree[a*2+1]);
	}
}
int maks (int left, int right, int a=1, int lewy=0, int prawy=n-1)
{
	if (left<=lewy && right>=prawy)
	{
		return tree[a];
	}
	else
	{
		int e=n+1, f=n+1;
		if (left<=mitte) e = maks (left, right, a*2, lewy, mitte);
		if (right>mitte) f = maks (left, right, a*2+1, mitte+1, prawy);
		return best(e, f);
	}
}
bool ok;
int w;
bool zrob (int lewy, int prawy) //prawy inclusive
{
	debug ("zrob %d %d od %d\n", lewy, prawy, w);
	if (prawy<lewy) return true; //done
	int y, z, x;
	y = maks (lewy, prawy);
	
	
	while (nast[y]==prawy+1)
	{
		debug ("mam %d\n", y);
		per[y] = w;
		w--;
		usun(y);
		//check if works:
		z = maks(lewy, y);
		
		if (nast[z]>y) 
		{
			ok = false;
			return false;
		}
		
		zrob (lewy, y-1);
		
		y = maks(lewy, prawy);
		
	}
	return true;
}

int main ()
{
	int tests;
	scanf ("%d", &tests);
	rep(q,0,tests)
	{
		nast.clear();
		tree.clear();
		per.clear();
		scanf ("%d", &n);
		nast.resize(n+2);
		nast[n] = n; //ma pokazywac na siebie
		nast[n+1] = -1; //nie istniejesz
		per.resize(n+1, -1);
		per[n] = n+1;
		
		rep(i,0,n)
		{
			scanf ("%d", &nast[i]);
			nast[i]--;
			if (nast[i]<0) nast[i] = i+1;
		}
		maketree();
		ok = true;
		w=n;
		zrob(0, n-1);
		
		if (!ok) printf ("-1\n");
		else
		{
			rep(i,0,n) assert(per[i]>0);
			
			rep(i,0,n) printf ("%d ", per[i]);
			printf ("\n");
		}
		
	}
}