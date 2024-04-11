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

int n;
int per[nax];

int bylo[nax];
int k;
vi cyk[nax];

bool mniej(vi &a, vi &b)
{
	return (int)a.size()<(int)b.size();
}

vector<pii> wyn;

void zrob(int a, int b)
{
	wyn.push_back({a, b});
	swap(per[a], per[b]);
	per[a]*=-1;
	per[b]*=-1;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &per[i]);
	}
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		vi wek;
		int v=i;
		while(!bylo[v])
		{
			bylo[v]=1;
			wek.push_back(v);
			v=per[v];
		}
		k++;
		cyk[k]=wek;
	}
	//~ for (int i=1; i<=k; i++)
		//~ debug() << i << " " << cyk[i];
	sort(cyk+1, cyk+1+k, mniej);
	//~ for (int i=1; i<=k; i++)
		//~ debug() << i << " " << cyk[i];
	while(k>=2)
	{
		vi a=cyk[k-1];
		vi b=cyk[k];
		k-=2;
		if (a.size()==1 && b.size()==1)
			continue;
		int ra=a.size();
		int rb=b.size();
		zrob(a[0], b[0]);
		for (int i=1; i<ra; i++)
			zrob(a[i], b[0]);
		for (int i=1; i<rb; i++)
			zrob(a[0], b[i]);
		zrob(a[0], b[0]);
	}
	if (k==1)
	{
		vi wek=cyk[k];
		int sta=0;
		for (int i=1; i<=n; i++)
			if (per[i]==i)
				sta=i;
		if (sta)
		{
			for (int i : wek)
				zrob(i, sta);
			zrob(wek[0], sta);
		}
		else
		{
			int r=wek.size();
			zrob(wek[0], wek[1]);
			zrob(wek[1], wek[2]);
			zrob(wek[0], wek[2]);
			for (int i=3; i<r; i++)
				zrob(wek[1], wek[i]);
			zrob(wek[0], wek[1]);
		}
	}
	
	
	
	for (int i=1; i<=n; i++)
		assert(i==per[i]);
	printf("%d\n", (int)wyn.size());
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	return 0;
}