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
using duz=long long;
const ll inf=1e18;

struct node {
	int roz=1;
	ll id;
	node *lew, *oj, *pra;
	node() { lew=pra=oj=NULL; }
	node(ll idid) { lew=pra=oj=NULL; id=idid;}
};
void update(node *v) {
	if (v==NULL) return;
	v->roz=1;
	for (int h=0; h<2; h++) {
		if (v->lew!=NULL) {
			v->roz+=v->lew->roz;
		}
		swap(v->lew, v->pra);
	}
}
node *merge(node *v, node *u) {
	if (v==NULL) return u;
	if (u==NULL) return v;	
	if (rand()%(v->roz+u->roz)<(v->roz)) {
		update(v);//czasem mona usun
		v->pra=merge(v->pra, u);
		v->pra->oj=v;
		update(v);
		return v;
	} else {
		update(u);//czasem mona usun
		u->lew=merge(v, u->lew);
		u->lew->oj=u;
		update(u);
		return u;
	}
}
pair <node*, node*> split(node *v, const function <bool(node*)> &is_left) {
	if (v==NULL)
		return make_pair(v, v);
	pair <node*, node*> ret;
	update(v);//czasem mona usun
	v->oj=NULL;
	if (is_left(v)) {
		ret=split(v->pra, is_left);
		v->pra=ret.first;
		if (v->pra!=NULL)
			v->pra->oj=v;
		ret.first=v;
	} else {
		ret=split(v->lew, is_left);
		v->lew=ret.second;
		if (v->lew!=NULL)
			v->lew->oj=v;
		ret.second=v;
	}
	update(v);
	return ret;
}
ll gl_help;
function <bool(node*)> cut_v(int v) {
	gl_help=v;
	return [](node *u)->bool {
		int pom=1;
		if (u->lew!=NULL) pom+=u->lew->roz;
		if (pom>gl_help) return false;
		gl_help-=pom;
		return true;
	};
}
function <bool(node*)> cut_leq(int v)
{
	gl_help=v;
	return [](node* u)->bool{return u->id<=gl_help;};
}
int position(node *v) {
	int ret=1;
	if (v->lew!=NULL) ret+=v->lew->roz;
	if (v->oj==NULL) return ret;
	return position(v->oj)+ret-(v->oj->lew==v)*(v->roz+1);
}
void kasuj(node *v)
{
	if (v==NULL)
		return;
	kasuj(v->lew);
	kasuj(v->pra);
	delete v;
}
ll mini(node *v)
{
	if (v->lew)
		return mini(v->lew);
	return v->id;
}
ll maxi(node *v)
{
	if (v->pra)
		return maxi(v->pra);
	return v->id;
}

int n, m;

int dok[nax];
ll kied[nax];

vector<pair<int,ll>> graf[nax];
ll gle[nax];
vi jump[nax];

void dfs1(int v, int oj)
{
	jump[v].push_back(oj);
	while (jump[v].back())
	{
		int a=jump[v].back();
		int b=min(jump[v].size(), jump[a].size())-1;
		jump[v].push_back(jump[a][b]);
	}
	for (int i=0; i<(int)graf[v].size(); i++)
	{
		if (graf[v][i].first==oj)
		{
			graf[v].erase(graf[v].begin()+i);
			break;
		}
	}
	for (auto i : graf[v])
	{
		gle[i.first]=gle[v]+i.second;
		dfs1(i.first, v);
	}
}

vll poc[nax];
vector<pll> prze;

node *drz[nax];

void dfs2(int v)
{
	for (auto i : graf[v])
		dfs2(i.first);
	if (graf[v].empty())
	{
	}
	else
	{
		drz[v]=drz[graf[v].back().first];
		priority_queue<pair<ll,node*>>kol;
		for (auto i : graf[v])
			if (i!=graf[v].back() && drz[i.first]!=NULL)
				kol.push({-mini(drz[i.first]), drz[i.first]});
		int fri=graf[v].back().first;
		ll ost=-inf;
		while(!kol.empty())
		{
			auto wez=kol.top();
			kol.pop();
			ll x=-wez.first;
			node *cal=wez.second;
			auto trz=split(drz[v], cut_leq(x));
			if (trz.first==NULL)
			{
				prze.push_back({1, x+gle[v]});
			}
			else
			{
				ll y=maxi(trz.first);
				prze.push_back({y+1+gle[v], x+gle[v]});
			}
			drz[v]=merge(trz.first, cal);
			if (trz.second!=NULL)
				kol.push({-mini(trz.second), trz.second});
		}
	}
	for (ll i : poc[v])
	{
		auto trz=split(drz[v], cut_leq(i));
		node *now=new node(i);
		drz[v]=merge(trz.first, merge(now, trz.second));
	}
}

vll zabilem;

void solve()
{
	for (int i=1; i<=n; i++)
		poc[i].clear();
	prze.clear();
	for (int i=1; i<=m; i++)
		poc[dok[i]].push_back(kied[i]);
	dfs2(1);
	sort(prze.begin(), prze.end());
	ll mom=1;
	priority_queue<ll> pom;
	int w=0;
	int juz=0;
	while(w<(int)prze.size() || !pom.empty())
	{
		while(w<(int)prze.size() && mom==prze[w].first)
		{
			pom.push(-prze[w].second);
			w++;
		}
		if (!pom.empty())
		{
			ll x=-pom.top();
			pom.pop();
			if (x<mom)
			{
				int wyn=juz;
				for (ll i : zabilem)
					if (i>=x)
						wyn--;
				printf("%lld %d\n", x, wyn);
				return;
			}
			mom++;
			juz++;
			zabilem.push_back(x);
		}
		else
		{
			if (w==(int)prze.size())
				break;
			mom=max(mom, prze[w].first);
		}
	}
	printf("-1 %d\n", juz);
}

int main()
{
	scanf("%d%d", &n, &m);
	//~ n=1e5;
	//~ m=1e5;
	for (int i=1; i<n; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		//~ b=i+1;
		//~ a=(i+1)/2;
		//~ c=rand()%(1000000000)+1;
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	//~ for (int i=1; i<=m; i++)
	//~ {
		//~ dok[i]=rand()%n+1;
		//~ kied[i]=kied[i-1]+(rand()%5)+1;
	//~ }
	for (int i=1; i<=m; i++)
		scanf("%d%lld", &dok[i], &kied[i]);
	dfs1(1, 0);
	ll bsa=0;
	ll bsb=1e15;
	solve();
	return 0;
}