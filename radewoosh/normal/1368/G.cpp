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
const int n1=(1<<18);

int n, m;

int k;
vi graf[nax];
vi skier[nax][2];

ll wyn;

char wcz[nax];

int num(int a, int b)
{
	if (a<1 || a>n || b<1 || b>m)
		return -1;
	a--;
	b--;
	return a*m+b+1;
}

void kra(int a, int b)
{
	if (a==-1 || b==-1)
		return;
	graf[a].push_back(b);
	graf[b].push_back(a);
}

void skikra(int a, int b)
{
	if (a==-1 || b==-1)
		return;
	skier[a][1].push_back(b);
	skier[b][0].push_back(a);
}

int czas;
int pre[nax];
int post[nax];

void dfs(int v)
{
	czas++;
	pre[v]=czas;
	for (int i : skier[v][1])
		dfs(i);
	post[v]=czas;
}

int narz[nax];
int pod[nax][2];

pii daj(int v)
{
	if (!narz[v])
		return {pod[v][0], pod[v][1]};
	return {0, pod[v][0]+pod[v][1]};
}

void upd(int v)
{
	pod[v][0]=pod[v][1]=0;
	for (int i=0; i<2; i++)
	{
		pii w=daj(2*v+i);
		pod[v][0]+=w.first;
		pod[v][1]+=w.second;
	}
}

vector<pii> dod[nax];
vector<pii> usu[nax];

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
		{
			if (wcz[j]=='U')
			{
				kra(num(i, j), num(i+1, j));
				skikra(num(i+2, j), num(i, j));
			}
			if (wcz[j]=='D')
			{
				skikra(num(i-2, j), num(i, j));
			}
			if (wcz[j]=='L')
			{
				kra(num(i, j), num(i, j+1));
				skikra(num(i, j+2), num(i, j));
			}
			if (wcz[j]=='R')
			{
				skikra(num(i, j-2), num(i, j));
			}
		}
	}
	k=n*m;
	for (int i=1; i<=k; i++)
		if (skier[i][0].empty())
			dfs(i);
	vector<pair<pii,pii>>wek;
	for (int i=1; i<=k; i++)
	{
		for (int j : graf[i])
		{
			wek.push_back({{pre[i], post[i]}, {pre[j], post[j]}});
		}
	}
	//~ debug() << wek;
	//~ for (int i=1; i<=k; i++)
	//~ {
		//~ for (int j=1; j<=k; j++)
		//~ {
			//~ int czy=0;
			//~ for (auto w : wek)
				//~ if (w.first.first<=i && i<=w.first.second && w.second.first<=j && j<=w.second.second)
					//~ czy=1;
			//~ wyn+=czy;
		//~ }
	//~ }
	vector<pair<int,pii>> eve;
	for (auto w : wek)
	{
		dod[w.first.first].push_back(w.second);
		usu[w.first.second].push_back(w.second);
	}
	sort(eve.begin(), eve.end());
	for (int i=1; i<=n1; i++)
		pod[n1-1+i][0]=1;
	for (int i=n1-1; i; i--)
		upd(i);
	for (int i=1; i<=k; i++)
	{
		for (pii j : dod[i])
			pisz(1, 1, n1, j.first, j.second, 1);
		wyn+=daj(1).second;
		for (pii j : usu[i])
			pisz(1, 1, n1, j.first, j.second, -1);
	}
	
	printf("%lld\n", wyn/2);
	return 0;
}