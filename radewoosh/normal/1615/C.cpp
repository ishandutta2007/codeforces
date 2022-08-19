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

char wcz[nax];
int sta[nax];
int kon[nax];

int wyn;

int on[nax];

void solve(int v)
{
	int s=0;
	for (int i=1; i<=n; i++)
	{
		on[i]=0;
		if ((sta[i]^kon[i])==v)
		{
			on[i]=1;
			s++;
		}
	}
	for (int i=1; i<=n; i++)
	{
		int x=(sta[i]+s+on[i])&1;
		if (x!=kon[i])
			return;
	}
	int li[]={0, 0};
	for (int i=1; i<=n; i++)
			if (on[i])
				li[sta[i]]++;
	if (li[1]>=li[0] && li[1]<=li[0]+1)
		wyn=min(wyn, s);
}

void test()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		sta[i]=wcz[i]-'0';
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		kon[i]=wcz[i]-'0';
	//~ {
		//~ int sa=0;
		//~ int sb=0;
		//~ for (int i=1; i<=n; i++)
		//~ {
			//~ sa+=sta[i];
			//~ sb+=kon[i];
		//~ }
		//~ if (sa==0 && sb==0)
		//~ {
			//~ printf("0\n");
			//~ return;
		//~ }
		//~ if (sa==0 || sb==0)
		//~ {
			//~ printf("-1\n");
			//~ return;
		//~ }
	//~ }
	wyn=nax;
	solve(0);
	solve(1);
	
	if (wyn==nax)
		wyn=-1;
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}