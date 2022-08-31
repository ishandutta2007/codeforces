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
const int nax=1007;

int n;
vi graf[nax];

void ff()
{
	fflush(stdout);
}

int odl[nax][nax];

pii pyt(vi wek)
{
	printf("? %d", (int)wek.size());
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	int a, b;
	scanf("%d%d", &a, &b);
	return {a, b};
}

void ans(pii v)
{
	printf("! %d %d\n", v.first, v.second);
	ff();
}

char wcz[nax];

void because_people_are_stupid()
{
	scanf("%s", wcz);
}

void fillodl(int v, int oj, int o, int s)
{
	odl[s][v]=o;
	for (int i : graf[v])
		if (i!=oj)
			fillodl(i, v, o+1, s);
}

int roz[nax];

vector<vi> sci[nax];
vi drz[nax];

bool mniej(int a, int b)
{
	return roz[a]>roz[b];
}

int czas;
int ost[nax];

void dfs1(int v, int oj)
{
	ost[v]=czas;
	roz[v]=1;
	for (int &i : graf[v])
	{
		if (i==oj)
			continue;
		drz[v].push_back(i);
		dfs1(i, v);
		roz[v]+=roz[i];
	}
	sort(drz[v].begin(), drz[v].end(), mniej);
}

int rep[nax];
int gle[nax];

vi jego[nax];

void dfs2(int v)
{
	if (!drz[v].empty())
	{
		rep[drz[v][0]]=rep[v];
		gle[drz[v][0]]=gle[v];
		for (int i : drz[v])
		{
			if (i==drz[v][0])
				continue;
			rep[i]=i;
			gle[i]=gle[v]+1;
		}
	}
	debug() << v << " " << rep[v] << " " << gle[v];
	jego[rep[v]].push_back(v);
	for (int i : drz[v])
		dfs2(i);
}

int solve(int korz, int pod, int dlu)
{
	czas++;
	dfs1(pod, korz);
	rep[pod]=pod;
	dfs2(pod);
	for (int i=0; i<nax; i++)
		sci[i].clear();
	for (int i=1; i<=n; i++)
		if (ost[i]==czas && rep[i]==i)
			sci[gle[i]].push_back(jego[i]);
	int naj=0;
	while(!sci[naj+1].empty())
		naj++;
	int bsa=0;
	int bsb=naj;
	int g=0;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		vi ter;
		for (vi j : sci[bss])
			for (int l : j)
				ter.push_back(l);
		pii wez=pyt(ter);
		if (wez.second==dlu)
		{
			bsa=bss;
			for (int j=0; j<(int)sci[bss].size(); j++)
				for (int l : sci[bss][j])
					if (l==wez.first)
						g=j;
		}
		else
		{
			bsb=bss-1;
		}
	}
	int d=bsa;
	vi wek=sci[d][g];
	int x=pyt({wek.back()}).second;
	int gor=(x-dlu)>>1;
	int r=(int)wek.size()-1-gor;
	return wek[r];
}

void test()
{
	scanf("%d", &n);
	for (int i=0; i<nax; i++)
	{
		graf[i].clear();
		jego[i].clear();
		sci[i].clear();
		gle[i]=rep[i]=0;
		czas=0;
		ost[i]=0;
		drz[i].clear();
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	vi wsz(n);
	iota(wsz.begin(), wsz.end(), 1);
	pii wez=pyt(wsz);
	int korz=wez.first;
	int dlu=wez.second;
	
	for (int i=1; i<=n; i++)
		fillodl(i, 0, 0, i);
	
	vi pod;
	wsz.clear();
	for (int i : graf[korz])
		wsz.push_back(i);
	pod.push_back(pyt(wsz).first);
	wsz.clear();
	for (int i : graf[korz])
		if (i!=pod[0])
			wsz.push_back(i);
	if (!wsz.empty())
	{
		wez=pyt(wsz);
		if (wez.second==dlu)
			pod.push_back(wez.first);
	}
	vi wyn;
	debug() << imie(pod);
	for (int i : pod)
		wyn.push_back(solve(korz, i, dlu));
	if ((int)pod.size()==1)
		wyn.push_back(korz);
	
	ans({wyn[0], wyn[1]});
	because_people_are_stupid();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}