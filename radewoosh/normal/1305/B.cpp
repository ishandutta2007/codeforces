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

int nie[nax];

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	int czy1=0;
	int czy2=0;
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='(')
		{
			czy1=1;
		}
		else
		{
			if (czy1)
				czy2=1;
		}
	}
	if (!czy2)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1; i<=n; i++)
	{
		vi dous;
		for (int j=1; j<=n; j++)
			nie[j]=0;
		int a=0;
		int b=0;
		for (int j=1; j<=i; j++)
			if (wcz[j]=='(')
				a++;
		for (int j=i+1; j<=n; j++)
			if (wcz[j]==')')
				b++;
		a=min(a, b);
		b=a;
		for (int j=1; j<=i; j++)
			if (wcz[j]=='(' && a)
			{
				a--;
				nie[j]=1;
				dous.push_back(j);
			}
		for (int j=n; j>i; j--)
			if (wcz[j]==')' && b)
			{
				b--;
				nie[j]=1;
				dous.push_back(j);
			}
		debug() << range(nie+1, nie+1+n);
		czy1=0;
		czy2=0;
		for (int i=1; i<=n; i++)
		{
			if (nie[i])
				continue;
			if (wcz[i]=='(')
			{
				czy1=1;
			}
			else
			{
				if (czy1)
					czy2=1;
			}
		}
		if (!czy2)
		{
			sort(dous.begin(), dous.end());
			printf("%d\n%d\n", 1, (int)dous.size());
			for (int j : dous)
				printf("%d ", j);
			printf("\n");
			exit(0);
		}
	}
	assert(0);
	return 0;
}