//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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

int n;

char wcz[nax];
int tab[nax];

vi daj(int a, int b)
{
	vi ret;
	for (int i=a; i<=b; i++)
		ret.push_back(tab[i]);
	return ret;
}

vi dod(vi a, vi b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if ((int)b.size()>(int)a.size())
		swap(a, b);
	for (int i=0; i<(int)b.size(); i++)
		a[i]+=b[i];
	for (int i=0; i<(int)a.size(); i++)
	{
		if (a[i]<10)
			continue;
		if (i+1==(int)a.size())
			a.push_back(0);
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	reverse(a.begin(), a.end());
	return a;
}

vi wyn;

void cons(vi v)
{
	if (wyn.empty())
		wyn=v;
	if (v.size()<wyn.size() || (v.size()==wyn.size() && v<wyn))
		wyn=v;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=(wcz[i]-'0');
	int s=n/2;
	vi kan;
	{
		int ile=0;
		for (int i=s+1; i<=n && ile<2; i++)
		{
			if (tab[i])
			{
				ile++;
				kan.push_back(i);
			}
		}
	}
	{
		int ile=0;
		for (int i=s; i>=1 && ile<2; i--)
		{
			if (tab[i+1])
			{
				ile++;
				kan.push_back(i+1);
			}
		}
	}
	for (int i : kan)
		cons(dod(daj(1, i-1), daj(i, n)));
	
	
	for (int i : wyn)
		printf("%d", i);
	printf("\n");
	return 0;
}