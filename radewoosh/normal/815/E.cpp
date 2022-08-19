//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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

using ll=long long;

map < ll , vector < pair <ll,ll> > > mapa;

void liczwek(ll n)
{
	if (!n || mapa.count(n))
		return;
	ll s=(n+1)/2;
	liczwek(s-1);
	liczwek(n-s);
	
	vector < pair <ll,ll> > wek, pom;
	for (auto i : mapa[s-1])
		wek.push_back(i);
	for (auto i : mapa[n-s])
		wek.push_back(i);
	wek.push_back({s-1, 1LL});
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	for (auto i : wek)
	{
		if (pom.empty() || pom.back().first!=i.first)
			pom.push_back({i.first, 0LL});
		pom.back().second+=i.second;
	}
	
	mapa[n]=pom;
}

ll liczpos(ll n, ll k)
{
	ll s=(n+1)/2;
	if (k==1)
		return s;
	liczwek(n);
	ll jak=0;
	ll kk=k-1;
	ll juzl=0;
	ll juzp=0;
	
	vector < pair < pair <ll,int> , ll > > wek;
	for (auto i : mapa[s-1])
		wek.push_back({{i.first, 1}, i.second});
	for (auto i : mapa[n-s])
		wek.push_back({{i.first, 0}, i.second});
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	
	//debug() << "cisne " << n << " " << k;
	
	for (auto i : wek)
	{
		//debug() << i;
		if (i.second<kk)
		{
			kk-=i.second;
			if (i.first.second)
				juzl+=i.second;
			else
				juzp+=i.second;
			continue;
		}
		if (i.first.second)
			return liczpos(s-1, k-juzp-1);
		else
			return s+liczpos(n-s, k-juzl-1);
	}
}

int main()
{
	ll n, k;
	scanf("%lld%lld", &n, &k);
	if (k==1)
	{
		printf("1\n");
		return 0;
	}
	if (k==2)
	{
		printf("%lld\n", n);
		return 0;
	}
	printf("%lld\n", 1+liczpos(n-2, k-2));
	return 0;
}