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
const int nax=307;
const int kax=1007;
const int inf=1e9;
const ll mod=1000*1000*1000+7;

int n, q;

ll tab[nax];

vi graf[nax];
ll mac[nax][nax];

ll eigen[nax][nax];

ll nor[nax][nax];
ll odw[nax][nax];

ll coef[nax][nax];

ll potfast[nax][kax];
ll odwfast[nax][kax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void dod(int a, int b, ll w)
{
	for (int i=1; i<=n; i++)
	{
		dod(nor[a][i], nor[b][i]*w);
		dod(odw[a][i], odw[b][i]*w);
	}
}

void zam(int a, int b)
{
	for (int i=1; i<=n; i++)
	{
		swap(nor[a][i], nor[b][i]);
		swap(odw[a][i], odw[b][i]);
	}
}

void mno(int a, ll w)
{
	for (int i=1; i<=n; i++)
	{
		nor[a][i]=(nor[a][i]*w)%mod;
		odw[a][i]=(odw[a][i]*w)%mod;
	}
}

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

ll pot(ll a, ll b)
{
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

int budzi[nax];
ll fen[nax][nax];

void pisz(int g, int v, ll w)
{
	v++;
	for (int i=v; i<=n; i+=(i&(-i)))
		dod(fen[g][i], w);
}

ll czyt(int g, int v)
{
	v++;
	ll ret=0;
	for (int i=min(v, n); i; i-=(i&(-i)))
		dod(ret, fen[g][i]);
	return ret;
}

void rebuild()
{
	for (int i=n; i; i--)
	{
		budzi[i]=inf;
		if (tab[i]>0)
			budzi[i]=0;
		for (int j : graf[i])
			budzi[i]=min(budzi[i], budzi[j]+1);
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			fen[i][j]=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (budzi[j]==inf)
				continue;
			dod(fen[i][budzi[j]+1], (tab[j]+mod)*coef[j][i]%mod*odwfast[i][budzi[j]]);
		}
		for (int j=1; j<=n; j++)
		{
		    int w=j+(j&(-j));
		    if (w<=n)
		        dod(fen[i][w], fen[i][j]);
		}
	}
}

void update(int a, int b)
{
	for (int i=1; i<=n; i++)
		pisz(i, budzi[a], b*coef[a][i]%mod*odwfast[i][budzi[a]]);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		potfast[i][0]=odwfast[i][0]=1;
		potfast[i][1]=i;
		odwfast[i][1]=inv(i);
		for (int j=2; j<kax; j++)
		{
			potfast[i][j]=(potfast[i][j-1]*i)%mod;
			odwfast[i][j]=(odwfast[i][j-1]*odwfast[i][1])%mod;
		}
	}
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d", &x);
		mac[i][i]=i;
		while(x--)
		{
			scanf("%d", &y);
			mac[y][i]=y;
			graf[i].push_back(y);
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		eigen[i][i]=1;
		for (int j=i-1; j; j--)
		{
			ll x=0;
			for (int l=j+1; l<=i; l++)
				x=(x+eigen[i][l]*mac[l][j])%mod;
			eigen[i][j]=(x*inv(i-j))%mod;
		}
	}
	
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			nor[i][j]=eigen[i][j];
		odw[i][i]=1;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (nor[j][i])
			{
				zam(i, j);
				break;
			}
		}
		mno(i, inv(nor[i][i]));
		for (int j=1; j<=n; j++)
			if (j!=i)
				dod(j, i, mod-nor[j][i]);
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			coef[i][j]=odw[i][j];
	
	rebuild();
	
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(mac[i]+1, mac[i]+1+n);
	//~ debug();
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(eigen[i]+1, eigen[i]+1+n);
	//~ debug();
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(coef[i]+1, coef[i]+1+n);
	//~ debug();
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			dod(eigen[i][j], eigen[i][j-1]);
	
	scanf("%d", &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int k, l, r;
			scanf("%d%d%d", &k, &l, &r);
			ll wyn=0;
			for (int i=1; i<=n; i++)
			{
				if (budzi[i]>k && i>=l && i<=r)
					dod(wyn, mod+tab[i]);
			}
			for (int i=1; i<=n; i++)
			{
				dod(wyn, czyt(i, k)*potfast[i][k]%mod*(eigen[i][r]-eigen[i][l-1]+mod));
			}
			
			printf("%lld\n", wyn);
		}
		else
		{
			int a, b;
			scanf("%d%d", &a, &b);
			int sta=tab[a];
			tab[a]+=b;
			if (sta<=0 && tab[a]>0)
			{
				rebuild();
			}
			else
			{
				if (budzi[a]!=inf)
				{
					update(a, b);
				}
			}
		}
	}
	return 0;
}