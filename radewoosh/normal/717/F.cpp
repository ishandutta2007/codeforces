#ifndef LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=1000*1007;
const long long inf=(long long)1000*1000*1000*1000*1000*1000;
const int d=300;

int n, q;

long long mini[nax][2];
long long dorz[nax];
long long tab[nax];
long long sum[nax];

void update(int v)
{
	int a=v*d;
	int b=(v+1)*d-1;
	for (int h=0; h<2; h++)
		mini[v][h]=inf;
	sum[v]=0;
	for (int i=a; i<=b; i++)
	{
		sum[v]=tab[i]-sum[v];
		mini[v][(i&1)^1]=min(mini[v][(i&1)^1], sum[v]);
	}
}

void wgniec(int v)
{
	int a=v*d;
	int b=(v+1)*d-1;
	for (int i=a; i<=b; i++)
		tab[i]+=dorz[v];
	dorz[v]=0;
	update(v);
}

int f(int v)
{
	return (v/d);
}

void dodaj(int a, int b, long long w)
{
	if (b-a<3*d)
	{
		for (int i=a; i<=b; i++)
			tab[i]+=w;
		for (int i=f(a); i<=f(b); i++)
			wgniec(i);
		return;
	}
	for (int i=a; f(i)==f(a); i++)
		tab[i]+=w;
	for (int i=b; f(i)==f(b); i--)
		tab[i]+=w;
	wgniec(f(a));
	wgniec(f(b));
	for (int i=f(a)+1; i<f(b); i++)
		dorz[i]+=w;
}

int czy(int a, int b)
{
	long long s=0;
	if (b-a<3*d)
	{
		for (int i=f(a); i<=f(b); i++)
			wgniec(i);
		for (int i=a; i<=b; i++)
		{
			s=tab[i]-s;
			debug() << "po " << i << " jest " << s;
			if (s<0)
				return 0;
		}
		return (!s);
	}
	wgniec(f(a));
	wgniec(f(b));
	for (int i=a; f(a)==f(i); i++)
	{
		s=tab[i]-s;
		if (s<0)
			return 0;
	}
	for (int i=f(a)+1; i<f(b); i++)
	{
		if (s+mini[i][0]<0 || -s+mini[i][1]+dorz[i]<0)
			return 0;
		s+=sum[i];
	}
	for (int i=f(b)*d; i<=b; i++)
	{
		s=tab[i]-s;
		if (s<0)
			return 0;
	}
	return (!s);
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		long long p1;
		scanf("%lld", &p1);
		dodaj(i, i, p1-1);
	}
	scanf("%d", &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==2)
		{
			int p1, p2;
			scanf("%d%d", &p1, &p2);
			printf("%d\n", czy(p1, p2));
		}
		else
		{
			int p1, p2, p3;
			scanf("%d%d%d", &p1, &p2, &p3);
			dodaj(p1, p2, p3);
		}
	}
	return 0;
}