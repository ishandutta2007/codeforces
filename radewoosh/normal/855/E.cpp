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
const int nax=100*1007;

//baza,dlugosc,niep
ll dp[12][100][12];

ll licz(int b, ll v)
{
	v++;
	vll wek;
	while(v)
	{
		wek.push_back(v%b);
		v/=b;
	}
	reverse(wek.begin(), wek.end());
	int start=1;
	int k=wek.size();
	int mas=0;
	ll ret=0;
	//~ debug() << wek;
	for (int i=0; i<k; i++)
	{
		//~ debug() << wek[i] << " " << mas;
		for (int j=start; j<wek[i]; j++)
		{
			int x=mas^(1<<j);
			ret+=dp[b][k-i-1][__builtin_popcount(x)];
			//~ debug() << i << " " << j << "  " << ret;
		}
		mas^=(1<<wek[i]);
		start=0;
	}
	for (int i=1; i<k; i++)
		ret+=dp[b][k-i-1][1]*(b-1);
	//~ debug() << imie(ret);
	return ret;
}

int main()
{
	for (int i=2; i<=10; i++)
	{
		dp[i][0][0]=1;
		for (int j=1; j<=70; j++)
		{
			for (int l=0; l<=i; l++)
			{
				if (l)
					dp[i][j][l]+=dp[i][j-1][l-1]*l;
				if (l<i)
					dp[i][j][l]+=dp[i][j-1][l+1]*(i-l);
			}
		}
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int b;
		ll l, r;
		scanf("%d%lld%lld", &b, &l, &r);
		printf("%lld\n", licz(b, r)-licz(b, l-1));
	}
	return 0;
}