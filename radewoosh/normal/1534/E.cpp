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
const int nax=1007;
const ll mod=1000*1000*1000+7;

void ff()
{
	fflush(stdout);
}

int n, k;

int pyt(vi wek)
{
	printf("?");
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	int x;
	scanf("%d", &x);
	return x;
}

void odp(int v)
{
	printf("! v\n");
	ff();
	exit(0);
}

int odl[nax];
int z[nax];
int jak[nax];

int mam[nax];

int main()
{
	scanf("%d%d", &n, &k);
	//~ if (!(k&1) && (n&1))
	//~ {
		//~ printf("-1\n");
		//~ ff();
		//~ return 0;
	//~ }
	//~ if (k==n-1)
	//~ {
		//~ int x=0;
		//~ for (int i=1; i<=n; i++)
		//~ {
			//~ vi wek;
			//~ for (int j=1; j<=n; j++)
				//~ if (j!=i)
					//~ wek.push_back(j);
			//~ x^=pyt(wek);
		//~ }
		//~ odp(x);
	//~ }
	//~ if (!(n%k))
	//~ {
		//~ int x=0;
		//~ int sta=1;
		//~ int kon=k;
		//~ while(sta<=n)
		//~ {
			//~ vi wek;
			//~ for (int j=sta; j<=kon; j++)
				//~ wek.push_back(j);
			//~ x^=pyt(wek);
			//~ sta+=k;
			//~ kon+=k;
		//~ }
		//~ odp(x);
	//~ }
	queue<int> bfs;
	for (int i=0; i<=n; i++)
		odl[i]=-1;
	odl[0]=0;
	bfs.push(0);
	while(!bfs.empty())
	{
		int v=bfs.front();
		bfs.pop();
		for (int i=0; i<=k; i++)
		{
			if (i>v || k-i>n-v)
				continue;
			int nv=v-i+k-i;
			if (odl[nv]==-1)
			{
				odl[nv]=odl[v]+1;
				z[nv]=v;
				jak[nv]=i;
				bfs.push(nv);
			}
		}
	}
	debug() << range(odl, odl+1+n);
	if (odl[n]==-1)
	{
		printf("-1\n");
		ff();
		return 0;
	}
	int g=n;
	int wyn=0;
	while(g)
	{
		int d=jak[g];
		g=z[g];
		vi wek;
		int a=d;
		int b=k-d;
		for (int i=1; i<=n; i++)
		{
			if (!mam[i])
			{
				if (b)
				{
					mam[i]^=1;
					wek.push_back(i);
					b--;
				}
			}
			else
			{
				if (a)
				{
					mam[i]^=1;
					wek.push_back(i);
					a--;
				}
			}
		}
		wyn^=pyt(wek);
	}
	printf("! %d\n", wyn);
	ff();
	return 0;
}