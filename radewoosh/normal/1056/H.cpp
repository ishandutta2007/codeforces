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
const int nax=1000*1007;
const ll mod1=1000*1000*1000+7;
const ll mod2=1000*1000*1000+9;
const ll h=1000*1000+3;
const int d=500;

int n, k;

vi wek[nax];

bool mniej(const vi &a, const vi &b)
{
	return ((int)a.size()>(int)b.size());
}

int gdz[nax];

inline bool liniowo(const int &a, const int &b)
{
	for (const int &i : wek[a])
		gdz[i]=-1;
	int num=0;
	for (const int &i : wek[b])
	{
		gdz[i]=num;
		num++;
	}
	int ost=1e9;
	int tak=0;
	for (const int &i : wek[a])
	{
		if (gdz[i]==-1)
		{
			tak=0;
		}
		else
		{
			if (!(gdz[i]<ost || (tak && gdz[i]==ost+1)))
				return false;
			tak=1;
			ost=gdz[i];
		}
	}
	return true;
}

vector <pii> wys[nax];
int ost[nax];
pll wpi[nax];
int czas;

int juz[nax];

//~ bool mniej2(const pii &a, const pii &b)
//~ {
	//~ int ja=wek[a.first].size()-a.second;
	//~ int jb=wek[b.first].size()-b.second;
	//~ return ja>jb;
//~ }

void test()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; i++)
	{
		int a;
		scanf("%d", &a);
		wek[i].clear();
		wek[i].resize(a);
		for (int j=0; j<a; j++)
			scanf("%d", &wek[i][j]);
	}
	sort(wek+1, wek+1+k, mniej);
	int w=0;
	for (int i=1; i<=k && (int)wek[i].size()>=d; i++)
	{
		w=i;
		for (int j=i+1; j<=k; j++)
		{
			if (!liniowo(i, j))
			{
				printf("Human\n");
				return;
			}
		}
	}
	for (int i=1; i<=n; i++)
		ost[i]=juz[i]=0;
	czas=-1;
	w++;
	for (int i=1; i<=n; i++)
		wys[i].clear();
	for (int i=w; i<=k; i++)
		for (int j=0; j+1<(int)wek[i].size(); j++)
			wys[wek[i][j]].push_back({i, j});
	for (int i=1; i<=n; i++)
	{
		//~ sort(wys[i].begin(), wys[i].end(), mniej2);
		for (const pii &j : wys[i])
		{
			//~ if (juz[wek[j.first][j.second+1]]==i)
				//~ continue;
			juz[wek[j.first][j.second+1]]=i;
			pll utrz{0, 0};
			for (int l=j.second+1; l<(int)wek[j.first].size(); l++)
			{
				const int &x=wek[j.first][l];
				utrz={(utrz.first*h+x)%mod1, (utrz.second*h+x)%mod2};
				if (ost[x]==i && wpi[x]!=utrz)
				{
					printf("Human\n");
					return;
				}
				ost[x]=i;
				wpi[x]=utrz;
			}
		}
	}
	
	printf("Robot\n");
}

int main()
{
	int tt;
	scanf("%d", &tt);
	while(tt--)
		test();
	return 0;
}