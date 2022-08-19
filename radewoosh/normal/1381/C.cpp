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

int n, x, y;

int tab[nax];

int ile[nax];
vi kto[nax];

int wyn[nax];

void tak()
{
	printf("YES\n");
}

void nie()
{
	printf("NO\n");
}

int jeszcze[nax];

void test()
{
	scanf("%d%d%d", &n, &x, &y);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		wyn[i]=0;
	for (int i=1; i<=n+1; i++)
	{
		ile[i]=0;
		kto[i].clear();
	}
	for (int i=1; i<=n; i++)
	{
		ile[tab[i]]++;
		kto[tab[i]].push_back(i);
	}
	priority_queue<pii> kol;
	int pus=0;
	for (int i=1; i<=n+1; i++)
	{
		if (!ile[i])
			pus=i;
		for (int j=1; j<=ile[i]; j++)
			kol.push({j, kto[i][j-1]});
	}
	for (int h=1; h<=x; h++)
	{
		int g=kol.top().second;
		kol.pop();
		wyn[g]=tab[g];
	}
	//~ debug() << range(wyn+1, wyn+1+n);
	int brak=n-y;
	//~ while(brak--)
	//~ {
		//~ int g=kol.top().second;
		//~ kol.pop();
		//~ wyn[g]=pus;
	//~ }
	for (int i=1; i<=n+1; i++)
	{
		jeszcze[i]=0;
	}
	vector<pii> wek;
	for (int i=1; i<=n; i++)
	{
		if (!wyn[i])
		{
			jeszcze[tab[i]]++;
			wek.push_back({tab[i], i});
		}
	}
	sort(wek.begin(), wek.end());
	int naj=0;
	for (int i=1; i<=n+1; i++)
		naj=max(naj, jeszcze[i]);
	int gupi;
	for (int i=1; i<=n+1; i++)
		if (jeszcze[i]==naj)
			gupi=i;
	int nadal=n-x;
	assert(nadal==(int)wek.size());
	if (naj*2-nadal<=brak)
	{
		//~ debug() << wek;
		tak();
		for (int i=0; i<nadal; i++)
		{
			if (wek[i].first==gupi && brak)
			{
				wyn[wek[i].second]=pus;
				brak--;
			}
			else
			{
				wyn[wek[i].second]=wek[(i-naj+nadal)%nadal].first;
			}
		}
		for (pii i : wek)
		{
			if (wyn[i.second]!=pus && brak)
			{
				wyn[i.second]=pus;
				brak--;
			}
		}
		for (int i=1; i<=n; i++)
			printf("%d ", wyn[i]);
		printf("\n");
	}
	else
	{
		nie();
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}