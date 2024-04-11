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

int n;

int kol[nax];

map<int,vi> mapa[4];

vector<vi> wek[4];

int juz[nax];

int check(int v)
{
	for (int k=1; k<=3; k++)
	{
		for (int h=0; h<4; h++)
		{
			for (int i=1; i<=n; i++)
				juz[i]=0;
			int jest[]={0, 0, 0, 0};
			for (vi &i : wek[h])
			{
				for (int j : i)
				{
					juz[j]=1;
					jest[kol[j]]++;
				}
				if (jest[k]>=v)
					break;
			}
			int a=k%3+1;
			int b=a%3+1;
			int pam=n/3-jest[b];
			for (int p=0; p<4; p++)
			{
				jest[a]=0;
				jest[b]=pam;
				for (vi &i : wek[p])
				{
					for (int j : i)
					{
						if (!juz[j])
						{
							if (kol[j]==a)
								jest[a]++;
							if (kol[j]==b)
								jest[b]--;
						}
					}
					if (jest[a]>=v && jest[b]>=v)
						return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d%d%d", &x, &y, &kol[i]);
		mapa[0][x].push_back(i);
		mapa[1][-x].push_back(i);
		mapa[2][y].push_back(i);
		mapa[3][-y].push_back(i);
	}
	for (int i=0; i<4; i++)
		for (auto j : mapa[i])
			wek[i].push_back(j.second);
	int bsa=0;
	int bsb=n/3;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (check(bss))
			bsa=bss;
		else
			bsb=bss-1;
	}
	printf("%d\n", bsa*3);
	return 0;
}