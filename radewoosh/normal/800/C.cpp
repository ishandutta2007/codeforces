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

int n, m;

int zak[nax];

vector <int> dziel;
int dp[nax];
int z[nax];
vector <int> doz[nax];

int naj=-1;

int v;

int aktu=1;

void eukl(long long &x, long long &y, long long a, long long b) {
  if (!a) { x = 0; y = 1; return;}
  eukl(y,x,b%a,a);
  x -= y*(b/a);
}

void zamien(long long a, long long b)
{
	a%=m;
	b%=m;
	if (!b)
	{
		printf("0 ");
		return;
	}
	long long mno=1;
	long long g1=__gcd(a, (long long)m);
	long long g2=__gcd(b, (long long)m);
	if (g1!=g2)
	{
		mno*=(g2/g1);
		mno%=m;
		a*=(g2/g1);
		a%=m;
	}
	long long mx=0;
	long long my=0;
	eukl(mx, my, a, m);
	mno*=mx;
	mno%=m;
	mno*=(b/g2);
	mno%=m;
	mno+=m;
	mno%=m;
	
	printf("%lld ", mno);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		zak[x]=1;
	}
	for (int i=1; i<=m; i++)
		if (!(m%i))
			dziel.push_back(i);
	for (int i=0; i<m; i++)
		if (!zak[i])
			doz[__gcd(i, m)].push_back(i);
	for (int i=(int)dziel.size()-1; i>=0; i--)
	{
		int x=dziel[i];
		z[x]=-1;
		for (int j=i+1; j<(int)dziel.size(); j++)
		{
			if (dziel[j]%x)
				continue;
			if (dp[dziel[j]]>dp[x])
			{
				z[x]=dziel[j];
				dp[x]=dp[dziel[j]];
			}
		}
		dp[x]+=doz[x].size();
	}
	for (int i=0; i<dziel.size(); i++)
		naj=max(naj, dp[dziel[i]]);
	for (int i=0; i<dziel.size(); i++)
		if (dp[dziel[i]]==naj)
			v=dziel[i];
	printf("%d\n", dp[v]);
	while(v!=-1)
	{
		for (int i=0; i<doz[v].size(); i++)
		{
			zamien(aktu, doz[v][i]);
			aktu=doz[v][i];
		}
		v=z[v];
	}
	printf("\n");
	return 0;
}