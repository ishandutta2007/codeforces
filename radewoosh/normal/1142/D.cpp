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
const int n1=(1<<17);

int n;
char wcz[nax];

vi nor[10];
vi nope;

vi drz[nax];

ll wyn;

vi zloz(vi a, vi b)
{
	vi ret(11);
	for (int i=0; i<=10; i++)
	{
		if (a[i]==-1)
			ret[i]=-1;
		ret[i]=b[a[i]];
	}
	return ret;
}

int gdz[nax][12];

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	nope.resize(10, -1);
	for (int i=0; i<10; i++)
	{
		nor[i].resize(11);
		for (int j=0; j<=10; j++)
		{
			if (i>=j)
			{
				nor[i][j]=-1;
			}
			else
			{
				int x=0;
				for (int l=0; l<j; l++)
					x+=l;
				x+=i-1+11;
				x%=11;
				nor[i][j]=x;
			}
		}
		//~ debug() << i << " " << nor[i];
	}
	//~ for (int i=1; i<=n1; i++)
		//~ drz[n1-1+i]=nope;
	//~ for (int i=1; i<=n; i++)
		//~ drz[n1-1+i]=nor[wcz[i]-'0'];
	for (int j=0; j<=10; j++)
		gdz[n+1][j]=n+1;
	for (int i=n; i; i--)
	{
		int x=wcz[i]-'0';
		for (int j=0; j<=10; j++)
		{
			int y=nor[x][j];
			if (y==-1)
				gdz[i][j]=i;
			else
				gdz[i][j]=gdz[i+1][y];
		}
		if (x)
			wyn+=gdz[i+1][x]-i;
	}
	printf("%lld\n", wyn);
	return 0;
}