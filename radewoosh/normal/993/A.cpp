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
const int nax=207;
const int d=100;
using pii=pair<int,int>;

void ans(string s)
{
	cout << s << endl;
	exit(0);
}

pii tab[2][4];

int ter[nax][nax];

int pam[nax][nax];

pii rusz(pii v, pii u)
{
	if (v.first<u.first)
		v.first++;
	if (v.first>u.first)
		v.first--;
	if (v.second<u.second)
		v.second++;
	if (v.second>u.second)
		v.second--;
	return v;
}

int czy(int v, int u)
{
	int ret=0;
	for (int i=v; i<nax; i++)
		if (ter[i][u])
			ret|=1;
	for (int i=0; i<=v; i++)
		if (ter[i][u])
			ret|=2;
	for (int i=u; i<nax; i++)
		if (ter[v][i])
			ret|=4;
	for (int i=0; i<=u; i++)
		if (ter[v][i])
			ret|=8;
	return (ret==15);
}

int main()
{
	for (int h=0; h<2; h++)
	{
		for (int i=0; i<4; i++)
		{
			scanf("%d%d", &tab[h][i].first, &tab[h][i].second);
			tab[h][i].first+=d;
			tab[h][i].second+=d;
		}
		memset(ter, 0, sizeof(ter));
		for (int i=0; i<4; i++)
		{
			int j=(i+1)%4;
			pii a=tab[h][i];
			pii b=tab[h][j];
			while(a!=b)
			{
				ter[a.first][a.second]=1;
				a=rusz(a, b);
			}
		}
		for (int i=0; i<nax; i++)
			for (int j=0; j<nax; j++)
				ter[i][j]=czy(i, j);
		for (int i=0; i<nax; i++)
			for (int j=0; j<nax; j++)
				pam[i][j]+=ter[i][j];
	}
	for (int i=0; i<nax; i++)
		for (int j=0; j<nax; j++)
			if (pam[i][j]==2)
				ans("Yes");
	ans("No");
	return 0;
}