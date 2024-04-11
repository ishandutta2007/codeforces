#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define debug printf
using namespace std;
int n, t, m;
vector <pair <int, int> > one, two;
vector <int> know1, know2;
int edge (pair <int, int> a, pair <int, int> b)
{
	int x=0;
	if (a.fi==b.se) 
	{
		if (x!=0) return 0;
		x=a.fi;
	}
	if (a.fi==b.fi) 
	{
		if (x!=0) return 0;
		x=a.fi;
	}
	if (a.se==b.fi)
	{
		if (x!=0) return 0;
		x=a.se;
	}
	if (a.se==b.se)
	{
		if (x!=0) return 0;
		x=a.se;
	}
	return x;
}
void ded (vector <pair <int, int> > &ja, vector <pair <int, int> > &ty, int moje, int twoje, vector <int> &know)
{
	int y;
	rep(i,0,moje)
	{
		rep(j,0,twoje) 
		{
			y=edge(ja[i], ty[j]);
			if (y!=0)
			{
				if (know[i]==0) know[i]=y;
				else if (know[i]!=y) know[i]=-1; //sprzecznosc
			}
		}
	}
}
int main ()
{
	int a, b;	
	cin >>n >>m;
	one.resize(n);
	two.resize(m);
	rep(i,0,n) scanf ("%d %d", &one[i].fi, &one[i].se);
	rep(i,0,m) scanf ("%d %d", &two[i].fi, &two[i].se);
	know1.resize(n, 0); //nie mam polaczenia
	know2.resize(m, 0);
	ded(one,two, n, m, know1);
	ded(two, one, m, n, know2);
	int wyn=0;
	a=0;
	rep(i,0,n) if (know1[i]==-1) 
	{
		printf ("-1\n");
		return 0;
	}
	rep(i,0,m) if (know2[i]==-1) 
	{
		printf ("-1\n");
		return 0;
	}
	rep(i,0,n) if (know1[i]!=0)
	{
		if (a==0) a=know1[i];
		if (a!=know1[i]) wyn=-1;
	}
	if (wyn==-1) printf ("0\n");
	else printf ("%d\n", a);
	
}