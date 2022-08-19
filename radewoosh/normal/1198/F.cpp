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
 
int n;
int tab[nax];
 
int naj[nax];
int g[19][nax];
 
int sito[nax];
vi pie;
 
void nope()
{
	printf("NO\n");
	exit(0);
}
 
void mam(vi wek)
{
	printf("YES\n");
	vi wyp(n, 1);
	for (int i : wek)
		wyp[i-1]++;
	for (int i : wyp)
		printf("%d ", i);
	printf("\n");
	exit(0);
}
 
int daj(int a, int b)
{
	int d=naj[b-a+1];
	return __gcd(g[d][a], g[d][b-(1<<d)+1]);
}
 
int czycos(int a, int b, int w)
{
	if (!w)
		return 1;
	int d=naj[b-a+1];
	return (g[d][a]%w)>0 || (g[d][b-(1<<d)+1]%w)>0;
}
 
vi stos;
 
void czysc(int &v)
{
	for (int i : pie)
	{
		if (i>2000)
			break;
		int w=i*i;
		while(!(v%w))
			v/=i;
	}
}
 
int znajdz(int v, int c)
{
	int bsa=v;
	int bsb=n+1;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb)>>1;
		if (czycos(v, bss, c))
			bsb=bss;
		else
			bsa=bss+1;
	}
	return bsa;
}
 
void rek(int v, int a, int b)
{
	if (a==1 && b==1)
		mam(stos);
	if (v>n)
		return;
	if (!czycos(v, n, a) && !czycos(v, n, b))
		return;
	int x=znajdz(v, a);
	int y=znajdz(v, b);
	if (x==y)
	{
		stos.push_back(x);
		rek(x+1, __gcd(a, tab[x]), b);
		stos.pop_back();
		rek(x+1, a, __gcd(b, tab[x]));
	}
	else
	{
		if (x<y)
		{
			stos.push_back(x);
			rek(x+1, __gcd(a, tab[x]), b);
			stos.pop_back();
		}
		else
		{
			rek(y+1, a, __gcd(b, tab[y]));
		}
	}
}
 
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=2; i<nax; i++)
	{
		if (!sito[i])
		{
			pie.push_back(i);
			for (int j=i; j<nax; j+=i)
				sito[j]=1;
		}
	}
	for (int i=1; i<=n; i++)
		czysc(tab[i]);
	for (int i=1; i<=n; i++)
	{
		naj[i]=naj[i-1];
		if ((1<<(naj[i]+1))<=i)
			naj[i]++;
		g[0][i]=tab[i];
	}
	for (int h=1; h<=naj[n]; h++)
		for (int i=1; i+(1<<h)-1<=n; i++)
			g[h][i]=__gcd(g[h-1][i], g[h-1][i+(1<<(h-1))]);
	rek(1, 0, 0);
	nope();
	return 0;
}