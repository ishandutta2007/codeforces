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

int n, k;

char wcz[nax];
int tab[nax];

int dzmas;

int spoko(int mas)
{
	if (!(mas&(1<<k)))
		return 1;
	if (mas&dzmas)
		return 1;
	return 0;
}

void skroc(int &mas)
{
	mas&=((1<<k)-1);
	int x=(mas&dzmas);
	if (!x)
		return;
	x&=-x;
	mas&=(x-1);
}

unordered_map<int,int> mapa[nax];

int rek(int v, int mas)
{
	if (v==n)
		return 0;
	skroc(mas);
	if (mapa[v].count(mas))
		return mapa[v][mas];
	int ret=rek(v+1, mas)+1;
	int wte=mas;
	mas=(mas<<tab[v+1])|1;
	if (spoko(mas))
		ret=min(ret, rek(v+1, mas));
	return mapa[v][wte]=ret;
}

int main()
{
	scanf("%s%d", wcz+1, &k);
	for (int i=1; i<k; i++)
		if (!(k%i))
			dzmas|=(1<<i);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'0';
	printf("%d\n", rek(0, 1));
	return 0;
}