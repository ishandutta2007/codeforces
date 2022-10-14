#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;

const int T = 1<<20;
ll lazy[T+T], tree[T+T]; //+, min
const int duzo = int(1e9)+100;
ll wynik;
int A, l, r;
int m;
void up (int a, int lewy, int prawy)
{
	if (lewy<prawy)
	{
		lazy[a*2]+=lazy[a];
		lazy[a*2+1]+=lazy[a];
	}
	tree[a]+=lazy[a];
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
		lazy[a] = 0;
		tree[a] = min(tree[a*2], tree[a*2+1]);
	}
	else up(a, lewy, prawy);
}
ll mini (int left, int right, int a=1, int lewy=0, int prawy = m)
{
	if (a==1) wynik = 1e18;
	up(a, lewy, prawy);
	if (left<=lewy && right>=prawy) 
	{
		if (wynik> tree[a])
		{
			wynik  = tree[a];
			A = a;
			l = lewy;
			r = prawy;
		}
		return tree[a];
	}
	else
	{
		ll ret = 0;
		if (left<=mitte) ret = min(ret, mini(left, right, a*2, lewy, mitte));
		if (right>mitte) ret = min(ret, mini(left, right, a*2+1, mitte+1, prawy));
		return ret;
	}
}
void add (int left, int right, ll x, int a = 1, int lewy = 0, int prawy = m)
{
	up(a, lewy, prawy);
	if (left<=lewy && right>=prawy)
	{
		lazy[a]+=x;
	}
	else
	{
		if (left<=mitte) add(left, right,x,  a*2, lewy, mitte);
		if (right>mitte) add(left, right, x, a*2+1, mitte+1, prawy);
	}
	update(a, lewy, prawy);
}
int search (int a, int lewy, int prawy)
{
	while (lewy<prawy)
	{
		update(a, lewy, prawy);
		if (tree[a*2]<tree[a*2+1]) 
		{
			a*=2;
			prawy = mitte;
		}
		else
		{
			a = a*2+1;
			lewy = mitte+1;
		}
	}
	return lewy;
}
vector <int> liczby;
vector <int> kor;
map <int, int> mapa;
int main ()
{
	int n;
	scanf ("%d", &n);
	vector <pair <pair <int, int>, ll> > pkt(n);
	liczby.resize(n*2);
	rep(i,0,n)
	{
		scanf ("%d %d %lld", &pkt[i].fi.fi, &pkt[i].fi.se, &pkt[i].se);
		liczby[i*2] = pkt[i].fi.fi;
		liczby[i*2+1] = pkt[i].fi.se;
	}
	sort(liczby.begin(), liczby.end());
	int y  = 0, z=0;
	m=0;
	kor.pb(0);
	mapa[0] = 0;
	for (int x: liczby)
	{
		if (x>y)
		{
			y= x;
			kor.pb(y);
			z++;
			m++;
			mapa[y] = z;
		}
	}
	for (auto &p: pkt)
	{
		p.fi.fi = mapa[p.fi.fi];
		p.fi.se = mapa[p.fi.se];
	}
	rep(i,0,n)
	{
		int a = max(pkt[i].fi.fi, pkt[i].fi.se);
		int b = min(pkt[i].fi.fi, pkt[i].fi.se);
		pkt[i].fi.fi= a;
		pkt[i].fi.se = b;
	}
	rep(i,0,m+1)
	{
		add(i,i,-kor[i]); //to trzeba dodac
	}
	sort(pkt.begin(), pkt.end());
	ll res = 0LL;
	int x1, x2;
	x1  = x2 = duzo;
	y = 0;
	ll sum = 0LL;
	rep(i,0,m+1)
	{
		while (y < n && pkt[y].fi.fi==i)
		{
			sum +=pkt[y].se;
			add(pkt[y].fi.se+1, m, pkt[y].se);
			y++;
		}
		ll d = mini(0, i);
		int pos = search(A, l, r);
		ll r = sum - d - kor[i];
		if (res<r)
		{
			res = r;
			x2 = kor[i];
			x1 = kor[pos];
		}
	}
	printf ("%lld\n%d %d %d %d\n", res, x1, x1, x2, x2);
}