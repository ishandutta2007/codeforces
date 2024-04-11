//while (clock()<=69*CLOCKS_PER_SEC)
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
const int nax=3000*1007;
const ll inf=1e18;

ll n, m1, m2, t;

int k;
map <ll,int> inter;
ll tab[nax];
int blok[nax][2];
//~ int juz[nax][2];
ll dp[nax][2];

vector < pair <ll,int> > wek;

//~ ll licz(int v, int u)
//~ {
	//~ if (v==1)
		//~ return 0;
	//~ if (juz[v][u])
		//~ return dp[v][u];
	//~ juz[v][u]=1;
	//~ if (blok[v][u])
	//~ {
		//~ ll wez=licz(v-1, u);
		//~ if (wez+t>=tab[v])
			//~ dp[v][u]=inf;
		//~ else
			//~ dp[v][u]=wez+t;
	//~ }
	//~ else
	//~ {
		//~ ll ret=inf;
		//~ ret=min(ret, licz(v, u^1));
		//~ ret=min(ret, licz(v-1, u));
		//~ dp[v][u]=ret;
	//~ }
	//~ debug() << v << " " << u << " " << dp[v][u];
	//~ return dp[v][u];
//~ }

vector <int> ruch;
vector < pair <int,int> > shoot;

int main()
{
	scanf("%lld%lld%lld%lld", &n, &m1, &m2, &t);
	for (int i=1; i<=m1; i++)
	{
		ll x;
		scanf("%lld", &x);
		wek.push_back({x, 0});
	}
	for (int i=1; i<=m2; i++)
	{
		ll x;
		scanf("%lld", &x);
		wek.push_back({x, 1});
	}
	for (auto i : wek)
		for (int j=-1; j<=1; j++)
			inter[i.first+j]=0;
	inter[0]=0;
	inter[n+1]=0;
	for (auto i : inter)
	{
		k++;
		inter[i.first]=k;
		tab[k]=i.first;
	}
	for (auto i : wek)
		blok[inter[i.first]][i.second]=1;
	dp[1][0]=dp[1][1]=t;
	for (int i=2; i<=k; i++)
	{
		dp[i][0]=dp[i][1]=inf;
		for (int h=0; h<5; h++)
		{
			for (int j=0; j<2; j++)
			{
				if (blok[i][j])
				{
					ll w=dp[i-1][j]+t;
					if (dp[i-1][j]>=tab[i])
						w=inf;
					dp[i][j]=min(dp[i][j], w);
				}
				else
				{
					ll w=min(dp[i-1][j], max(dp[i][j^1], tab[i]));
					
					dp[i][j]=min(dp[i][j], w);
				}
			}
		}
		//~ debug() << i << " " << range(dp[i], dp[i]+2);
	}
	if (dp[k][0]==inf)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	
	int i=k;
	int v=0;
	while(i>1)
	{
		//~ debug() << i << " " << v << " " << dp[i][v];
		if (blok[i][v])
		{
			shoot.push_back({dp[i][v]-t, v+1});
			i--;
		}
		else
		{
			if (dp[i-1][v]==dp[i][v])
			{
				i--;
			}
			else
			{
				v^=1;
				ruch.push_back(tab[i]);
			}
		}
	}
	
	if (v)
		ruch.push_back(0);
	
	sort(ruch.begin(), ruch.end());
	sort(shoot.begin(), shoot.end());
	
	printf("%d\n", (int)ruch.size());
	for (int i : ruch)
		printf("%d ", i);
	printf("\n");
	
	printf("%d\n", (int)shoot.size());
	for (auto i : shoot)
		printf("%d %d\n", i.first, i.second);
	
	return 0;
}