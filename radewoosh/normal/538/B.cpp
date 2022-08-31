//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=1000*1007;

int czyok[nax];

vector <int> te;

int n;
int dp[nax];
int z[nax];

vector <int> wek;

int main()
{
	czyok[0]=1;
	for (int i=1; i<=1000*1000; i++)
	{
		czyok[i]=(czyok[i/10] && (i%10)<=1);
		if (czyok[i])
			te.push_back(i);
	}
	for (int i=1; i<nax; i++)
		dp[i]=nax;
	for (int i=1; i<nax; i++)
	{
		for (int j : te)
		{
			if (j>i)
				break;
			if (dp[i-j]+1<dp[i])
			{
				dp[i]=dp[i-j]+1;
				z[i]=j;
			}
		}
	}
	scanf("%d", &n);
	printf("%d\n", dp[n]);
	while(n)
	{
		wek.push_back(z[n]);
		n-=z[n];
	}
	for (int i : wek)
		printf("%d ", i);
	printf("\n");
	return 0;
}