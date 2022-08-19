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
const int nax=3007;

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

pll operator + (pll a, pll b)
{
	return {a.first+b.first, a.second+b.second};
}

pll operator * (pll a, ll b)
{
	return {a.first*b, a.second*b};
}

pll rotate90cw(pll v)
{
	return {v.second, -v.first};
}

pll rotate90ccw(pll v)
{
	return {-v.second, v.first};
}

ll iloska(pll a, pll b)
{
	return a.first*b.first+a.second*b.second;
}

ll ilowek(pll s, pll a, pll b)
{
	a=a-s;
	b=b-s;
	return a.first*b.second-a.second*b.first;
}

ll dlu(pll v)
{
	return iloska(v, v);
}

ll odl(pll a, pll b)
{
	return dlu(a-b);
}

pll cen;
int typ(pll v)
{
	if (v>cen)
		return 1;
	return 0;
}

bool mniej(pll a, pll b)
{
	int t1=typ(a);
	int t2=typ(b);
	if (t1!=t2)
		return t1<t2;
	//~ if (ilowek(cen, a, b))
		return ilowek(cen, a, b)<0;
	//~ return odl(cen, a)<odl(cen, b);
}

vector <pll> get_hull(vector <pll> wek)
{
	auto pom=wek;
	sort(pom.begin(), pom.end());
	wek.clear();
	for (pll i : pom)
		if (wek.empty() || wek.back()!=i)
			wek.push_back(i);
	pom=wek;
	wek.clear();
	cen=pom[0];
	sort(pom.begin()+1, pom.end(), mniej);
	for (pll i : pom)
	{
		int r=wek.size();
		while(r>1 && ilowek(wek[r-2], wek[r-1], i)>0)
		{
			r--;
			wek.pop_back();
		}
		wek.push_back(i);
	}
	return wek;
}

int n;
pll tab[nax];

ll wyn;

ll wyb4(ll v)
{
	return v*(v-1)*(v-2)*(v-3)/24;
}

ll wyb3(ll v)
{
	return v*(v-1)*(v-2)/6;
}

void solve(vector <pll> &wek)
{
	cen={0, 0};
	sort(wek.begin(), wek.end(), mniej);
	//~ debug() << wek;
	int r=n-1;
	for (int i=0; i<2*r; i++)
	{
		pll x=wek[i];
		wek.push_back(x);
	}
	int w=0;
	ll ret=wyb4(r);
	for (int i=0; i<r; i++)
	{
		w=max(w-1, 0);
		while(ilowek(cen, wek[i], wek[i+w+1])<0)
			w++;
		ret-=wyb3(w);
	}
	wyn+=ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	for (int i=1; i<=n; i++)
	{
		vector <pll> wek;
		for (int j=1; j<=n; j++)
			if (i!=j)
				wek.push_back(tab[j]-tab[i]);
		solve(wek);
	}
	printf("%lld\n", wyn);
	return 0;
}