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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

#define shandom_ruffle random_shuffle

const int nax=1000*1007;

int n, m;

vector <int> graf[nax];

int odl[nax];

int dok[nax];

int oj[nax];

void dfs(int v)
{
	for (int i : graf[v])
	{
		if (odl[i])
		{
			if (odl[i]<odl[v] && i!=oj[v])
			{
				int mini=n+7;
				int maxi=-7;
				int u=v;
				while(u!=i)
				{
					mini=min(mini, u);
					maxi=max(maxi, u);
					u=oj[u];
					mini=min(mini, u);
					maxi=max(maxi, u);
				}
				dok[mini]=min(dok[mini], maxi-1);
			}
			continue;
		}
		oj[i]=v;
		odl[i]=odl[v]+1;
		dfs(i);
	}
}

long long sum[nax];

void query()
{
	int l, r;
	scanf("%d%d", &l, &r);
	int bsa=l-1;
	int bsb=r;
	int bss;
	while(bsa<bsb)
	{
		bss=(bsa+bsb+2)>>1;
		if (dok[bss]<=r)
			bsa=bss;
		else
			bsb=bss-1;
	}
	long long pocz=bsa+1;
	long long kon=r;
	printf("%lld\n", sum[bsa]-sum[l-1]-(pocz+kon)*(kon-pocz+1)/2+(kon-pocz+1)*(r+1));
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		dok[i]=n;
	for (int i=1; i<=n; i++)
	{
		if (!odl[i])
		{
			odl[i]=1;
			dfs(i);
		}
	}
	for (int i=n; i>1; i--)
		dok[i-1]=min(dok[i-1], dok[i]);
	for (int i=1; i<=n; i++)
		sum[i]=sum[i-1]+dok[i]-i+1;
	int q;
	scanf("%d", &q);
	while(q--)
		query();
	return 0;
}