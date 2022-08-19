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

struct flow {
  struct edge {  // Mona dodawa atrybuty w celu identyfikacji krawdzi.
    int cel = 0;
    ll lim = 0;
    ll flow = 0;
    edge* odw;
  };

  //liczba wierzcholkow, numer zrodla i numer ujscia, numerowane od 1
  int n, zr, uj;

  vector<vector<edge*>> graf;
  vector<vector<edge*>> dgraf;
  vector<int> odl;

  flow(){}

  flow(int vertex_limit) {
    graf.resize(vertex_limit + 1);
    dgraf.resize(vertex_limit + 1);
    odl.resize(vertex_limit + 1, 0);
  }

  // Dodaje krawd od @v do @u o przepustowosci @lim.
  void add_edge(int v, int u, ll lim, bool bi_dir) {
    edge* wte = new edge();
    edge* wtamte = new edge();
    wte->odw = wtamte;
    wtamte->odw = wte;
    wte->lim = lim;
    if (bi_dir) wtamte->lim = lim;
    wte->cel = u;
    wtamte->cel = v;
    graf[v].push_back(wte);
    graf[u].push_back(wtamte);
  }

  // progarm uywa si wewntrznie, nie tyka
  void clear() {
    for (int i = 1; i <= n; i++) {
      odl[i] = 0;
      dgraf[i].clear();
    }
  }

  // progarm uywa si wewntrznie, nie tyka
  void bfs() {
    queue<int> kol;
    int u;
    kol.push(zr);
    odl[zr] = 1;
    while (!kol.empty()) {
      u = kol.front();
      kol.pop();
      for (int i = 0; i < graf[u].size(); i++) {
        if (!odl[graf[u][i]->cel] && graf[u][i]->lim) {
          odl[graf[u][i]->cel] = odl[u] + 1;
          kol.push(graf[u][i]->cel);
        }
        if (odl[graf[u][i]->cel] == odl[u] + 1)
          dgraf[u].push_back(graf[u][i]);
      }
    }
  }

  // progarm uywa si wewntrznie, nie tyka
  ll dfs(int v, ll mini) {
    if (v==uj) return mini;
    for (int i = 0; i < dgraf[v].size(); i++) {
      if (dgraf[v][i]->lim) {
        ll ret = dfs(dgraf[v][i]->cel, min(mini, dgraf[v][i]->lim));
        if (!ret) {
          swap(dgraf[v][i], dgraf[v].back());
          dgraf[v].pop_back();
          i--;
          continue;
        }
        dgraf[v][i]->lim -= ret;
        dgraf[v][i]->odw->lim += ret;
        dgraf[v][i]->flow += ret;
        ll pom = min(dgraf[v][i]->flow, dgraf[v][i]->odw->flow);
        dgraf[v][i]->flow -= pom;
        dgraf[v][i]->odw->flow -= pom;
        return ret;
      } else {
        swap(dgraf[v][i], dgraf[v].back());
        dgraf[v].pop_back();
        i--;
      }
    }
    return 0;
  }

  ll dinic(int nn, int zrzr, int ujuj) {
	n=nn;
	zr=zrzr;
	uj=ujuj;
    ll ret = 0;
    while (true) {
      clear();
      bfs();
      ll bier1 = 0;
      while (true) {
        // staa wiksza ni jakakolwiek przepustowo
        ll bier2 = dfs(zr, 1000 * 1000 * 1000);
        if (!bier2) break;
        bier1 += bier2;
      }
      if (!bier1) break;
      ret += bier1;
    }
    return ret;
  }
  void clear_memory()
  {
    for (int i=1; i<=n; i++)
        for (auto j : graf[i])
            delete(j);
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
	int ret=(janusz.dinic(l, wej, wyj)==chce);
	janusz.clear_memory();
	return ret;
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