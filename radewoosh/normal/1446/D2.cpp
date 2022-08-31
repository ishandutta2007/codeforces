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
const int d=400;

int n;

int tab[nax];

int ile[nax];
int naj;

int wyn;

//~ int najcz[nax];

int war[nax];

int pier[nax];

void run(int v)
{
	for (int i=0; i<=2*n+7; i++)
		pier[i]=nax;
	for (int i=1; i<=n; i++)
	{
		war[i]=0;
		if (tab[i]==1)
			war[i]=1;
		if (tab[i]==v)
			war[i]=-1;
	}
	int s=0;
	for (int i=0; i<=n; i++)
	{
		wyn=max(wyn, i-pier[n+2+s]);
		pier[n+2+s]=min(i, pier[n+2+s]);
		s+=war[i+1];
	}
}

int czas;
int ost[nax];
int teraz[nax];

int najwie;

void reset()
{
	najwie=0;
	czas++;
}

void dodaj(int v)
{
	if (ost[v]!=czas)
	{
		ost[v]=czas;
		teraz[v]=0;
	}
	teraz[v]++;
	najwie=max(najwie, teraz[v]);
}

void male()
{
	for (int i=1; i<=n; i++)
	{
		if (i==n || tab[i+1]==1)
		{
			reset();
			int duze=0;
			for (int j=i; j && duze<d+7; j--)
			{
				if (tab[j]==1)
					duze++;
				else
					dodaj(tab[j]);
				if (najwie>=duze)
					wyn=max(wyn, i-j+1);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		ile[tab[i]]++;
	for (int i=1; i<=n; i++)
	{
		if (ile[i]==n)
		{
			printf("0\n");
			return 0;
		}
		if (ile[i]>ile[naj])
			naj=i;
	}
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==1)
		{
			tab[i]=naj;
			continue;
		}
		if (tab[i]==naj)
		{
			tab[i]=1;
			continue;
		}
	}
	//~ debug() << range(tab+1, tab+1+n);
	//~ for (int i=1; i<=n; i++)
		//~ najcz[i]=najcz[i-1]+(tab[i]==1);
	for (int i=2; i<=n; i++)
		if (ile[i]>=d)
			run(i);
	male();
	printf("%d\n", wyn);
	return 0;
}