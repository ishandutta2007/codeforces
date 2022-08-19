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
const int nax=1007;
const int vax=1007;
//~ const int vax=3;

int n;

vi stos;

bitset <2*vax> bylo[nax];

const int lim=500*1000;
//~ const int lim=1e3;

bool mniej(pair<pii,int> a, pair<pii,int> b)
{
	return abs(a.first.second)<abs(b.first.second);
}

void rek(int v, int roz, int juz, int gle)
{
	if (abs(roz)>vax || gle>lim)
		return;
	if (!v && !roz && juz)
	{
		while((int)stos.size()>1 && !stos.back())
			stos.pop_back();
		reverse(stos.begin(), stos.end());
		for (int i : stos)
			printf("%d", i);
		printf("\n");
		exit(0);
	}
	if (bylo[v][roz+vax])
		return;
	bylo[v][roz+vax]=1;
	vi szaf(10-(!juz));
	for (int i=(!juz); i<10; i++)
		szaf[i-(!juz)]=i;
	random_shuffle(szaf.begin(), szaf.end());
	for (int i : szaf)
	{
		int x=(v+i*n);
		stos.push_back(i);
		rek(x/10, roz+(x%10)*n-i, 1, gle+1);
		stos.pop_back();
	}
}

int main()
{
	//~ srand(time(0));
	scanf("%d", &n);
	for (int h=0; h<10; h++)
	{
		for (int i=0; i<nax; i++)
			bylo[i].reset();
		rek(0, 0, 0, 0);
	}
	printf("-1\n");
	return 0;
}