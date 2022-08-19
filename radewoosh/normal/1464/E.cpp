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
const int d=512;
const ll mod=998244353;

int n, m;

vi graf[nax];
int juz[nax];
int nim[nax];

int ile[d];

ll mac[d+7][d+7];

void policz(int v)
{
	if (juz[v])
		return;
	juz[v]=1;
	unordered_set<int> setel;
	for (int i : graf[v])
	{
		policz(i);
		setel.insert(nim[i]);
	}
	while(setel.count(nim[v]))
		nim[v]++;
}

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

void dod(int a, int b, ll w)
{
	for (int i=0; i<=d; i++)
		mac[a][i]=(mac[a][i]+mac[b][i]*w)%mod;
}

void zam(int a, int b)
{
	for (int i=0; i<=d; i++)
		swap(mac[a][i], mac[b][i]);
}

void mno(int a, ll w)
{
	for (int i=0; i<=d; i++)
		mac[a][i]=(mac[a][i]*w)%mod;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
	}
	for (int i=1; i<=n; i++)
	{
		policz(i);
		ile[nim[i]]++;
		debug() << i << " " << nim[i];
	}
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<d; j++)
			mac[i][i^j]=(-ile[j]*inv(n+1)%mod+mod)%mod;
		mac[i][i]=(mac[i][i]+1+mod)%mod;
	}
	mac[0][d]=inv(n+1);
	for (int i=0; i<d; i++)
	{
		for (int j=i; j<d; j++)
		{
			if (mac[j][i])
			{
				zam(j, i);
				break;
			}
		}
		assert(mac[i][i]);
		mno(i, inv(mac[i][i]));
		for (int j=0; j<d; j++)
			if (j!=i)
				dod(j, i, mod-mac[j][i]);
	}
	
	printf("%lld\n", (mod+1-mac[0][d])%mod);
	return 0;
}