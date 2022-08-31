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
const int nax=107;

int n, k;

vi wek[nax];

int kied[nax];

void ans(int v)
{
	if (v)
		printf("ACCEPTED\n");
	else
		printf("REJECTED\n");
	exit(0);
}

int mam[nax];

int mac[nax][nax];

vi gru[nax];

int stan[nax][nax];

void check()
{
	for (int i=2; i<=n; i++)
		if (stan[k][i]>stan[k][i-1])
			ans(0);
}

void rek(int v)
{
	if (v==k+1)
	{
		check();
		return;
	}
	int r=gru[v].size();
	for (int i=0; i<=r; i++)
	{
		for (int i=1; i<=n; i++)
			stan[v][i]=stan[v-1][i];
		int ile=i;
		for (int j : wek[v])
			ile+=stan[v][j];
		for (int j : wek[v])
		{
			stan[v][j]=(ile>0);
			ile--;
		}
		rek(v+1);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	if (n==1)
		ans(1);
	for (int i=1; i<=n; i++)
		kied[i]=k+1;
	for (int i=1; i<=n; i++)
		mac[i][i]=1;
	for (int i=1; i<=k; i++)
	{
		int a, b;
		scanf("%d", &a);
		while(a--)
		{
			scanf("%d", &b);
			wek[i].push_back(b);
			kied[b]=min(kied[b], i);
		}
		for (int p=1; p<=n; p++)
			for (int j : wek[i])
				for (int l : wek[i])
					mac[p][l]|=mac[p][j];
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (!mac[i][j])
				ans(0);
	for (int i=1; i<=n; i++)
		if (kied[i]==k+1)
			ans(0);
	for (int i=1; i<=n; i++)
		gru[kied[i]].push_back(i);
	rek(1);
	ans(1);
	return 0;
}