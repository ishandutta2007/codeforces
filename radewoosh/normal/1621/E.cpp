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
const ll inf=1e18;

void ff()
{
	fflush(stdout);
}

int n, m;

ll ticz[nax];

vll wek[nax];
ll sum[nax];

int miej[nax];

int znajdz(ll li, ll mi)
{
	int bsa=0;
	int bsb=n;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (ticz[bss]*mi>=li)
			bsa=bss;
		else
			bsb=bss-1;
	}
	return bsa;
}

set<int> uje, zer;

int nic(int a, int b, set<int> &setel)
{
	return setel.lower_bound(a)==setel.lower_bound(b+1);
}

int wszystko(int a, int b, set<int> &setel)
{
	if (setel.empty())
		return 1;
	if ((*setel.begin())<a)
		return 0;
	auto it=setel.end();
	it--;
	if ((*it)>b)
		return 0;
	return 1;
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &ticz[i]);
	sort(ticz+1, ticz+1+n);
	reverse(ticz+1, ticz+1+n);
	n=m;
	for (int i=0; i<=n; i++)
		miej[i]=0;
	for (int i=1; i<=n; i++)
	{
		int r, x;
		scanf("%d", &r);
		wek[i].clear();
		sum[i]=0;
		while(r--)
		{
			scanf("%d", &x);
			wek[i].push_back(x);
			sum[i]+=x;
		}
		miej[znajdz(sum[i], wek[i].size())]--;
	}
	for (int i=1; i<=n; i++)
		miej[i]+=miej[i-1];
	for (int i=1; i<=n; i++)
		miej[i]+=i;
	uje.clear();
	zer.clear();
	int dwa=0;
	for (int i=0; i<=n; i++)
	{
		if (miej[i]<-1)
			dwa=1;
		if (miej[i]==-1)
			uje.insert(i);
		if (miej[i]==0)
			zer.insert(i);
	}
	if (dwa)
	{
		for (int i=1; i<=n; i++)
			for (ll j : wek[i])
				printf("0");
		printf("\n");
		return;
	}
	if (uje.empty() && zer.empty())
	{
		for (int i=1; i<=n; i++)
			for (ll j : wek[i])
				printf("1");
		printf("\n");
		return;
	}
	for (int i=1; i<=n; i++)
	{
		int sta=znajdz(sum[i], wek[i].size());
		for (ll j : wek[i])
		{
			int now=znajdz(sum[i]-j, (int)wek[i].size()-1);
			int tso=0;
			if (now<=sta)
			{
				if (uje.empty() && nic(now, sta-1, zer))
					tso=1;
			}
			else
			{
				if (wszystko(sta, now-1, uje))
					tso=1;
			}
			
			printf("%d", tso);
		}
	}
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