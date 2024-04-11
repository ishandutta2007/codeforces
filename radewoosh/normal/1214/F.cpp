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

ll m;
int n;

unordered_map <ll,vi> ga;
unordered_map <ll,vi> gb;

int kto[nax];

ll a[nax];
ll b[nax];

ll wyn;

ll sum[nax];

void dod(int a, int b, ll w)
{
	if (a>b)
		return;
	sum[a]+=w;
	sum[b+1]-=w;
}

int main()
{
	scanf("%lld%d", &m, &n);
	for (int i=0; i<n; i++)
	{
		scanf("%lld", &a[i]);
		a[i]--;
		//~ a[i]%=m;
		ga[a[i]].push_back(i);
	}
	for (int i=0; i<n; i++)
	{
		scanf("%lld", &b[i]);
		b[i]--;
		//~ b[i]%=m;
		gb[b[i]].push_back(i);
	}
	sort(a, a+n);
	sort(b, b+n);
	wyn=0;
	for (int i=0; i<n; i++)
		wyn+=abs(a[i]-b[i]);
	ll da=0;
	ll db=0;
	debug() << range(a, a+n);
	debug() << range(b, b+n);
	for (int h=0; h<2; h++)
	{
		for (int i=0; i<=n; i++)
			sum[i]=0;
		for (int i=n; i<3*n; i++)
			b[i]=b[i-n]+m;
		int w=0;
		for (int i=0; i<n; i++)
		{
			w=max(w-1, 0);
			while(a[i]>=b[i+w+1])
				w++;
			debug() << i << " a do " << w;
			dod(1, w, a[i]);
			dod(w+1, n, -a[i]);
		}
		w=0;
		for (int i=n-1; i>=0; i--)
		{
			w=max(w-1, 0);
			while(i-w-1>=0 && b[i]<=a[i-w-1])
				w++;
			dod(1, w, -b[i]);
			dod(w+1, i, b[i]);
			dod(i+1, n, m+b[i]);
		}
		debug() << range(a, a+n);
		debug() << range(b, b+n);
		
		for (int i=1; i<=n; i++)
			sum[i]+=sum[i-1];
		debug() << range(sum+1, sum+1+n);
		for (int i=1; i<=n; i++)
		{
			if (sum[i]<wyn)
			{
				wyn=sum[i];
				da=0;
				db=0;
				if (!h)
					db=i;
				else
					da=i;
			}
		}
		for (int i=0; i<n; i++)
			swap(a[i], b[i]);
	}
	
	printf("%lld\n", wyn);
	for (int i=1; i<=da; i++)
		a[i-1]+=m;
	for (int i=1; i<=db; i++)
		b[i-1]+=m;
	sort(a, a+n);
	sort(b, b+n);
	for (int i=0; i<n; i++)
	{
		int x=ga[a[i]%m].back();
		ga[a[i]%m].pop_back();
		
		int y=gb[b[i]%m].back();
		gb[b[i]%m].pop_back();
		
		kto[x]=y+1;
	}
	
	for (int i=0; i<n; i++)
		printf("%d ", kto[i]);
	printf("\n");
	return 0;
}