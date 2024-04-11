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
map <int, int> mapa;
vector <pair <int, int> > ojce; //odleglosci do ojca - stad mam dystanse
pair <int, int> krol (int a)
{
	if (ojce[a].fi==-1) return mp(a,0); //dystans
	pair <int, int> p=krol(ojce[a].fi);
	p.se=p.se^ojce[a].se;
	ojce[a]=p;
	return p;
}
int unia (int a, int b, int c)
{
	pair <int, int> krola=krol(a), krolb=krol(b);
	if (krola.fi==krolb.fi) 
	{
		return -1;
	}
	ojce[krola.fi]=mp(a, krola.se);
	ojce[krolb.fi]=mp(b, krolb.se);
	ojce[a]=mp(-1,0);
	ojce[b]=mp(a,c);
	return c;
}
int dist (int a, int b)
{
	pair <int, int> krola=krol(a), krolb=krol(b);
	if (krola.fi!=krolb.fi) return -1;
	else return krola.se^krolb.se;
}
int x=0; //kolejne wspolrzedne
int num (int a)
{
	if (mapa.count(a)==0)
	{
		x++;
		mapa.insert(mp(a,x));
		return x;
	}
	else 
	{
		//debug ("number\n");
		return mapa[a];
	}
}
int main ()
{
	int q;
	cin>>q;
	ojce.resize(q*3+8, mp(-1,0));
	int last=0;
	int t, l, r, x;
	rep(i,0,q)
	{
		//debug ("question %d: \n", i);
		if (last==-1) last=1;
		cin>>t;
		if (t==1)
		{
			cin>>l >>r >>x;
			l^=last;
			r^=last;
			x^=last;
			if (l>r) swap(l,r);
			debug ("update [%d %d %d] %d %d %d\n",l, r, x, num(l-1), num(r), x);
			unia(num(l-1), num(r), x);
		}
		if (t==2)
		{
			cin>>l >>r;
			l^=last;
			r^=last;
			if (l>r) swap(l,r);
			debug ("ask [%d %d] %d %d\n", l, r, num(l-1), num(r));
			last=dist(num(l-1), num(r));
			cout<<last <<"\n";
		}
	}
}