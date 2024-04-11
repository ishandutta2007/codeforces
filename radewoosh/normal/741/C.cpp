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
sim dor(c) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

int n;
int n2;
int x[1000007];
int y[1000007];

int tez[1000007];
int wyn[1000007];

void check(int v)
{
	if ((wyn[v]+wyn[(v+1)%n2]+wyn[(v+2)%n2])%3)
		return;
		
	int poz=(v+(rand()%3))%n2;
	wyn[poz]^=1;
	wyn[tez[poz]]^=1;
	
	check((poz+n2)%n2);
	check((poz-1+n2)%n2);
	check((poz-2+n2)%n2);
	
	check((tez[poz]+n2)%n2);
	check((tez[poz]-1+n2)%n2);
	check((tez[poz]-2+n2)%n2);
}

int main()
{
	srand(69);
	scanf("%d", &n);
	n2=n*2;
	for (int i=0; i<n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		y[i]--;
		tez[x[i]]=y[i];
		tez[y[i]]=x[i];
		wyn[x[i]]=1;
	}
	for (int i=0; i<n2; i++)
		check(i);
	for (int i=0; i<n; i++)
		printf("%d %d\n", wyn[x[i]]+1, wyn[y[i]]+1);
	return 0;
}