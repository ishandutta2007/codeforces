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

int n;

vll sta, cel;

vll wek;

vector<char> wyn;

void nope()
{
	printf("IMPOSSIBLE\n");
	exit(0);
}

void wrzu(char c)
{
	if (!wyn.empty() && wyn.back()=='R' && c=='R')
	{
		wyn.pop_back();
		return;
	}
	wyn.push_back(c);
}

void check()
{
	for (int i=0; i<n; i++)
		if (cel[i]<sta[i] && cel[i]<sta[n-1-i])
			nope();
	int czy2=1;
	for (int i=0; i<n; i++)
		if (cel[i]!=sta[n-1-i])
			czy2=0;
	if (czy2)
	{
		wek.push_back(0);
		reverse(cel.begin(), cel.end());
	}
	int czy=1;
	for (int i=0; i<n; i++)
		if (cel[i]!=sta[i])
			czy=0;
	if (!czy)
		return;
	ll licz=0;
	reverse(wek.begin(), wek.end());
	debug() << wek;
	for (ll i : wek)
		licz+=i;
	if (licz>200*1000)
	{
		printf("BIG\n%lld\n", licz);
		exit(0);
	}
	for (ll i : wek)
	{
		if (!i)
			wrzu('R');
		else
			for (ll j=0; j<i; j++)
				wrzu('P');
	}
	printf("SMALL\n");
	printf("%d\n", (int)wyn.size());
	for (char i : wyn)
		printf("%c", i);
	printf("\n");
	exit(0);
}

int main()
{
	scanf("%d", &n);
	sta.resize(n);
	cel.resize(n);
	for (int i=0; i<n; i++)
		scanf("%lld", &sta[i]);
	for (int i=0; i<n; i++)
		scanf("%lld", &cel[i]);
	vector<char> wyn;
	if (n==1)
	{
		check();
		nope();
	}
	while(1)
	{
		debug() <<imie(wek) << cel;
		check();
		if (cel[n-1]<cel[0])
		{
			wek.push_back(0);
			reverse(cel.begin(), cel.end());
			continue;
		}
		if (n>2 || cel[1]<10)
		{
			for (int i=n-1; i; i--)
				cel[i]-=cel[i-1];
			wek.push_back(1);
		}
		else
		{
			ll ile=(cel[1]-max(sta[1], sta[0]))/cel[0];
			ile=max(ile, 1LL);
			wek.push_back(ile);
			cel[1]-=ile*cel[0];
		}
	}
	return 0;
}