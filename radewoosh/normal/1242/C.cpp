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
const int kax=17;
const int nax=5007;

int k;

vll wek[kax];
ll mas[kax];

ll wsz;

vector <pii> graf[kax][nax];

void nope()
{
	printf("No\n");
	exit(0);
}

vector <pii> pok[1<<kax];

int bylo[kax][nax];

vector <pii> stos;

void dfs(int v, int u)
{
	if (bylo[v][u])
	{
		if (bylo[v][u]==1)
		{
			vector <pii> wsz;
			int juz=0;
			int mas=0;
			int zle=0;
			for (pii i : stos)
			{
				if (i==make_pair(v, u))
					juz=1;
				if (juz)
				{
					wsz.push_back(i);
					if (mas&(1<<i.first))
						zle=1;
					mas|=(1<<i.first);
				}
			}
			if (!zle)
				pok[mas]=wsz;
		}
		return;
	}
	bylo[v][u]=1;
	stos.push_back({v, u});
	
	for (pii i : graf[v][u])
		dfs(i.first, i.second);
	
	bylo[v][u]=2;
	stos.pop_back();
}

int dp[1<<kax];

pii wyn[kax];

int main()
{
	scanf("%d", &k);
	for (int i=0; i<k; i++)
	{
		int x, y;
		scanf("%d", &x);
		while(x--)
		{
			scanf("%d", &y);
			wek[i].push_back(y);
			mas[i]+=y;
		}
		wsz+=mas[i];
	}
	if (wsz%k)
		nope();
	wsz/=k;
	for (int i=0; i<k; i++)
	{
		mas[i]=mas[i]-wsz;
		sort(wek[i].begin(), wek[i].end());
	}
	for (int i=0; i<k; i++)
	{
		for (int j=0; j<k; j++)
		{
			int b=0;
			for (int a=0; a<(int)wek[i].size(); a++)
			{
				while(b<(int)wek[j].size() && wek[j][b]<wek[i][a]+mas[j])
					b++;
				//~ int b=lower_bound(wek[j].begin(), wek[j].end(), wek[i][a]+mas[j])-wek[j].begin();
				if (b<(int)wek[j].size() && wek[j][b]==wek[i][a]+mas[j])
					graf[j][b].push_back({i, a});
			}
		}
	}
	for (int i=0; i<k; i++)
	{
		for (int j=0; j<(int)wek[i].size(); j++)
		{
			if (bylo[i][j])
				continue;
			dfs(i, j);
		}
	}
	dp[0]=1;
	for (int i=1; i<(1<<k); i++)
		for (int j=i; j; j=(j-1)&i)
			if (!pok[j].empty() && dp[i^j])
				dp[i]=1;
	if (!dp[(1<<k)-1])
		nope();
	
	int v=(1<<k)-1;
	while(v)
	{
		for (int i=v; i; i=(i-1)&v)
		{
			if (dp[v^i] && !pok[i].empty())
			{
				vector <pii> wez=pok[i];
				reverse(wez.begin(), wez.end());
				int r=wez.size();
				for (int j=0; j<r; j++)
					wyn[wez[j].first].first=wek[wez[j].first][wez[j].second];
				for (int j=0; j<r; j++)
					wyn[wez[j].first].second=wez[(j+1)%r].first+1;
				v^=i;
				break;
			}
		}
	}
	printf("Yes\n");
	for (int i=0; i<k; i++)
		printf("%d %d\n", wyn[i].first, wyn[i].second);
	return 0;
}