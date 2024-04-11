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

/*using ll=long long;

struct flow
{
	int n, zr, uj;
	vector<vector<pair<int,pair<ll*,ll*>>>> graf;
	vector<vector<pair<int,pair<ll*,ll*>>>> dgraf;
	vector<vector<ll>> ori;//do odzyskiwania flowu
	vector<int> odl;
	flow(){}
	flow(int vertex_limit) {
		graf.resize(vertex_limit + 1);
		dgraf.resize(vertex_limit + 1);
		odl.resize(vertex_limit + 1, 0);
		ori.resize(vertex_limit + 1);//do odzyskiwania flowu
	}
	bool iszero(ll v) {
		return (!v);//zmienic dla dabli
	}
	void add_edge(int v, int u, ll lim, bool bi_dir=false) {
		ll *a=new ll(lim);
		ll *b=new ll(lim*bi_dir);
		graf[v].push_back({u,{a, b}});
		graf[u].push_back({v,{b, a}});
		ori[v].push_back(lim);//do odzyskiwania flowu
		ori[u].push_back(lim*bi_dir);//do odzyskiwania flowu
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
			if (iszero(sta-(ret+=dfs(zr, 1e18))))//cos wiekszego niz maxflow, uwaga na overflow
				break;
		}
		return ret;
	}
	//ponizszych nie trzeba przepisywac
	void clear_memory() {
		for (int i=1; i<=n; i++)
			for (auto j : graf[i])
				delete(j.second.first);
	}
	//do ponizszych najpierw uzyc dinic()
	vector <int> cut() {
		vector <int> ret;
		bfs();
		for (int i=1; i<=n; i++)
			if (odl[i])
				ret.push_back(i);
		return ret;
	}
	map<pair<int,int>,ll> get_flowing() {//tam gdzie plynie 0 moze nie byc zainicjowane
		map<pair<int,int>,ll> ret;
		for (int i=1; i<=n; i++)
			for (int j=0; j<(int)graf[i].size(); j++)
				if ((*graf[i][j].second.first)<ori[i][j])
					ret[{i,graf[i][j].first}]+=ori[i][j]-(*graf[i][j].second.first);
		for (auto i : ret) {
			ll x=min(i.second, ret[{i.first.second,i.first.first}]);
			ret[i.first]-=x;
			ret[{i.first.second,i.first.first}]-=x;
		}
		return ret;
	}
};*/

const int nax=37;
const int vax=107;

int m;
int wym[nax];

bitset <nax*vax> dp[vax][nax];
bitset <nax*vax> z[vax][nax];

bitset <nax*vax> prze;

int juz[vax];

int mac[vax][vax];

int sto[vax];

void zrob(int n)
{
	printf("%d\n", n);
	int kt=m;
	int ile=0;
	for (int i=n; i>1; i--)
	{
		if (z[i][kt][ile])
		{
			sto[i]=wym[kt];
			ile=ile+(i-1)-wym[kt];
			kt--;
		}
		else
		{
			sto[i]=wym[kt];
			ile=ile+(i-1)-wym[kt];
		}
	}
	sto[1]=wym[1];
	for (int h=1; h<=n; h++)
	{
		vector <pair <int,int> > wek;
		for (int i=1; i<=n; i++)
			if (!juz[i])
				wek.push_back({sto[i], i});
		sort(wek.begin(), wek.end());
		reverse(wek.begin(), wek.end());
		reverse(wek.begin()+1, wek.end());
		for (int i=1; i<(int)wek.size(); i++)
		{
			if (i<=wek[0].first)
			{
				//debug() << "z " << wek[0].second << " " << wek[i].second;
				mac[wek[0].second][wek[i].second]=1;
			}
			else
			{
				//debug() << "z " << wek[i].second << " " << wek[0].second;
				mac[wek[i].second][wek[0].second]=1;
				sto[wek[i].second]--;
			}
		}
		//debug();
		juz[wek[0].second]=1;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			printf("%d", mac[i][j]);
		}
		printf("\n");
	}
	exit(0);
}

int main()
{
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
		scanf("%d", &wym[i]);
	sort(wym+1, wym+1+m);
	dp[1][1][wym[1]]=1;
	for (int i=1; i<=100; i++)
	{
		/*for (int j=1; j<=m; j++)
			for (int l=0; l<=3; l++)
				if (dp[i][j][l])
					debug() << i << " " << j << " " << l << " " << (int)z[i][j][l];*/
		if (dp[i][m][0])
		{
			zrob(i);
		}
		for (int j=1; j<=m; j++)
		{
			int bil;
			
			bil=wym[j]-(i);
			if (bil>0)
				prze=(dp[i][j]<<bil);
			else
				prze=(dp[i][j]>>(-bil));
			dp[i+1][j]|=prze;
			
			bil=wym[j+1]-(i);
			if (bil>0)
				prze=(dp[i][j]<<bil);
			else
				prze=(dp[i][j]>>(-bil));
			dp[i+1][j+1]|=prze;
			z[i+1][j+1]|=prze;
		}
	}
	printf("=(\n");
	return 0;
}