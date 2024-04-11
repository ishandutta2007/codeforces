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

int n, k;

char s[nax];
char a[nax];
char b[nax];

int zaj[nax];
int ust[nax];
char naco[nax];

int rek(int v, int rel)
{
	if (v==n+1)
		return 1;
	if (ust[s[v]])
	{
		if (naco[s[v]]<a[v] && !rel)
			return 0;
		return rek(v+1, rel|(naco[s[v]]>a[v]));
	}
	for (char i='a'; i<'a'+k; i++)
	{
		if (zaj[i])
			continue;
		if (!rel && i<a[v])
			continue;
		zaj[i]=1;
		ust[s[v]]=1;
		naco[s[v]]=i;
		if (rek(v+1, rel|(i>a[v])))
			return 1;
		zaj[i]=0;
		ust[s[v]]=0;
	}
	return 0;
}

void test()
{
	scanf("%d", &k);
	scanf("%s", s+1);
	scanf("%s", a+1);
	scanf("%s", b+1);
	n=strlen(s+1);
	for (int i=0; i<k; i++)
		zaj['a'+i]=ust['a'+i]=0;
	if (!rek(1, 0))
	{
		printf("NO\n");
		return;
	}
	for (char i='a'; i<'a'+k; i++)
	{
		if (!ust[i])
		{
			for (int j='a'; j<'a'+k; j++)
			{
				if (!zaj[j])
				{
					ust[i]=1;
					zaj[j]=1;
					naco[i]=j;
					break;
				}
			}
		}
	}
	//~ debug() << range(naco+'a', naco+'a'+k);
	int rel=0;
	for (int i=1; i<=n; i++)
	{
		if (naco[s[i]]==b[i])
			continue;
		if (naco[s[i]]>b[i])
			rel=1;
		break;
	}
	if (rel)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for (int i=0; i<k; i++)
			printf("%c", naco[i+'a']);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}