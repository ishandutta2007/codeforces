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
const ll mod=998244353;

int n;

int tab[nax][nax];

int zle[nax][nax];

vi graf[nax];

ll spo;
vi wyn;

int juz[nax];

vi kto[nax];

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=2*n; i++)
		graf[i].clear();
	for (int i=1; i<=2*n; i++)
	{
		for (int j=1; j<=n; j++)
			scanf("%d", &tab[i][j]);
		for (int j=1; j<i; j++)
		{
			zle[i][j]=0;
			for (int l=1; l<=n; l++)
				if (tab[i][l]==tab[j][l])
					zle[i][j]=1;
			zle[j][i]=zle[i][j];
			if (zle[i][j])
			{
				graf[i].push_back(j);
				graf[j].push_back(i);
			}
		}
		juz[i]=0;
	}
	spo=1;
	wyn.clear();
	for (int h=1; h<=n; h++)
	{
		int ruch=0;
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				kto[j].clear();
			}
			for (int j=1; j<=2*n; j++)
				if (!juz[j])
					kto[tab[j][i]].push_back(j);
			for (int j=1; j<=n; j++)
			{
				if ((int)kto[j].size()==1)
				{
					int x=kto[j][0];
					wyn.push_back(x);
					//~ debug() << x << " jako " << j << " w " << i;
					juz[x]=1;
					for (int l : graf[x])
						juz[l]=1;
					ruch=1;
					break;
				}
			}
			if (ruch)
				break;
		}
		if (!ruch)
		{
			//~ debug() << "nie wiem " <
			for (int i=1; i<=2*n; i++)
			{
				if (!juz[i])
				{
					juz[i]=1;
					for (int j : graf[i])
						juz[j]=1;
					wyn.push_back(i);
					spo=(spo*2)%mod;
					break;
				}
			}
		}
	}
	//~ debug() << wyn;
	printf("%lld\n", spo);
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
}


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}