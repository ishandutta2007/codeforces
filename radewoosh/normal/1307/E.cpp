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
const int nax=5007;
const ll mod=1000*1000*1000+7;

int n, m;

int tab[nax];

vi jakie[nax];
int ilemn[nax][nax];

int lew[nax];
int pra[nax];

ll raz;
ll dwa;

int popra[nax];
int polew[nax];

void cons(ll a, ll b)
{
	if (a>raz)
	{
		raz=a;
		dwa=0;
	}
	if (a==raz)
	{
		dwa=(dwa+b)%mod;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		jakie[a].push_back(b);
	}
	for (int i=1; i<=n; i++)
	{
		sort(jakie[i].begin(), jakie[i].end());
		for (int j : jakie[i])
			ilemn[i][j]++;
		for (int j=1; j<=n; j++)
			ilemn[i][j]+=ilemn[i][j-1];
		popra[tab[i]]++;
		//~ debug() << i << " " << range(ilemn[i]+1, ilemn[i]+1+n);
	}
	{
		ll a=0;
		ll b=1;
		for (int i=1; i<=n; i++)
		{
			int x=popra[i];
			if (ilemn[i][x])
			{
				a++;
				b=(b*ilemn[i][x])%mod;
			}
		}
		cons(a, b);
	}
	for (int i=1; i<=n; i++)
	{
		polew[tab[i]]++;
		popra[tab[i]]--;
		ll a=0;
		ll b=1;
		int nie=0;
		for (int j=1; j<=n; j++)
		{
			int l=polew[j];
			int p=popra[j];
			if (j==tab[i])
			{
				if (ilemn[j][l]==ilemn[j][l-1])
				{
					nie=1;
					break;
				}
				if (l<=p)
				{
					if (ilemn[j][p]>=2)
					{
						a++;
						a++;
						b=(b*(ilemn[j][p]-1))%mod;
						continue;
					}
					else
					{
						a++;
						continue;
					}
				}
				else
				{
					if (ilemn[j][p])
					{
						a++;
						a++;
						b=(b*ilemn[j][p])%mod;
						continue;
					}
					else
					{
						a++;
						continue;
					}
				}
			}
			else
			{
				if (l>p)
					swap(l, p);
				if (ilemn[j][l] && ilemn[j][p]>=2)
				{
					a++;
					b=(b*ilemn[j][l])%mod;
					a++;
					b=(b*(ilemn[j][p]-1))%mod;
					continue;
				}
				if (ilemn[j][l])
				{
					a++;
					b=(b*(ilemn[j][l]+ilemn[j][p]))%mod;
					continue;
				}
				if (ilemn[j][p])
				{
					a++;
					b=(b*ilemn[j][p])%mod;
					continue;
				}
			}
		}
		if (!nie)
		{
			debug() << i << " " << a << " " << b;
			cons(a, b);
		}
	}
	
	printf("%lld %lld\n", raz, dwa);
	return 0;
}