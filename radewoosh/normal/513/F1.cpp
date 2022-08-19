//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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

struct flow
{
	int n, zr, uj;
	vector<vector<pair<int,pair<ll*,ll*>>>> graf;
	vector<vector<pair<int,pair<ll*,ll*>>>> dgraf;
	vector<int> odl;
	
	flow(){}
	flow(int vertex_limit) {
		graf.resize(vertex_limit + 1);
		dgraf.resize(vertex_limit + 1);
		odl.resize(vertex_limit + 1, 0);
	}
	bool iszero(ll v) {
		return (!v);//zmienic dla dabli
	}
	void add_edge(int v, int u, ll lim, bool bi_dir) {
		ll *a=new ll(lim);
		ll *b=new ll(lim*bi_dir);
		graf[v].push_back({u,{a, b}});
		graf[u].push_back({v,{b, a}});
	}
	void bfs() {
		for (int i=1; i<=n; i++) {
			odl[i]=0;
			dgraf[i].clear();
		}
		queue <int> kol;
		kol.push(zr);
		odl[zr]=1;
		while(!kol.empty()) {
			int v=kol.front();
			kol.pop();
			for (auto i : graf[v]) {
				if (!odl[i.first] && !iszero(*i.second.first)) {
					odl[i.first]=odl[v]+1;
					kol.push(i.first);
				}
				if (odl[i.first]==odl[v]+1 && !iszero(*i.second.first))
					dgraf[v].push_back(i);
			}
		}
	}
	ll dfs(int v, ll lim) {
		if (v==uj)
			return lim;
		ll ret=0;
		for (int i=0; i<(int)dgraf[v].size() && !iszero(lim); i++) {
			auto &j=dgraf[v][i];
			ll wez=0;
			if (!iszero(*j.second.first))
				wez=dfs(j.first, min(*j.second.first, lim));
			if (iszero(wez)) {
				swap(dgraf[v][i], dgraf[v].back());
				dgraf[v].pop_back();
				i--;
				continue;
			}
			ret+=wez;
			(*j.second.first)-=wez;
			(*j.second.second)+=wez;
			lim-=wez;
		}
		return ret;
	}
	ll dinic(int nn, int zrzr, int ujuj) {
		n=nn;
		zr=zrzr;
		uj=ujuj;
		ll ret=0;
		while(1) {
			bfs();
			ll sta=ret;
			if (iszero(sta-(ret+=dfs(zr, 1e18))))//cos wiekszego niz maxflow
				break;
		}
		return ret;
	}
};

const int nax=3007;
const int vax=30;
	
int n, m;

int ma, fe;
int chce;

int l, wej, wyj;

char wcz[vax][vax];
int juz[vax][vax];

int rx[]={0, 0, -1, 1};
int ry[]={-1, 1, 0, 0};

vector < pair <int,int> > sta;
vector < pair <long long, pair <int,int> > > wek;

void nope()
{
	printf("-1\n");
	exit(0);
}

int fri(int v, int u)
{
	if (v<0 || u<0 || v>=n || u>=m || wcz[v][u]=='#')
		return 0;
	return 1;
}

vector < pair <int, pair <int,int> > > bfs(int v, int u)
{
	vector < pair <int, pair <int,int> > > ret;
	memset(juz, 0, sizeof(juz));
	juz[v][u]=1;
	ret.push_back({0,{v,u}});
	for (int i=0; i<ret.size(); i++)
	{
		for (int j=0; j<4; j++)
		{
			int vv=ret[i].second.first+rx[j];
			int uu=ret[i].second.second+ry[j];
			if (!fri(vv, uu) || juz[vv][uu])
				continue;
			ret.push_back({ret[i].first+1,{vv,uu}});
			juz[vv][uu]=1;
		}
	}
	return ret;
}

void male()
{
	int v, u;
	long long czas;
	scanf("%d%d%lld", &v, &u, &czas);
	v--;
	u--;
	l++;
	sta.push_back({wej, l});
	for (auto i : bfs(v, u))
		wek.push_back({i.first*czas, {l, m*i.second.first+i.second.second+1}});
}

void female()
{
	int v, u;
	long long czas;
	scanf("%d%d%lld", &v, &u, &czas);
	v--;
	u--;
	l++;
	sta.push_back({l, wyj});
	for (auto i : bfs(v, u))
		wek.push_back({i.first*czas, {n*m+m*i.second.first+i.second.second+1, l}});
}

int check(int v)
{
	flow janusz=flow(nax);
	for (auto i : sta)
		janusz.add_edge(i.first, i.second, 1, false);
	for (auto i : wek)
	{
		janusz.add_edge(i.second.first, i.second.second, 1, false);
		if (!v)
			break;
		v--;
	}
	return (janusz.dinic(l, wej, wyj)==chce);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &ma, &fe);
	if (abs(ma-fe)!=1)
		nope();
	for (int i=0; i<n; i++)
		scanf("%s", wcz[i]);
	chce=max(ma, fe);
	l=n*m*2+2;
	wej=n*m*2+1;
	wyj=n*m*2+2;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			sta.push_back({i*m+j+1, n*m+i*m+j+1});
	if (ma<fe)
		male();
	else
		female();
	for (int i=1; i<=ma; i++)
		male();
	for (int i=1; i<=fe; i++)
		female();
	sort(wek.begin(), wek.end());
	int bsa=0;
	int bsb=wek.size();
	int bss;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)>>1;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	if (bsa!=wek.size())
		printf("%lld\n", wek[bsa].first);
	else
		nope();
	return 0;
}