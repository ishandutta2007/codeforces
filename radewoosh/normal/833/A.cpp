//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

const int nax=1000*1007;
const int d=1000*1000;
const long long inf=2e18;

long long a, b;

int sito[nax];

long long szes(long long v)
{
	long long bsa=1;
	long long bsb=d;
	long long bss;
	long long w;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)>>1;
		w=bss*bss*bss;
		if (w>=v)
			bsb=bss;
		else
			bsa=bss+1;
	}
	if (bsa*bsa*bsa==v)
		return bsa;
	return -1;
}

int check(long long v)
{
	int aa=0;
	int bb=0;
	
	long long p=a;
	long long q=b;
	
	while(!(p%v))
	{
		p/=v;
		aa++;
	}
	while(!(q%v))
	{
		q/=v;
		bb++;
	}
	while(aa || bb)
	{
		if (!aa || !bb)
			return 0;
		if (aa>=bb)
			aa--;
		else
			bb--;
		aa--;
		bb--;
	}
	return 1;
}

int main()
{
	for (int i=2; i<=d; i++)
		if (!sito[i])
			for (int j=i; j<=d; j+=i)
				sito[j]=i;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld", &a, &b);
		long long wez=szes(a*b);
		if (wez==-1)
		{
			printf("No\n");
			continue;
		}
		int ok=1;
		int ost=-1;
		while(wez>1)
		{
			int w=sito[wez];
			wez/=w;
			if (w!=ost)
			{
				ost=w;
				if (!check(w))
					ok=0;
			}
		}
		if (ok)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}