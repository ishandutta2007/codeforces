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
const int nax=100*1007;
const int d=26;

int n;

int q;

char wcz[nax];
int tab[nax];
int nast[nax][d];
int poprz[nax][d];

int quick[nax];

//~ int f(int l, int r);

//~ int f(int l, int r, int alfa)
//~ {
	//~ int xo=0;
	//~ int ost=l-1;
	//~ while(ost<=r)
	//~ {
		//~ int w=min(nast[ost+1][alfa], r+1);
		//~ xo^=f(ost+1, w-1);
		//~ ost=w;
	//~ }
	//~ return xo;
//~ }

unordered_map <int,int> mapa[nax];

//~ int f(int l, int r)
//~ {
	//~ if (l>r)
		//~ return 0;
	//~ if (mapa[l].count(r))
		//~ return mapa[l][r];
	//~ unsigned int mas=0;
	//~ for (int i=0; i<d; i++)
	//~ {
		//~ if (nast[l][i]>r)
			//~ continue;
		//~ mas|=(1<<f(l, r, i));
	//~ }
	//~ return mapa[l][r]=__builtin_ctz(~mas);
//~ }

inline int f_fast(const int &l, const int &r, bool pam=true);

inline int f_fast(const int &l, const int &r, const int &alfa)
{
	int a=nast[l][alfa];
	int b=poprz[r][alfa];
	return quick[b]^quick[a]^f_fast(l, a-1)^f_fast(b+1, r);
}

inline int f_fast(const int &l, const int &r, bool pam)
{
	if (l>r)
		return 0;
	if (mapa[l].count(r))
		return mapa[l][r];
	unsigned int mas=0;
	for (int i=0; i<d; i++)
	{
		if (nast[l][i]>r)
			continue;
		mas|=(1<<f_fast(l, r, i));
	}
	if (pam)
		mapa[l][r]=__builtin_ctz(~mas);
	return __builtin_ctz(~mas);
}

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'a';
	for (int i=0; i<d; i++)
		nast[n+1][i]=n+1;
	for (int i=n; i; i--)
	{
		for (int j=0; j<d; j++)
			nast[i][j]=nast[i+1][j];
		nast[i][tab[i]]=i;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<d; j++)
			poprz[i][j]=poprz[i-1][j];
		poprz[i][tab[i]]=i;
	}
	for (int i=1; i<=n; i++)
	{
		mapa[i].reserve(6*d);
		mapa[i].max_load_factor(0.25);
	}
	for (int i=1; i<=n; i++)
	{
		int w=poprz[i-1][tab[i]];
		quick[i]=quick[w]^f_fast(w+1, i-1);
	}
	scanf("%d", &q);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (f_fast(a, b, false))
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}