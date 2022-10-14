#include <bits/stdc++.h>
#define wied(i,a,b) for (int i=a;  i<b; i++)
#define mitte (lewy+prawy)/2
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define debug //
using namespace std;
vector <int> scho, ele;
int n, m, q;
int v;
inline pair <int, int> binsuche (int a, vector <int> &tab)
{
	pair <int, int> p=mp(-1,-1); //brak schodow
	int lewy=0, prawy=tab.size()-1;
	while (lewy<prawy)
	{
		if (tab[mitte]<a) lewy=mitte+1;
		else prawy=mitte;
	}
	p.se=tab[prawy];
	if (prawy>0) p.fi=tab[prawy-1];
	return p;
}
int suf (int a, int b)
{
	if (a%b==0) return a/b;
	else return a/b+1;
}
int main ()
{
	int cl, ce;
	scanf ("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
	scho.resize(cl);
	ele.resize(ce);
	wied(i,0,cl) scanf ("%d", &scho[i]);
	wied(i,0,ce) scanf ("%d", &ele[i]);
	scho.push_back(1e9);
	ele.push_back(1e9);
	int a, b, c, d;
	scanf ("%d", &q);
	pair <int, int> p;
	int wyn, res;
	wied(i,0,q)
	{
		scanf ("%d %d %d %d", &a, &b, &c, &d);
		wyn=2e9;
		if (a==c) 
		{
			printf ("%d\n", abs(b-d));
		}	
		else
		{
			if (scho.size()>0)
			{
				p=binsuche (b,scho);
				res=abs(p.se-b)+abs(p.se-d)+abs(a-c);
				wyn=min(wyn, res);
				if (p.fi>=0) res=abs(p.fi-b)+abs(p.fi-d)+abs(a-c);
				wyn=min(wyn, res);
			}
			if (ele.size()>0)
			{
				p=binsuche(b,ele);
				res=abs(p.se-b)+abs(p.se-d)+suf(abs(a-c), v);
				wyn=min(wyn, res);
				if (p.fi>=0) res=abs(p.fi-b)+abs(p.fi-d)+suf(abs(a-c), v);
				wyn=min(wyn, res);
			}
			printf ("%d\n", wyn);
		}
	}
	return 0;
}