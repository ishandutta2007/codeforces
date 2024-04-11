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
const int nax=100*1007;
const ll inf=1e18;

int n;
ll c, d;
ll tab[nax];
int kto[nax];

ll dp[nax];
ll wyn=inf;

ll ile[nax][2];
ll sum[nax][2];

int najd[nax];

//~ ll koszt(int i, int j)
//~ {
	//~ int x=kto[i];
	//~ return dp[j]+(ile[i][x^1]-ile[j][x^1])*d+((sum[i][x]-sum[j][x])-(tab[n+1]-tab[j])*(ile[i][x]-ile[j][x]))*c;
//~ }

ll koszt(int i, int j)
{
	int x=kto[i];
	ll ret=dp[j]+(ile[i][x^1]-ile[j][x^1])*d;
	ret+=(tab[j]-tab[i])*c;
	i++;
	if (i<najd[j])
	{
		ret+=(ile[i][x]-ile[najd[j]][x])*d;
		i=najd[j];
	}
	ret+=((sum[i][x]-sum[j][x])-(tab[n+1]-tab[j])*(ile[i][x]-ile[j][x]))*c;
	return ret;
}

vi poz[2];
vi pot[2];

void mini(ll &a, ll b)
{
	a=min(a, b);
}

void rek2(int h, int a, int b, int c, int d)
{
	if (a>b || c>d)
		return;
	int s=(a+b)>>1;
	int g=-1;
	ll war=inf;
	for (int i=c; i<=d; i++)
	{
		ll w=koszt(poz[h][s], pot[h][i]);
		if (w<war)
		{
			war=w;
			g=i;
		}
	}
	mini(dp[poz[h][s]], war);
	assert(g>=0);
	rek2(h, a, s-1, c, g);
	rek2(h, s+1, b, g, d);
}

void rek1(int a, int b)
{
	if (a>=b)
		return;
	int s=(a+b)>>1;
	rek1(s+1, b);
	
	poz[0].clear();
	poz[1].clear();
	pot[0].clear();
	pot[1].clear();
	for (int i=a; i<=s; i++)
		poz[kto[i]].push_back(i);
	for (int i=s+1; i<=b; i++)
		for (int h=0; h<2; h++)
			if (h!=kto[i])
				pot[h].push_back(i);
	
	for (int h=0; h<2; h++)
		rek2(h, 0, (int)poz[h].size()-1, 0, (int)pot[h].size()-1);
	
	
	rek1(a, s);
}

int main()
{
	scanf("%d%lld%lld", &n, &c, &d);
	for (int i=1; i<=n+1; i++)
	{
		tab[i]=i;
		scanf("%lld", &tab[i]);
		if (i<=n)
		{
			char x;
			scanf(" %c", &x);
			kto[i]=(x=='P');
			//~ kto[i]=rand()&1;
		}
		else
			kto[i]=2;
	}
	//~ debug() << range(tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
		dp[i]=inf;
	//~ debug() << imie(n) << imie(dp[6]);
	for (int i=n; i; i--)
	{
		for (int h=0; h<2; h++)
		{
			ile[i][h]=ile[i+1][h];
			sum[i][h]=sum[i+1][h];
		}
		ile[i][kto[i]]++;
		sum[i][kto[i]]+=(tab[n+1]-tab[i]);
	}
	
	for (int i=1; i<=n+1; i++)
	{
		najd[i]=max(najd[i-1], 1);
		while(d<c*(tab[i]-tab[najd[i]]))
			najd[i]++;
	}
	//~ debug() << range(najd+1, najd+1+n);
	
	//~ for (int i=n; i; i--)
		//~ for (int j=i+1; j<=n+1; j++)
			//~ if (kto[i]!=kto[j])
				//~ dp[i]=min(dp[i], koszt(i, j));
	
	rek1(1, n+1);
	//~ for (int i=n; i; i--)
	//~ {
		//~ for (int j=i+1; j<=n+1; j++)
		//~ {
			//~ if (kto[i]==kto[j])
				//~ continue;
			//~ ll trz=dp[j];
			//~ for (int l=i; l<j; l++)
			//~ {
				//~ if (kto[l]==kto[i])
				//~ {
					//~ if (l==i)
						//~ trz+=c*(tab[j]-tab[l]);
					//~ else
						//~ trz+=min(c*(tab[j]-tab[l]), d);
				//~ }
				//~ else
					//~ trz+=d;
			//~ }
			//~ dp[i]=min(dp[i], trz);
		//~ }
	//~ }
	//~ debug() << range(dp+1, dp+1+n+1);
	
	for (int i=1; i<=n+1; i++)
		wyn=min(wyn, dp[i]+(i-1)*d);
	printf("%lld\n", wyn);
	return 0;
}