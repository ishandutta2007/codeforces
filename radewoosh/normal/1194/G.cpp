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
const int nax=1007;
const ll mod=998244353;

int n;
char wcz[nax];

ll wyn;

map <pair<pii,int>,ll> mapa[nax][2][2];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int a=1; a<10; a++)
	{
		for (int b=1; b<10; b++)
		{
			//~ debug() << imie(a) << " " << imie(b);
			if (__gcd(a, b)!=1)
				continue;
			if (a==1 && b==1)
			{
				ll x=0;
				for (int i=1; i<=n; i++)
					x=(x*10+wcz[i]-'0')%mod;
				dod(wyn, x);
				continue;
			}
			int fl=0;
			int fm=0;
			for (int p=1; p*max(a, b)<10; p++)
			{
				fl|=(1<<(p*a));
				fm|=(1<<(p*b));
			}
			for (int i=1; i<=n; i++)
				for (int j=0; j<2; j++)
					for (int l=0; l<2; l++)
						mapa[i][j][l].clear();
			mapa[0][0][0][{{0, 0}, 0}]=1;
			for (int i=1; i<=n; i++)
			{
				for (int j=0; j<2; j++)
				{
					for (int l=0; l<2; l++)
					{
						for (auto x : mapa[i-1][j][l])
						{
							int ml=x.first.first.first;
							int mm=x.first.first.second;
							int bil=x.first.second;
							ll mno=x.second;
							for (int g=0; g<10; g++)
							{
								for (int d=0; d<10; d++)
								{
									int nml=(ml|(1<<g))&fl;
									int nmm=(mm|(1<<d))&fm;
									int nbil=(10*bil+a*d-b*g);
									if (abs(nbil)>=9)
										continue;
									if ((j || g<=wcz[i]-'0') && (l || d<=wcz[i]-'0'))
										dod(mapa[i][j|(g<wcz[i]-'0')][l|(d<wcz[i]-'0')][{{nml, nmm}, nbil}], mno);
								}
							}
						}
					}
				}
			}
			for (int j=0; j<2; j++)
			{
				for (int l=0; l<2; l++)
				{
					for (auto x : mapa[n][j][l])
					{
						if (x.first.second)
							continue;
						int ml=x.first.first.first;
						int mm=x.first.first.second;
						ll mno=x.second;
						int czy=0;
						for (int p=1; p*max(a, b)<10; p++)
							if ((ml&(1<<(p*a))) && (mm&(1<<(p*b))))
								czy=1;
						//~ if (czy)
							//~ debug() << a << " " << b << "   " << imie(ml) << imie(mm) << imie(mno);
						if (czy)
							dod(wyn, mno);
					}
				}
			}
		}
	}
	
	printf("%lld\n", wyn);
	return 0;
}