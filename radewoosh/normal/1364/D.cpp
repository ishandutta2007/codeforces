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

int bylo[nax];
int kol[nax];

vi stos;

int nac[nax];

vi skroc(vi wek)
{
	for (int i=1; i<=n; i++)
		nac[i]=0;
	for (int i : wek)
		nac[i]=1;
	int po=-2;
	int na=0;
	int r=wek.size();
	for (int i : wek)
	{
		po=(po+1+r*7)%r;
		na=(na+1+r*7)%r;
		for (int j : graf[i])
		{
			if (nac[j] && j!=wek[po] && j!=wek[na])
			{
				int a=0;
				int b=0;
				while(wek[a]!=i)
					a++;
				while(wek[b]!=j)
					b++;
				vi now;
				if (b-a<(int)wek.size()-(b-a))
				{
					for (int l=a; l<=b; l++)
						now.push_back(wek[l]);
				}
				else
				{
					for (int l=b; l<(int)wek.size(); l++)
						now.push_back(wek[l]);
					for (int l=0; l<=a; l++)
						now.push_back(wek[l]);
				}
				return skroc(now);
			}
		}
	}
	return wek;
}

void dfs(int v, int oj, int kk)
{
	if (bylo[v])
	{
		int g=0;
		while(stos[g]!=v)
			g++;
		vi wek;
		for (int i=g; i<(int)stos.size(); i++)
			wek.push_back(stos[i]);
		debug() << imie(wek);
		wek=skroc(wek);
		debug() << imie(wek);
		if ((int)wek.size()<=k)
		{
			printf("2\n");
			printf("%d\n", (int)wek.size());
			for (int i : wek)
				printf("%d ", i);
			printf("\n");
		}
		else
		{
			printf("1\n");
			int ile=(k+1)/2;
			for (int i=0; i<ile; i++)
				printf("%d ", wek[2*i]);
			printf("\n");
		}
		exit(0);
	}
	kol[v]=kk;
	bylo[v]=1;
	stos.push_back(v);
	for (int i : graf[v])
		if (i!=oj)
			dfs(i, v, 3-kk);
	stos.pop_back();
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1, 0, 1);
	vi gdz[2];
	for (int i=1; i<=n; i++)
		gdz[kol[i]&1].push_back(i);
	if ((int)gdz[1].size()>(int)gdz[0].size())
		swap(gdz[0], gdz[1]);
	printf("1\n");
	for (int i=0; i<(k+1)/2; i++)
		printf("%d ", gdz[0][i]);
	printf("\n");
	return 0;
}