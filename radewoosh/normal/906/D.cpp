//while (clock()<=69*CLOCKS_PER_SEC)
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

const int nax=1000*1007;
using ll=long long;

int n, m;

vector <ll> mod;

ll tab[nax];

ll phi(ll v)
{
	vector <ll> dzi;
	for (ll i=2; i*i<=v; i++)
	{
		if (!(v%i))
		{
			dzi.push_back(i);
			v/=i;
			i--;
		}
	}
	dzi.push_back(v);
	ll ret=1;
	ll ost=-1;
	for (ll i : dzi)
	{
		if (ost==i)
			ret*=i;
		else
			ret*=(i-1);
		ost=i;
	}
	return ret;
}

inline ll modulo(ll a, ll b)
{
	if (a<b)
		return a;
	return (a%b)+b;
}



ll policz(int l, int r, int kt)
{
	if (l>r || kt>=(int)mod.size())
		return 1;
	ll pot=policz(l+1, r, kt+1);
	ll x=tab[l];
	ll ret=1;
	while(pot)
	{
		if (pot&1)
			ret=modulo(ret*x, mod[kt]);
		x=modulo(x*x, mod[kt]);
		pot>>=1;
	}
	return ret;
}

void query()
{
	int l, r;
	scanf("%d%d", &l, &r);
	printf("%lld\n", policz(l, r, 0)%m);
}

int main()
{
	scanf("%d%d", &n, &m);
	mod.push_back(m);
	while(mod.back()!=1)
		mod.push_back(phi(mod.back()));
	debug() << mod;
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	int q;
	scanf("%d", &q);
	while(q--)
		query();
	return 0;
}