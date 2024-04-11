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

const int nax=100*1007;
const int xax=5037;
const int l=1024;

int n, k, x;

int ile[2][xax];

int *iles;
int *ilet;

int main()
{
	scanf("%d%d%d", &n, &k, &x);
	for (int i=1; i<=n; i++)
	{
		int p1;
		scanf("%d", &p1);
		ile[0][p1]++;
	}
	ilet=ile[0];
	iles=ile[1];
	while(k--)
	{
		swap(ilet, iles);
		for (int i=0; i<l; i++)
			ilet[i]=0;
		int zacz=0;
		for (int i=0; i<l; i++)
		{
			ilet[i^x]+=((iles[i]+1-zacz)>>1);
			ilet[i]+=((iles[i]+zacz)>>1);
			if (iles[i]&1)
				zacz^=1;
		}
	}
	for (int i=l-1; 1; i--)
	{
		if (ilet[i])
		{
			printf("%d ", i);
			break;
		}
	}
	for (int i=0; 1; i++)
	{
		if (ilet[i])
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}