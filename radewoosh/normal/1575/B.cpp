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
using ld=long double;
const ld eps=1e-15;
using pdd=pair<ld,ld>;
const ld pi=2*acosl(0);

int n, k;
pll tab[nax];

pdd operator +(pdd a, pdd b)
{
	return {a.first+b.first, a.second+b.second};
}

pdd operator -(pdd a, pdd b)
{
	return {a.first-b.first, a.second-b.second};
}

pdd operator *(pdd a, ld b)
{
	return {a.first*b, a.second*b};
}

pdd operator /(pdd a, ld b)
{
	return {a.first/b, a.second/b};
}

ld ilowek(pdd s, pdd a, pdd b)
{
	a=a-s;
	b=b-s;
	return a.first*b.second-a.second*b.first;
}

ld iloska(pdd s, pdd a, pdd b)
{
	a=a-s;
	b=b-s;
	return a.first*b.first+a.second*b.second;
}

ld odl(pdd a, pdd b)
{
	return sqrt(iloska(a, b, b));
}

ld odl(pdd x, pdd a, pdd b)
{
	return abs(ilowek(a, b, x)/odl(a, b));
}

pdd norm(pdd v)
{
	return v/odl({0, 0}, v);
}

int iszero(ld v)
{
	return abs(v)<eps;
}

pdd rotate90(pdd v)
{
	return {v.second, -v.first};
}

ld dlu(pdd v)
{
	return odl(v, {0, 0});
}

int check(ld v)
{
	int bil=0;
	vector<pair<ld,int>>wek;
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==make_pair(0LL, 0LL))
		{
			bil++;
			continue;
		}
		ld r2=tab[i].first*tab[i].first+tab[i].second*tab[i].second;
		ld r=sqrt(r2);
		if (r>2*v-eps)
			continue;
		ld p=r/2;
		ld bok=sqrt(v*v-p*p);
		pdd sr={tab[i].first, tab[i].second};
		sr=sr/2;
		pdd kop=sr;
		kop=kop/dlu(kop);
		pdd a=sr+(rotate90(kop)*bok);
		pdd b=sr-(rotate90(kop)*bok);
		ld raz=atan2(a.first, a.second);
		ld dwa=atan2(b.first, b.second);
		while (abs(raz+2*pi-dwa)<abs(raz-dwa))
			raz+=2*pi;
		while (abs(raz-2*pi-dwa)<abs(raz-dwa))
			raz-=2*pi;
		while(raz>0)
		{
			raz-=2*pi;
			dwa-=2*pi;
		}
		while(raz<0)
		{
			raz+=2*pi;
			dwa+=2*pi;
		}
		if (raz>dwa)
			swap(raz, dwa);
		//~ debug() << i << " " << raz << " " << dwa;
		for (int h=0; h<2; h++)
		{
			wek.push_back({raz+h*2*pi, 1});
			wek.push_back({dwa+h*2*pi, -1});
		}
	}
	if (bil>=k)
		return 1;
	sort(wek.begin(), wek.end());
	for (auto i : wek)
	{
		bil+=i.second;
		if (bil>=k)
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	ld bsa=0;
	ld bsb=2e5;
	for(int h=0; bsa+eps<bsb && h<40; h++)
	{
		ld bss=(bsa+bsb)/2;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss;
	}
	ld wyn=(bsa+bsb)/2;
	printf("%.9lf\n", (double)wyn);
	//~ debug() << check(4);
	return 0;
}