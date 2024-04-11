//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
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

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n, m;

void nope()
{
	printf("-1\n");
	exit(0);
}

int czas;
int ost[nax];

int war[nax];

int licz()
{
	debug() << "ro";
	czas++;
	for (int i=0; i<n; i++)
		ost[war[i]]=czas;
	int ret=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<i; j++)
			ret+=(ost[war[i]+war[j]]==czas);
	return ret;
}

void uluz(int v)
{
	for (int i=n-1; i>=0; i--)
	{
		int x=min(v, n);
		war[i]=i+1+x;
		v-=x;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	uluz(0);
	if (licz()<m)
		nope();
	int bsa=0;
	int bsb=n*n;
	while(bsa<=bsb)
	{
		int bss=(bsa+bsb)>>1;
		uluz(bss);
		int x=licz();
		if (x==m)
		{
			for (int i=0; i<n; i++)
				printf("%d ", war[i]);
			printf("\n");
			return 0;
		}
		if (x>m)
			bsa=bss+1;
		else
			bsb=bss-1;
	}
	//~ int x=bsa;
	//~ uluz(x);
	//~ debug() << imie(x) << imie(licz());
	//~ for (int i=x-10; i<=x+10; i++)
	//~ {
		//~ uluz(i);
		//~ debug() << i << " " << licz();
	//~ }
	//~ assert(0);
	for (int i=0; 1; i++)
	{
		for (int h=-1; h<=1; h+=2)
		{
			int w=bsa+i*h;
			if (w<0 || w>n*n)
				continue;
			uluz(w);
			if (licz()==m)
			{
				for (int i=0; i<n; i++)
					printf("%d ", war[i]);
				printf("\n");
				return 0;
			}
		}
	}
	return 0;
}