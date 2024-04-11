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
const int nax=107;
const int d=60;

int n;

int tab[nax];

ll fib[nax];

vi raz[nax];
vi dwa[nax];

int kto[nax];

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	//~ sort(tab+1, tab+1+n);
	ll s=0;
	for (int i=1; i<=n; i++)
		s+=tab[i];
	int g=-1;
	ll tu=0;
	for (int i=1; i<=d; i++)
	{
		tu+=fib[i];
		if (tu==s)
		{
			g=i;
			break;
		}
	}
	if (g==-1)
	{
		ans(0);
		return;
	}
	for (int i=1; i<=n; i++)
	{
		raz[i].clear();
		dwa[i].clear();
		{
			ll x=tab[i];
			for (int j=d; j; j--)
			{
				if (x>=fib[j])
				{
					raz[i].push_back(j);
					x-=fib[j];
				}
			}
		}
		{
			ll x=tab[i]-1;
			for (int j=d; j; j--)
			{
				if (x>=fib[j])
				{
					dwa[i].push_back(j);
					x-=fib[j];
				}
			}
		}
	}
	int wyj=0;
	for (int i=1; i<=n; i++)
		wyj+=raz[i].size();
	//~ debug() << imie(g) << wyj << " " << raz[1] << " " << dwa[1];
	for (int i=1; i<=n; i++)
	{
		if (wyj-(int)raz[i].size()+(int)dwa[i].size()+1!=g)
			continue;
		//~ debug() << imie("jade") << i;
		for (int j=0; j<=g+1; j++)
			kto[j]=0;
		int nope=0;
		kto[1]=i;
		for (int j=1; j<=n && !nope; j++)
		{
			//~ debug() << j << " " << (i==j ? dwa[j] : raz[j]);
			for (int l : (i==j ? dwa[j] : raz[j]))
			{
				if (l>g)
				{
					nope=1;
					break;
				}
				if (kto[l] || kto[l-1]==j || kto[l+1]==j)
				{
					nope=1;
					break;
				}
				kto[l]=j;
			}
		}
		//~ debug() << i;
		//~ debug() << range(kto+1, kto+1+g);
		if (nope)
			continue;
		ans(1);
		return;
	}
	
	ans(0);
}

int main()
{
	fib[1]=1;
	fib[2]=1;
	for (int i=3; i<=d; i++)
		fib[i]=fib[i-2]+fib[i-1];
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}