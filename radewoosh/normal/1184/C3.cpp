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
const int nax=4007;
using ld=double;
using pdd=pair<ld,ld>;

int k, n, m;
vector <pdd> znam;

pdd operator + (pdd a, pdd b)
{
	return {a.first+b.first, a.second+b.second};
}

pdd operator - (pdd a, pdd b)
{
	return {a.first-b.first, a.second-b.second};
}

pdd operator * (pdd a, ld b)
{
	return {a.first*b, a.second*b};
}

pdd operator / (pdd a, ld b)
{
	return {a.first/b, a.second/b};
}

ld dlu(pdd v)
{
	return sqrt(v.first*v.first+v.second*v.second);
}

ld odl(pdd a, pdd b)
{
	return dlu(a-b);
}

pdd sr(vector <pdd> wek)
{
	pdd ret{0, 0};
	for (pdd i : wek)
		ret=ret+i;
	return ret/wek.size();
}

int los(int a, int b)
{
	return a+rand()%(b-a+1);
}

int zawie(pair <pdd,ld> a, pdd b)
{
	ld mag=0.2;
	ld y=odl(a.first, b);
	return ((1-mag)*a.second<=y && y<=(1+mag)*a.second);
}

int main()
{
	srand(time(0));
	scanf("%d%d", &k, &n);
	m=k*n;
	for (int i=1; i<=m; i++)
	{
		ld x, y;
		scanf("%lf%lf", &x, &y);
		znam.push_back({x, y});
	}
	n*=0.9;
	
	
	for (int h=0; h<k; h++)
	{
		vector <pair<pdd,ld>> kan;
		for (int h=0; h<20000; h++)
		{
			int ile=los(2, 5);
			vector <pdd> daj;
			for (int i=0; i<ile; i++)
				daj.push_back(znam[los(0, m-1)]);
			pdd x=sr(daj);
			ld y=0;
			for (pdd j : daj)
				y+=odl(j, x);
			y/=ile;
			kan.push_back({x, y});
		}
		int kto=-1;
		ld dokl=1e18;
		for (int i=0; i<(int)kan.size(); i++)
		{
			vector <ld> dys;
			for (int j=0; j<m; j++)
				dys.push_back(abs(kan[i].second-odl(kan[i].first, znam[j])));
			sort(dys.begin(), dys.end());
			ld x=dys[n-1];
			if (x<dokl)
			{
				dokl=x;
				kto=i;
			}
		}
		printf("%lf %lf %lf\n", kan[kto].first.first, kan[kto].first.second, kan[kto].second);
		vector <pair<ld,pdd>>dys;
		for (int j=0; j<m; j++)
			dys.push_back({abs(kan[kto].second-odl(kan[kto].first, znam[j])), znam[j]});
		sort(dys.begin(), dys.end());
		znam.clear();
		for (int j=n; j<m; j++)
			znam.push_back(dys[j].second);
		m-=n;
	}
	return 0;
}