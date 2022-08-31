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
const int kax=21;

int n, m, k;

char mam[kax];
char chce[kax];

int maslew[nax];
int maspra[nax];

int per[nax];//gdzie znajdzie sie i-te ciastko

void zapisz(int v)
{
	int a=0;
	int b=0;
	for (int i=0; i<k; i++)
	{
		int x=(mam[i]-'0');
		a|=(x<<per[i]);
	}
	for (int i=0; i<k; i++)
	{
		int x=(chce[i]-'0');
		b|=(x<<per[i]);
	}
	maslew[v]=a;
	maspra[v]=b;
}

int pier[1<<kax];
int pom[1<<kax];

void relax()
{
	for (int i=0; i<(1<<k); i++)
		pom[i]=pier[i];
	for (int i=0; i<(1<<k); i++)
		for (int j=0; j<k; j++)
			pier[i]=min(pier[i], pom[i^(1<<j)]);
}

int wa, wb;

int jest()
{
	for (int i=0; i<=n; i++)
	{
		if (pier[maspra[i]]<=i-m)
		{
			wb=i;
			wa=pier[maspra[i]];
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", mam);
	scanf("%s", chce);
	for (int i=0; i<k; i++)
		per[i]=i;
	zapisz(0);
	for (int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		swap(per[a], per[b]);
		zapisz(i);
	}
	//~ for (int i=0; i<=n; i++)
		//~ debug() << i << " " << maslew[i] << " " << maspra[i];
	for (int i=0; i<(1<<k); i++)
		pier[i]=nax;
	for (int i=n; i>=0; i--)
		pier[maslew[i]]=i;
	int wyn=0;
	while(!jest())
		relax(), wyn++;
	printf("%d\n", k-wyn);
	printf("%d %d\n", wa+1, wb);
	return 0;
}