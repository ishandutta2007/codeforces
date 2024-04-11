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
const int nax=200*1007;
const int d=600;
//~ const int d=0;

int n;
char wcz[nax];
int tab[nax];

int sum[nax];

ll wyn;

int czy(int a, int b)
{
	a--;
	int d=b-a;
	int j=sum[b]-sum[a];
	if (!j)
		return 0;
	return !(d%j);
}

int mapa[127*1007*1007];

int m;
int poz[nax];

int miesci(int v, int x)
{
	if (x>v)
		return 0;
	return v-x+1;
}

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
	{
		tab[i]=(wcz[i]=='1');
		sum[i]=sum[i-1]+tab[i];
	}
	for (int i=1; i<=d; i++)
	//~ for (int i=1; i<=3; i++)
	{
		for (int j=0; j<=n; j++)
		{
			int x=i*sum[j]-j+n;
			wyn+=mapa[x];
			mapa[x]++;
		}
		for (int j=0; j<=n; j++)
		{
			int x=i*sum[j]-j+n;
			mapa[x]=0;
		}
	}
	for (int i=1; i<=n; i++)
		if (tab[i])
		{
			m++;
			poz[m]=i;
		}
	poz[m+1]=n+1;
	for (int i=1; i<=m; i++)
	{
		for (int j=i; j<=m && (j-i+1)*(d+1)<=n; j++)
		{
			int jest=(j-i+1);
			int lew=poz[i]-poz[i-1]-1;
			int pra=poz[j+1]-poz[j]-1;
			int odl=poz[j]-poz[i]+1;
			//~ debug() << i << " " << j << "   " << jest << " " << odl << " " << pra << " " << lew;
			for (int l=max(d+1, (odl+jest-1)/jest); 1; l++)
			{
				//~ debug() << imie(l);
				if (jest*(ll)l>odl+lew+pra)
					break;
				//~ debug() << imie(l);
				wyn+=miesci(odl+pra+lew, jest*l)-miesci(pra+odl-1, jest*l)-miesci(lew+odl-1, jest*l);
			}
		}
	}
	
	
	printf("%lld\n", wyn);
	return 0;
}