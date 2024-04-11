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
const int nax=2000*1007;

int r[nax];

// @s[0..n-1]  - napis dugoci @n.
// @r[0..2n-2] - tablica promieni palindromw.
// s: a   b   a   a   b   a   a   c   a   a   b   b   b   b   a   a   c   a   c
// r: 0 0 1 0 0 3 0 0 2 0 0 1 0 0 3 0 0 1 0 0 0 1 1 6 1 1 0 0 0 1 0 0 1 0 1 0 0
void Manacher(const char* s, int n) {
  for (int i = 0, m = 0, k = 0, p = 0; i < 2 * n - 1; m = i++ - 1) {
    while (p < k and i / 2 + r[m] != k)
      r[i++] = min(r[m--], (k + 1 - p++) / 2);
    while (k + 1 < n and p > 0 and s[k + 1] == s[p - 1])
      k++, p--;
    r[i] = (k + 1 - p++) / 2;
  }
}
bool is_pal(int p, int k) { //Przedzia [p, k] obustronnie domknity
	return r[p + k] >= (k - p + 1) / 2;
}

int n;
char wcz[nax];

void test()
{
	scanf("%s", wcz);
	n=strlen(wcz);
	int ile=0;
	while((ile+1)*2<=n && wcz[ile]==wcz[n-1-ile])
		ile++;
	for (int i=0; i<=2*n+3; i++)
		r[i]=0;
	Manacher(wcz, n);
	debug() << range(r, r+2*n-1);
	int wyn=0;
	int g=-1;
	int parz=0;
	//~ for (int i=0; i<=2*n-2; i++)
	//~ {
		//~ if (i<=2*n-2-i)
		//~ {
			//~ if (i&1)
			//~ {
				
			//~ }
			//~ else
			//~ {
				//~ if (ile*2+r[i]*2>=i)
				//~ {
					//~ if ()
				//~ }
			//~ }
		//~ }
		//~ if (i>=2*n-2-i)
		//~ {
			
		//~ }
	//~ }
	for (int i=1; i<=n; i++)
	{
		int pr=r[2*(i-1)];
		if (ile+pr>=min(i-1, n-i))
		{
			debug() << imie(i) << imie(pr);
			int mog=pr*2+1+2*(min(i-1, n-i)-pr);
			if (mog>wyn)
			{
				wyn=mog;
				g=i;
				parz=1;
			}
		}
	}
	for (int i=1; i<n; i++)
	{
		int pr=r[2*(i-1)+1];
		if (ile+pr>=min(i, n-i))
		{
			debug() << imie(i) << imie(pr);
			int mog=pr*2+2*(min(i, n-i)-pr);
			if (mog>wyn)
			{
				wyn=mog;
				g=i;
				parz=0;
			}
		}
	}
	assert(g!=-1);
	debug() << imie(g) << imie(parz);
	if (parz)
	{
		int pr=r[2*(g-1)];
		int resz=min(g-1, n-g)-pr;
		debug() << imie(resz) << imie(pr);
		for (int i=1; i<=resz; i++)
			printf("%c", wcz[i-1]);
		for (int i=-pr; i<=pr; i++)
			printf("%c", wcz[g-1+i]);
		for (int i=resz; i; i--)
			printf("%c", wcz[i-1]);
		printf("\n");
	}
	else
	{
		int pr=r[2*(g-1)+1];
		int resz=min(g, n-g)-pr;
		debug() << imie(resz) << imie(pr);
		for (int i=1; i<=resz; i++)
			printf("%c", wcz[i-1]);
		for (int i=-pr+1; i<=pr; i++)
			printf("%c", wcz[g-1+i]);
		for (int i=resz; i; i--)
			printf("%c", wcz[i-1]);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}