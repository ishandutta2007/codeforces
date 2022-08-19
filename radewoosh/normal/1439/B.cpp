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

int n, m, k;

vi graf[nax];
int sto[nax];

int dead[nax];

void zbior()
{
	vi wek;
	for (int i=1; i<=n; i++)
		if (!dead[i])
			wek.push_back(i);
	printf("1 %d\n", (int)wek.size());
	for (int i : wek)
		printf("%d ", i);
	printf("\n");
}

int czas;
int ost[nax];

vi nor[nax];

void test()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=n; i++)
	{
		sto[i]=dead[i]=0;
		graf[i].clear();
		ost[i]=0;
		nor[i].clear();
	}
	czas=0;
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		sto[a]++;
		sto[b]++;
		graf[a].push_back(b);
		graf[b].push_back(a);
		nor[a].push_back(b);
		nor[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		sort(nor[i].begin(), nor[i].end());
	queue<int> kol;
	for (int i=1; i<=n; i++)
		if (sto[i]<k)
			kol.push(i);
	int mozliwe=(k*(k-1LL)/2<=m);
	for (int h=n; h; h--)
	{
		//~ debug() << imie(h);
		if (kol.empty())
		{
			zbior();
			return;
		}
		int v=kol.front();
		kol.pop();
		//~ debug() << imie(v);
		if (sto[v]==k-1 && mozliwe)
		{
			czas++;
			vi som, wyp;
			for (int i : graf[v])
			{
				if (dead[i])
					continue;
				som.push_back(i);
				ost[i]=czas;
			}
			sort(som.begin(), som.end());
			wyp=som;
			wyp.push_back(v);
			sort(wyp.begin(), wyp.end());
			int ok=1;
			for (int i : som)
			{
				if (!ok)
					break;
				for (int j : som)
				{
					if (i==j)
						break;
					if (!ok)
						break;
					if (!binary_search(nor[i].begin(), nor[i].end(), j))
						ok=0;
				}
			}
			if (ok)
			{
				printf("2\n");
				for (int i : wyp)
					printf("%d ", i);
				printf("\n");
				return;
			}
		}
		//~ debug() << "po " << v;
		dead[v]=1;
		for (int i : graf[v])
		{
			if (dead[i])
				continue;
			sto[i]--;
			if (sto[i]==k-1)
				kol.push(i);
		}
		//~ debug() << "sup";
	}
	printf("-1\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}