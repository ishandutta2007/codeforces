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
const int nax=1000*1007;

int n;

ll tab[nax];

set <int> wyn;

ll sum[nax];

vector <pair<ll,int> > wek;

int check(int v)
{
	//~ debug() << "pacze " << v;
	wek.clear();
	int m=n+1;
	for (int i=1; i<=n; i++)
		wek.push_back({tab[i], 0});
	wek.push_back({v, 1});
	for (int i=m-1; i>0; i--)
		if (wek[i]>wek[i-1])
			swap(wek[i], wek[i-1]);
	//~ sort(wek.begin(), wek.end());
	//~ reverse(wek.begin(), wek.end());
	for (int i=m-1; i>=0; i--)
		sum[i]=sum[i+1]+wek[i].first;
	int g=-1;
	for (int i=0; i<m; i++)
		if (wek[i].second)
			g=i;
	ll trz=0;
	int w=m;
	for (int i=1; i<=m; i++)
	{
		w=max(w, i);
		trz+=wek[i-1].first;
		while(w>i && wek[w-1].first<i)
			w--;
		if (trz<=i*(i-1LL)+sum[w]+(w-i)*(ll)i)
			continue;
		if (g<i)
			return -1;
		return 1;
	}
	//~ debug() << wek;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+n);
	reverse(tab+1, tab+1+n);
	ll parz=0;
	for (int i=1; i<=n; i++)
		parz+=tab[i];
	parz&=1;
	int bsa=0;
	int bsb=n;
	int mam=-1;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb)>>1;
		int v=check(bss);
		if (v==0)
		{
			mam=bss;
			break;
		}
		if (v==-1)
			bsb=bss;
		else
			bsa=bss+1;
	}
	if (!check(bsa))
		mam=bsa;
	if (mam>=0)
	{
		//~ debug() << imie(mam);
		int sr=mam;
		bsa=0;
		bsb=sr;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb)>>1;
			if (!check(bss))
				bsb=bss;
			else
				bsa=bss+1;
		}
		for (int i=bsa; i<=sr; i++)
			wyn.insert(i);
		bsa=sr;
		bsb=n;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb+2)>>1;
			if (!check(bss))
				bsa=bss;
			else
				bsb=bss-1;
		}
		for (int i=sr; i<=bsa; i++)
			wyn.insert(i);
	}
	
	set <int> pom=wyn;
	wyn.clear();
	for (int i : pom)
		if ((i&1)==parz)
			wyn.insert(i);
	if (wyn.empty())
		wyn.insert(-1);
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
	return 0;
}