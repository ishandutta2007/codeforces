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
const int nax=2007;
const int d=9;

int n;

int z[nax];
int gdz[nax];

int dp[nax][nax][d];

int m;
vector <int> komb[nax];
int us[nax][d];
int dod[nax][d];

void mini(int &a, int b)
{
	a=min(a, b);
}

void cons(vector <int> wek)
{
	komb[m]=wek;
	m++;
}

int szuk(vector <int> wek)
{
	for (int i=0; i<m; i++)
		if (komb[i]==wek)
			return i;
	return -1;
}

vector<int> usun(vector <int> wek, int v)
{
	for (int &i : wek)
	{
		if (i==v)
		{
			swap(i, wek.back());
			wek.pop_back();
			return usun(wek, v);
		}
	}
	sort(wek.begin(), wek.end());
	return wek;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &z[i], &gdz[i]);
		z[i]--;
		gdz[i]--;
	}
	cons({});
	for (int i=0; i<d; i++)
		cons({i});
	for (int i=0; i<d; i++)
		for (int j=i; j<d; j++)
			cons({i, j});
	for (int i=0; i<d; i++)
		for (int j=i; j<d; j++)
			for (int l=j; l<d; l++)
				cons({i, j, l});
	for (int i=0; i<d; i++)
		for (int j=i; j<d; j++)
			for (int l=j; l<d; l++)
				for (int k=l; k<d; k++)
					cons({i, j, l, k});
	
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<d; j++)
		{
			auto now=usun(komb[i], j);
			us[i][j]=szuk(now);
			now=komb[i];
			now.push_back(j);
			sort(now.begin(), now.end());
			//~ now.resize(unique (now.begin(), now.end())-now.begin());
			dod[i][j]=szuk(now);
		}
	}
	
	for (int i=0; i<=n; i++)
		for (int j=0; j<m; j++)
			for (int l=0; l<d; l++)
				dp[i][j][l]=1e9;
	
	dp[0][0][0]=0;
	for (int i=0; i<=n; i++)
	{
		for (int j=m-1; j>=0; j--)
		{
			for (int l=0; l<d-1; l++)
				mini(dp[i][j][l+1], dp[i][j][l]+1);
			for (int l=d-1; l>0; l--)
				mini(dp[i][j][l-1], dp[i][j][l]+1);
			for (int l=0; l<d; l++)
			{
				if (i<n && z[i+1]==l)
				{
					int x=dod[j][gdz[i+1]];
					if (x!=-1)
						mini(dp[i+1][x][l], dp[i][j][l]);
				}
				mini(dp[i][us[j][l]][l], dp[i][j][l]);
			}
		}
	}
	
	int wyn=1e9;
	for (int i=0; i<d; i++)
		wyn=min(wyn, dp[n][0][i]);
	printf("%d\n", wyn+2*n);
	return 0;
}