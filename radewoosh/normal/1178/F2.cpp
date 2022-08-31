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
const int nax=1007;
const ll mod=998244353;

int n, m;
int tab[nax*nax];

ll dp[nax][nax];

int lew[nax];
int pra[nax];

ll pyt(int a, int b)
{
	if (a>b)
		return 1;
	return dp[a][b];
}

int czy[nax];
ll ile[nax];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%d", &tab[i]);
	vi wek;
	for (int i=1; i<=m; i++)
		if (wek.empty() || wek.back()!=tab[i])
			wek.push_back(tab[i]);
	m=wek.size();
	for (int i=0; i<m; i++)
		tab[i+1]=wek[i];
	for (int i=1; i<=n; i++)
		lew[i]=m+1;
	for (int i=1; i<=m; i++)
	{
		lew[tab[i]]=min(lew[tab[i]], i);
		pra[tab[i]]=max(pra[tab[i]], i);
	}
	for (int i=n; i; i--)
	{
		for (int j=lew[i]; j<=pra[i]; j++)
		{
			if (tab[j]<i)
			{
				printf("0\n");
				return 0;
			}
		}
	}
	//~ debug() << range(tab+1, tab+1+m);
	
	for (int j=1; j<=m; j++)
	{
		for (int i=j; i; i--)
		{
			int v=i;
			for (int l=i; l<=j; l++)
				if (tab[l]<tab[v])
					v=l;
			v=tab[v];
			if (lew[v]<i || pra[v]>j)
				continue;
			//~ debug() << i << " " << j;
			if (!czy[v])
			{
				ile[v]=1;
				int ost=lew[v]-1;
				for (int l=lew[v]; l<=pra[v]; l++)
				{
					if (tab[l]==v)
					{
						ile[v]=(ile[v]*pyt(ost+1, l-1))%mod;
						ost=l;
					}
				}
				czy[v]=1;
			}
			
			ll a=0;
			ll b=0;
			for (int l=i; l<=lew[v]; l++)
				a=(a+pyt(i, l-1)*pyt(l, lew[v]-1))%mod;
			for (int l=pra[v]; l<=j; l++)
				b=(b+pyt(pra[v]+1, l)*pyt(l+1, j))%mod;
			dp[i][j]=(a*b%mod*ile[v])%mod;
			//~ debug() << a << " " << b << " " << ile[v];
		}
	}
	printf("%lld\n", dp[1][m]);
	return 0;
}