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
vector <pair <pair <int, int>, pair <int, int> > > rec;

#ifdef LOCAL
vector <pair <pair <int, int>, pair <int, int> > > pro;
void init ()
{
	pro.resize(2);
	rep(i,0,2) scanf ("%d %d %d %d", &pro[i].fi.fi, &pro[i].fi.se, &pro[i].se.fi, &pro[i].se.se);
}

int ask (int x1, int y1, int x2, int y2)
{

	int ret=0;
	rep(i,0,2) if (pro[i].fi.fi >=x1 && pro[i].fi.se>=y1 && pro[i].se.fi<=x2 && pro[i].se.se<=y2) ret++;
	
	for (auto p: rec) if (p.fi.fi>=x1 && p.fi.se>=y1 && p.se.fi<=x2 && p.se.se<=y2) ret--;
	
	//debug ("ask: ");
	//debug ("? %d %d %d %d - %d\n", x1, y1, x2, y2, ret);
	
	return ret;
}
#endif

#ifndef LOCAL
int ask (int x1, int y1, int x2, int y2)
{
	int ret;
	printf ("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	scanf ("%d", &ret);
	for (auto p: rec) if (p.fi.fi>=x1 && p.fi.se>=y1 && p.se.fi<=x2 && p.se.se<=y2) ret--;
	return ret;
}
#endif

void find (int p, int x1, int y1, int x2, int y2)
{
	if (p==0) return;
	
	debug ("find %d (%d %d) (%d %d)\n", p, x1, y1, x2, y2);
	
	//int p0 = p;
	
	if (x1==x2)
	{
		pair <pair <int, int>, pair <int, int> > t;
		t.fi.fi = x1; t.se.fi = x2;
		int r, lewy = y1, prawy = y2;
		
		while (lewy<prawy) //prawy koniec
		{
			r = ask(x1, y1, x2, mitte);
			if (r>0) prawy = mitte;
			else lewy = mitte+1;
		}
		t.se.se = lewy;
		
		lewy = y1; prawy = t.se.se;
		
		while (lewy<prawy) //lewy koniec
		{
			r = ask(x1, mitte+1, x2, t.se.se);
			if (r==1) lewy = mitte+1;
			else prawy = mitte;
		}
		t.fi.se = lewy;
		
		rec.pb(t);
		debug ("mam!\n");
		find(p-1, x1, t.se.se+1, x2, y2);
		return;
	}
	
	if (y1==y2)
	{
		pair <pair <int, int>, pair <int, int> > t;
		t.fi.se = y1; t.se.se = y2;
		int r, lewy = x1, prawy = x2;
		
		while (lewy<prawy) //prawy koniec
		{
			r = ask(x1, y1, mitte, y2);
			if (r>0) prawy = mitte;
			else lewy = mitte+1 ;
		}
		t.se.fi = lewy;
		
		lewy = x1; prawy = t.se.fi;
		
		while (lewy<prawy) //lewy koniec
		{
			r = ask(mitte+1, y1, t.se.fi, y2);
			if (r==1) lewy = mitte+1;
			else prawy = mitte;
		}
		t.fi.fi = lewy;
		
		rec.pb(t);
		debug ("mam!\n");
		find(p-1, t.se.fi+1,y1, x2, y2);
		return;
	}
	
	int xmid = (x1+x2)/2, ymid = (y1+y2)/2;
	
	int q1=0, q2=0, q3=0, q4=0, p1, p2, p3, p4;
	
	p1 = ask(x1, y1, x2, ymid);
	p-=p1;
	if (p1>0)
	{	
		q1 = ask(x1, y1, xmid, ymid);
		q2 = ask(xmid+1, y1, x2, ymid);
		
		find(q1, x1, y1, xmid, ymid);
		find(q2, xmid+1, y1, x2, ymid);
		
		p1-=q1+q2;
		find(p1, x1, y1, x2, ymid);
	}
	//debug ("after p1: %d\n", p);
	if (p==0) return;
	
	p2 = ask(x1, ymid+1, x2, y2);
	p-=p2;
	if (p2>0)
	{
		//debug ("p2 > 0\n");
		q3 = ask(x1, ymid+1, xmid, y2);
		q4 = ask(xmid+1, ymid+1, x2, y2);
		
		find(q3, x1, ymid+1, xmid, y2);
		find(q4, xmid+1, ymid+1, x2, y2);
		
		p2-=q3+q4;
		
		find(p2, x1, ymid+1, x2, y2);
	}
	if (p==0) return;
	
	p3 = ask(x1, y1, xmid, y2);
	//p3-=q1+q3; oni juz sa znalezieni
	
	p-=p3;
	if (p3>0)
	{
		find(p3, x1, y1, xmid, y2);
	}
	if (p==0) return;
	
	p4 = ask(xmid+1, y1, x2, y2);
	//p4-=q2+q4;
	p-=p4;
	if (p4>0)
	{
		find(p4, xmid+1, y1, x2, y2);
	}
	if (p==0) return;
	
	//mamy kogos na srodku
	pair <pair <int, int>, pair <int, int> > t;
	int r, lewy, prawy;
	
	lewy = xmid+1;
	prawy = x2;
	
	while (lewy<prawy)
	{
		r = ask(x1, y1, mitte, y2);
		
		//if (p0==2) if (rec[0].se.fi<=mitte) r--;
		
		if (r==0) lewy = mitte+1;
		else prawy = mitte;
	}
	t.se.fi = lewy;
	
	lewy = x1; prawy = xmid;
	
	while (lewy<prawy)
	{
		r = ask(mitte+1, y1, x2,y2);
		//if (p0==2 && rec[0].fi.fi>mitte) r--;
		
		
		if (r==0) prawy = mitte;
		else lewy = mitte+1;
	}
	t.fi.fi = lewy;
	
	lewy = y1; prawy = ymid;
	
	while (lewy<prawy)
	{
		r = ask(x1, mitte+1, x2, y2);
		//if (p0==2 && rec[0].fi.se>mitte) r--;
		
		if (r==0) prawy = mitte;
		else lewy = mitte+1;
	}
	t.fi.se = lewy;
	lewy = ymid+1, prawy = y2;
	
	while (lewy<prawy)
	{
		r = ask(x1, y1, x2, mitte);
		//if (p0==2 && rec[0].se.se<=mitte) r--;
		
		if (r==0) lewy = mitte+1;
		else prawy = mitte;
	}
	t.se.se = lewy;
	debug ("mam! (%d %d %d %d)\n", x1, y1, x2, y2);
	rec.pb(t);
}
int n;
int main ()
{
	scanf ("%d", &n);
	
	#ifdef LOCAL
	init();
	#endif
	
	find(2, 1, 1, n, n);
	
	#ifdef LOCAL
	printf ("%d\n",n);
	#endif
	
	#ifndef LOCAL
	printf ("!");
	#endif
	
	rep(i,0,2) printf (" %d %d %d %d", rec[i].fi.fi, rec[i].fi.se, rec[i].se.fi, rec[i].se.se);
	printf ("\n");
	
}