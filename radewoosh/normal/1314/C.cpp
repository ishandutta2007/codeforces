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
const int nax=1007;

int n, m;
ll k;

char wcz[nax];

vector <pii> sor;

int pref[nax][nax];

bool mniej(pii a, pii b)
{
	int da=a.second-a.first+1;
	int db=b.second-b.first+1;
	int wsp=pref[a.first][b.first];
	//~ debug() << imie(da) << imie(db) << imie(wsp);
	if (wsp>=da || wsp>=db)
		return da<db;
	return wcz[a.first+wsp]<wcz[b.first+wsp];
}

ll dp[nax][nax];
ll cio[nax];

void dod(ll &a, ll b)
{
	a=min(a+b, k);
}

ll licz(pii p)
{
	for (int h=0; h<=m; h++)
		for (int i=0; i<=n; i++)
			dp[h][i]=0;
	dp[0][0]=1;
	int dlu=p.second-p.first+1;
	for (int h=0; h<m; h++)
	{
		for (int i=0; i<=n; i++)
			cio[i]=0;
		ll s=0;
		for (int i=1; i<=n; i++)
		{
			int wsp=pref[p.first][i];
			if (wsp>=dlu)
			{
				dod(cio[i+dlu-1], dp[h][i-1]);
			}
			else
			{
				if (wcz[p.first+wsp]<wcz[i+wsp])
				{
					dod(cio[i+wsp], dp[h][i-1]);
				}
			}
			dod(s, cio[i]);
			dp[h+1][i]=s;
		}
	}
	return dp[m][n];
}

int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	scanf("%s", wcz+1);
	for (int i=n; i; i--)
		for (int j=n; j; j--)
			if (wcz[i]==wcz[j])
				pref[i][j]=pref[i+1][j+1]+1;
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			sor.push_back({i, j});
	sort(sor.begin(), sor.end(), mniej);
	//~ debug() << sor;
	//~ debug() << imie(mniej({1, 1}, {1, 2}));
	//~ debug() << imie(mniej({1, 2}, {1, 1}));
	//~ return 0;
	int bsa=0;
	int bsb=(int)sor.size()-1;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (licz(sor[bss])>=k)
			bsa=bss;
		else
			bsb=bss-1;
	}
	pii p=sor[bsa];
	for (int i=p.first; i<=p.second; i++)
		printf("%c", wcz[i]);
	printf("\n");
	return 0;
}