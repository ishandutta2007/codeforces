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
const int nax=5000*1007;

int h, g;
int n;

ll tab[nax];

ll s;

vi oper;

int szuk(int v)
{
	if (!tab[v*2] && !tab[v*2+1])
		return 0;
	if (tab[v*2]>tab[v*2+1])
		return szuk(v*2)+1;
	return szuk(v*2+1)+1;
}

void usun(int v)
{
	if (!tab[v*2] && !tab[v*2+1])
	{
		tab[v]=0;
		return;
	}
	int cel;
	if (tab[v*2]>tab[v*2+1])
	{
		cel=v*2;
	}
	else
	{
		cel=v*2+1;
	}
	swap(tab[v], tab[cel]);
	usun(cel);
}

void test()
{
	scanf("%d%d", &h, &g);
	n=(1<<h)-1;
	s=0;
	for (int i=1; i<=2*n+1; i++)
		tab[i]=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		s+=tab[i];
	}
	oper.clear();
	for (int i=1; i<(1<<g); i++)
	{
		int poz=31-__builtin_clz(i)+1;
		//~ debug() << i << " " << poz;
		while(tab[i])
		{
			int ile=szuk(i);
			if (poz+ile==g)
				break;
			s-=tab[i];
			usun(i);
			oper.push_back(i);
		}
	}
	
	
	
	printf("%lld\n", s);
	for (int i : oper)
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