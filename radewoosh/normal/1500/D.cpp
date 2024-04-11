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
const int nax=1507;
const int vax=12;

int n, q;

int tab[nax][nax];

int wyn[nax];

int roz[nax][nax];

vector<pii> now[nax], sta[nax];

vector<pii> pom;

int czas;
int ost[nax*nax];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &tab[i][j]);
	
	for (int i=n; i; i--)
	{
		for (int j=n; j; j--)
		{
			sta[j].swap(now[j]);
			now[j].clear();
		}
		for (int j=n; j; j--)
		{
			pom.clear();
			for (pii l : sta[j])
				pom.push_back({l.first+1, l.second});
			for (pii l : sta[j+1])
				pom.push_back({l.first+1, l.second});
			for (pii l : now[j+1])
				pom.push_back({l.first+1, l.second});
			pom.push_back({1, tab[i][j]});
			if (i<n && j<n && roz[i+1][j]==roz[i][j+1])
			{
				int r=roz[i+1][j];
				pom.push_back({r+1, tab[i+r][j+r]});
			}
			sort(pom.begin(), pom.end());
			roz[i][j]=min(n-i, n-j)+1;
			roz[i][j]=min(roz[i][j], roz[i+1][j]+1);
			roz[i][j]=min(roz[i][j], roz[i][j+1]+1);
			roz[i][j]=min(roz[i][j], roz[i+1][j+1]+1);
			czas++;
			int widz=0;
			//~ debug() << i << " " << j << " " << pom;
			for (pii l : pom)
			{
				if (ost[l.second]==czas)
					continue;
				if (widz==q)
				{
					roz[i][j]=min(roz[i][j], l.first-1);
					break;
				}
				ost[l.second]=czas;
				now[j].push_back(l);
				widz++;
			}
			//~ debug() << i << " " << j << " " << wek[j];
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		//~ debug() << range(roz[i]+1, roz[i]+1+n);
		for (int j=1; j<=n; j++)
			wyn[roz[i][j]]++;
	}
	
	for (int i=n; i; i--)
		wyn[i-1]+=wyn[i];
	for (int i=1; i<=n; i++)
		printf("%d\n", wyn[i]);
	return 0;
}