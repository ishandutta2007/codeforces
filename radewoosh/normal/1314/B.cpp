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
const int inf=1e9;

int n, k, m;

int lub[nax];

struct mac
{
	int w[2][2];
	mac()
	{
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				w[i][j]=0;
	}
	mac(int v)
	{
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				w[i][j]=v;
	}
	void dawaj()
	{
		for (int i=0; i<2; i++)
			for (int j=0; j<2; j++)
				w[i][j]+=(i || j);
	}
};

void maxi(int &a, int b)
{
	a=max(a, b);
}

mac rek(int a, int b)
{
	if (a+1==b)
	{
		mac ret=mac(-inf);
		maxi(ret.w[lub[a]][lub[b]], 0);
		maxi(ret.w[lub[b]][lub[a]], 0);
		ret.dawaj();
		return ret;
	}
	mac raz=rek(a, (a+b)>>1);
	mac dwa=rek((a+b+2)>>1, b);
	mac ret=mac(-inf);
	for (int h=0; h<2; h++)
	{
		swap(raz, dwa);
		for (int a=0; a<2; a++)
		{
			for (int b=0; b<2; b++)
			{
				for (int c=0; c<2; c++)
				{
					for (int d=0; d<2; d++)
					{
						maxi(ret.w[a][b], raz.w[a][b]+dwa.w[c][d]+(a || c)+(b || d)+(b || c));//b, potem b
						maxi(ret.w[a][c], raz.w[a][b]+dwa.w[c][d]+(a || c)+(b || d)+(b || c));//b, potem c
						maxi(ret.w[a][d], raz.w[a][b]+dwa.w[c][d]+(a || c)+(b || d)+(d || c));//d, potem d
						maxi(ret.w[a][c], raz.w[a][b]+dwa.w[c][d]+(a || c)+(b || d)+(d || c));//d, potem c
					}
				}
			}
		}
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; i++)
	{
		int x;
		scanf("%d", &x);
		lub[x]=1;
	}
	m=(1<<n);
	mac wez=rek(1, m);
	int wyn=0;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			wyn=max(wyn, wez.w[i][j]+(i || j));
	printf("%d\n", wyn);
	return 0;
}