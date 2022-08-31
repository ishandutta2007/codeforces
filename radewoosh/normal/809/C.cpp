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

const long long mod=1000*1000*1000+7;

map < pair < pair <int,int> , int> , pair <long long, long long> > mapa;

inline void dziel(long long &v)
{
	if(v&1)
		v+=mod;
	v/=2;
}

inline int naj(int v)
{
	int r=1;
	while(r*2<v)
		r*=2;
	return r;
}

inline pair <long long,long long> dod(pair <long long,long long> a, pair <long long,long long> b)
{
	a.first+=b.first;
	a.second+=b.second;
	return a;
}

pair <long long,long long> licz(int a, int b, int k)
{
	if (a>b)
		swap(a, b);
	int r=naj(b);
	k=min(k, 2*r);
	if (a<=0 || b<=0 || k<=0)
		return {0, 0};
	pair <long long,long long> ret={0, 0};
	if (a==b && __builtin_popcount(a)==1)//kwadrat
	{
		k=min(k, a);
		ret.first=a;
		ret.first*=k;
		ret.first%=mod;
		ret.first*=(k+1);
		ret.first%=mod;
		dziel(ret.first);
		
		ret.second=a;
		ret.second*=k;
		ret.second%=mod;
		return ret;
	}
	if (mapa.count({{a, b}, k}))
		return mapa[{{a, b}, k}];
	
	
	ret=dod(licz(min(a, r), min(b, r), k), licz(a-r, b-r, k));
	
	auto ret2=dod(licz(min(a, r), b-r, k-r), licz(a-r, min(b, r), k-r));
	
	ret2.first+=ret2.second*r;
	ret2.first%=mod;
	
	ret=dod(ret, ret2);
	
	ret.first%=mod;
	ret.second%=mod;
	
	mapa[{{a, b}, k}]=ret;
	return ret;
}

int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
	{
		mapa.clear();
		int a, b, x, y, k;
		scanf("%d%d%d%d%d", &a, &b, &x, &y, &k);
		long long wyn=licz(x, y, k).first-licz(x, b-1, k).first-licz(a-1, y, k).first+licz(a-1, b-1, k).first;
		wyn%=mod;
		wyn+=mod;
		wyn%=mod;
		printf("%lld\n", wyn);
	}
	return 0;
}