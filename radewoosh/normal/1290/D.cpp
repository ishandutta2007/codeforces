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

void ff()
{
	fflush(stdout);
}

int pyt(int v)
{
	v++;
	printf("? %d\n", v);
	ff();
	char c;
	scanf(" %c", &c);
	return (c=='Y');
}

void ans(int v)
{
	printf("! %d\n", v);
	ff();
	exit(0);
}

void reset()
{
	printf("R\n");
	ff();
}

int n, k;

int mniej[nax];

void koniec()
{
	int wyn=0;
	for (int i=0; i<n; i++)
		if (!mniej[i])
			wyn++;
	ans(wyn);
}

int main()
{
	scanf("%d%d", &n, &k);
	//~ for (int i=0; i<n; i++)
	//~ {
		//~ if (pyt(i))
			//~ mniej[i]=1;
	//~ }
	reset();
	int m=n/k;
	if (m==1)
	{
		for (int i=0; i<n; i++)
		{
			if (pyt(i))
				mniej[i]=1;
		}
		koniec();
	}
	vector <vi> cyk;
	for (int i=0; i<m/2; i++)
	{
		vi ter{i};
		for (int j=1; j<m/2; j++)
		{
			ter.push_back((i+j)%m);
			ter.push_back((i-j+m)%m);
		}
		ter.push_back((i+m/2)%m);
		cyk.push_back(ter);
	}
	for (vi i : cyk)
	{
		reset();
		for (int j : i)
		{
			for (int l=0; l<k; l++)
			{
				int v=j*k+l;
				if (mniej[v])
					continue;
				if (pyt(v))
					mniej[v]=1;
			}
		}
	}
	for (vi i : cyk)
	{
		reset();
		for (int j : i)
		{
			for (int l=k-1; l>=0; l--)
			{
				int v=j*k+l;
				if (mniej[v])
					continue;
				if (pyt(v))
					mniej[v]=1;
			}
		}
	}
	//~ debug() << cyk;
	
	
	
	koniec();
	return 0;
}