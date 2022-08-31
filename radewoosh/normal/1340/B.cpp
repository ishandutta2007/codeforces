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
const int nax=2007;

string kod[]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int mas[10];

int n, k;

int ile[nax][10];

char wcz[nax];

int dp[nax][nax];

int main()
{
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<7; j++)
			mas[i]=(mas[i]<<1)|(kod[i][j]-'0');
	}
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz);
		int w=0;
		for (int j=0; j<7; j++)
			w=(w<<1)|(wcz[j]-'0');
		for (int j=0; j<10; j++)
		{
			if ((mas[j]&w)!=w)
			{
				ile[i][j]=nax;
			}
			else
			{
				ile[i][j]=__builtin_popcount(mas[j]^w);
			}
		}
	}
	dp[n+1][0]=1;
	for (int i=n; i; i--)
	{
		for (int j=0; j<=k; j++)
		{
			for (int l=0; l<10; l++)
			{
				if (ile[i][l]<=j && dp[i+1][j-ile[i][l]])
					dp[i][j]=1;
				
			}
		}
	}
	if (!dp[1][k])
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=9; j>=0; j--)
		{
			if (k-ile[i][j]>=0 && dp[i+1][k-ile[i][j]])
			{
				k-=ile[i][j];
				printf("%d", j);
				break;
			}
		}
	}
	printf("\n");
	return 0;
}