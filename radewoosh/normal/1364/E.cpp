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
const int inf=(1<<30)-1;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int los(int a, int b)
{
	return a+(rng()%(b-a+1));
}

void ff()
{
	fflush(stdout);
}

//~ vi per{0, 1, 2, 3, 4, 5, 6, 7};

int pyt(int a, int b)
{
	printf("? %d %d\n", a+1, b+1);
	ff();
	//~ return (per[a]|per[b]);
	int x;
	scanf("%d", &x);
	return x;
}

void ans(vi wek)
{
	printf("!");
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	exit(0);
}

int n;

int main()
{
	scanf("%d", &n);
	//~ n=8;
	//~ shandom_ruffle(per.begin(), per.end());
	//~ debug() << imie(per);
	
	vi wek(n);
	iota(wek.begin(), wek.end(), 0);
	int najm=inf;
	int g=-1;
	for (int h=0; h<40; h++)
	{
		int a=los(0, n-1);
		int b=los(0, n-1);
		if (a==b)
			continue;
		int wez=pyt(a, b);
		int x=__builtin_popcount(wez);
		if (x<najm)
		{
			najm=x;
			g=a;
		}
	}
	swap(wek[0], wek[g]);
	
	int zero=-1;
	while(1)
	{
		if ((int)wek.size()==1)
		{
			zero=wek[0];
			break;
		}
		assert((int)wek.size()!=2);
		if ((int)wek.size()!=n)
			swap(wek[0], wek[los(0, (int)wek.size()-1)]);
		//~ debug() << wek;
		vi odp(wek.size());
		for (int i=1; i<(int)wek.size(); i++)
			odp[i]=pyt(wek[0], wek[i]);
		int an=inf;
		for (int i=1; i<(int)odp.size(); i++)
			an=(an&odp[i]);
		if (!an)
		{
			zero=wek[0];
			break;
		}
		vi zywe;
		for (int i=1; i<(int)wek.size(); i++)
			if (odp[i]==an)
				zywe.push_back(wek[i]);
		wek=zywe;
	}
	vi wyn;
	for (int i=0; i<n; i++)
	{
		if (i==zero)
			wyn.push_back(0);
		else
			wyn.push_back(pyt(zero, i));
	}
	ans(wyn);
	return 0;
}