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

void pier()
{
	printf("tokitsukaze\n");
	exit(0);
}

void dru()
{
	printf("quailty\n");
	exit(0);
}

void draw()
{
	printf("once again\n");
	exit(0);
}

int n, k;
char wcz[nax];
int tab[nax];

vi wek[2];
set <int> setel[2];

int nal(int co, int v)
{
	if (wek[co][0]>=v)
		return 0;
	int a=wek[co][0];
	auto it=setel[co].lower_bound(v);
	it--;
	int b=(*it);
	if (b-a+1<=k)
		return 1;
	return 2;
}

int nap(int co, int v)
{
	if (wek[co].back()<=v)
		return 0;
	auto it=setel[co].lower_bound(v+1);
	int a=(*it);
	int b=wek[co].back();
	if (b-a+1<=k)
		return 1;
	return 2;
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'0';
	for (int i=1; i<=n; i++)
	{
		setel[tab[i]].insert(i);
		wek[tab[i]].push_back(i);
	}
	for (int i=0; i<2; i++)
		if (wek[i].empty() || wek[i].back()-wek[i][0]+1<=k)
			pier();
	int umie=0;
	for (int i=1; i+k-1<=n; i++)
	{
		int a=i;
		int b=i+k-1;
		for (int j=0; j<2; j++)
		{
			if (nal(j, a)+nap(j, b)<=1)
			{
			}
			else
			{
				//~ debug() << i << " " << j << " " << nal(j, a) << " " << nap(j, b);
				umie=1;
			}
		}
	}
	
	if (!umie)
		dru();
	else
		draw();
	return 0;
}