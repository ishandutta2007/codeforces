//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int nax=1007*1007;

int n, m;

vi graf[nax];

int bylo[nax];

vi wek[nax];

vector<pii> pary;
vi scie;

int gle[nax];
int ngle;

void dfs1(int v)
{
	if (gle[v]>ngle)
		ngle=gle[v];
	bylo[v]=1;
	for (int i : graf[v])
	{
		if (bylo[i])
			continue;
		gle[i]=gle[v]+1;
		dfs1(i);
	}
}

vi trz[nax];

vi stos;

void dfs2(int v)
{
	stos.push_back(v);
	if (gle[v]==ngle && scie.empty())
		scie=stos;
	bylo[v]=1;
	vi dz;
	for (int i : graf[v])
	{
		if (bylo[i])
			continue;
		dfs2(i);
		dz.push_back(i);
	}
	int k=0;
	wek[v].clear();
	for (int i : dz)
	{
		k++;
		swap(trz[k], wek[i]);
	}
	priority_queue<pii> kol;
	for (int i=1; i<=k; i++)
		kol.push({(int)trz[i].size(), i});
	while((int)kol.size()>1)
	{
		pii x=kol.top();
		kol.pop();
		pii y=kol.top();
		kol.pop();
		x.first--;
		y.first--;
		
		int a=trz[x.second].back();
		int b=trz[y.second].back();
		trz[x.second].pop_back();
		trz[y.second].pop_back();
		pary.push_back({a, b});
		
		if (x.first)
			kol.push(x);
		if (y.first)
			kol.push(y);
	}
	if (!kol.empty())
		swap(wek[v], trz[kol.top().second]);
	wek[v].push_back(v);
	stos.pop_back();
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
		bylo[i]=0;
	}
	for (int j=1; j<=m; j++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	scie.clear();
	pary.clear();
	ngle=0;
	gle[1]=1;
	dfs1(1);
	for (int i=1; i<=n; i++)
		bylo[i]=0;
	dfs2(1);
	
	
	
	int chce=(n+1)/2;
	debug() << imie(scie.size()) << imie(pary.size());
	assert((int)scie.size()>=chce || (int)pary.size()*2>=chce);
	if ((int)scie.size()>=chce)
	{
		printf("PATH\n%d\n", (int)scie.size());
		for (int i : scie)
			printf("%d ", i);
		printf("\n");
	}
	else
	{
		printf("PAIRING\n%d\n", (int)pary.size());
		for (pii i : pary)
			printf("%d %d\n", i.first, i.second);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}