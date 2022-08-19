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
const int inf=1e9;

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

int n, m;

ll taba[nax];
ll tabb[nax];

int cut[nax];
vi graf[nax];

queue<int> kol;
set<int> roz;

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<=n; i++)
	{
		graf[i].clear();
		cut[i]=0;
	}
	cut[0]=1;
	cut[n+1]=0;
	for (int i=1; i<=n; i++)
		scanf("%lld", &taba[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tabb[i]);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a-1].push_back(b);
		graf[b].push_back(a-1);
	}
	{
		ll s=0;
		for (int i=1; i<=n; i++)
		{
			s+=taba[i]-tabb[i];
			if (!s)
				cut[i]=1;
		}
	}
	if (!cut[n])
	{
		ans(0);
		return;
	}
	roz.clear();
	for (int i=0; i<=n+1; i++)
		if (!cut[i])
			roz.insert(i);
	for (int i=0; i<=n; i++)
		if (cut[i])
			kol.push(i);
	while(!kol.empty())
	{
		int v=kol.front();
		kol.pop();
		for (int i : graf[v])
		{
			int a=min(v, i);
			int b=max(v, i);
			if (!cut[a] || !cut[b])
				continue;
			while(1)
			{
				int x=*roz.lower_bound(a);
				if (x>b)
					break;
				roz.erase(x);
				cut[x]=1;
				kol.push(x);
			}
		}
	}
	ans(roz.size()==1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}