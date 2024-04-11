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

void ff()
{
	fflush(stdout);
}

int n, m;
int tab[nax];
int juz[nax];

vector <pii> sam;

vector <pair<int,pii> > par;

int out[nax];

int main()
{
	scanf("%d%d", &n, &m);
	n*=2;
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		juz[a]=1;
		juz[b]=1;
		if (tab[b]>tab[a])
			swap(a, b);
		par.push_back({tab[a]-tab[b], {a, b}});
	}
	for (int i=1; i<=n; i++)
	{
		if (!juz[i])
		{
			sam.push_back({tab[i], i});
		}
	}
	int t;
	scanf("%d", &t);
	t&=1;
	sort(sam.begin(), sam.end());
	sort(par.begin(), par.end());
	reverse(sam.begin(), sam.end());
	reverse(par.begin(), par.end());
	for (int i=1; i<=n; i++)
	{
		if ((i&1)==t)
		{
			int czy=0;
			for (auto j : par)
			{
				if (!out[j.second.first])
				{
					printf("%d\n", j.second.first);
					ff();
					int x;
					scanf("%d", &x);
					assert(x==j.second.second);
					out[j.second.first]=1;
					out[j.second.second]=1;
					i++;
					czy=1;
					break;
				}
			}
			if (!czy)
			{
				for (auto j : sam)
				{
					if (!out[j.second])
					{
						out[j.second]=1;
						printf("%d\n", j.second);
						ff();
						break;
					}
				}
			}
		}
		else
		{
			int x;
			scanf("%d", &x);
			if (juz[x])
			{
				for (auto j : par)
				{
					if (j.second.first==x || j.second.second==x)
					{
						out[j.second.first]=1;
						out[j.second.second]=1;
						printf("%d\n", (j.second.first^j.second.second^x));
						ff();
						break;
					}
				}
				i++;
			}
			else
			{
				out[x]=1;
			}
		}
	}
	return 0;
}