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
const int nax=200*1007;

void ff()
{
	fflush(stdout);
}

int n, m;

int pyt(int l, int r)
{
	printf("? %d %d\n", l, r);
	ff();
	int x;
	scanf("%d", &x);
	return x;
}

int trzas(int l, int r)
{
	int w;
	while(1)
	{
		w=pyt(l, r);
		if (w==n-m)
		{
			pyt(l, r);
			continue;
		}
		break;
	}
	int dlu=r-l+1;
	assert(!((m+dlu-w)&1));
	int ret=(m+dlu-w)/2;
	while(1)
	{
		w=pyt(l, r);
		if (w==m)
			break;
		pyt(l, r);
	}
	return ret;
}

int trzas2(int l, int r)
{
	set <int> setel;
	int w;
	for (int i=1; i<=25; i++)
	{
		w=pyt(l, r);
		setel.insert(w);
		pyt(l, r);
		if (w!=n-m)
			break;
	}
	pyt(l, r);
	vi wek;
	for (int i : setel)
		wek.push_back(i);
	if ((int)wek.size()==1)
	{
		w=wek[0];
	}
	else
	{
		for (int i : wek)
			if (i!=n-m)
				w=i;
	}
	
	int dlu=r-l+1;
	assert(!((m+dlu-w)&1));
	int ret=(m+dlu-w)/2;
	while(1)
	{
		w=pyt(l, r);
		if (w==m)
			break;
		pyt(l, r);
	}
	return ret;
}

int sum[nax];

int main()
{
	scanf("%d%d", &n, &m);
	if (n&1)
	{
		sum[n]=m;
		for (int i=1; i<n; i++)
		{
			if (i&1)
				sum[i]=m-trzas(i+1, n);
			else
				sum[i]=trzas(1, i);
		}
	}
	else
	{
		sum[n]=m;
		for (int i=1; i<=n; i+=2)
			sum[i]=trzas(1, i);
		for (int i=n-2; i>0; i-=2)
			sum[i]=trzas2(1, i);
	}
	
	//~ debug() << range(sum+1, sum+1+n);
	printf("! ");
	for (int i=1; i<=n; i++)
		printf("%d", sum[i]-sum[i-1]);
	ff();
	printf("\n");
	return 0;
}