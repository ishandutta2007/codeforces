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
const int nax=1000*1007;

struct node {
	int id;
	int roz=1;
	node *lew, *oj, *pra;
	int obr=0;
	int war;
	node() { lew=pra=oj=NULL; }
};
void update(node *v) {
	if (v==NULL) return;
	v->roz=1;
	for (int h=0; h<2; h++) {
		if (v->lew!=NULL) {
			v->roz+=v->lew->roz;
			v->lew->obr^=(v->obr);
		}
		swap(v->lew, v->pra);
	}
	if (v->obr)
	{
		v->obr=0;
		v->war*=-1;
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
int gl_help;
function <bool(node*)> cut_leq(int v) {
	gl_help=v;
	return [](node* u)->bool{return u->war<=gl_help;};
}
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
int position(node *v) {
	int ret=1;
	if (v->lew!=NULL) ret+=v->lew->roz;
	if (v->oj==NULL) return ret;
	return position(v->oj)+ret-(v->oj->lew==v)*(v->roz+1);
}

int mini(node *v)
{
	update(v);
	if (v->lew==NULL)
		return v->war;
	return mini(v->lew);
}

int n, q;

node *korz=NULL;

int wyn[nax];

node *scal(node *a, node *b)
{
	if (a==NULL)
		return b;
	if (b==NULL)
		return a;
	int x=mini(a);
	int y=mini(b);
	if (y<x)
	{
		swap(x, y);
		swap(a, b);
	}
	//~ debug() << imie(x) << imie(y);
	auto raz=split(a, cut_leq(y));
	node *wez=scal(raz.second, b);
	return merge(raz.first, wez);
}

void dfs(node *v)
{
	if (v==NULL)
		return;
	update(v);
	wyn[v->id]=v->war;
	dfs(v->lew);
	dfs(v->pra);
}

//~ void wypisz(node *v)
//~ {
	//~ if (v==NULL)
		//~ return;
	//~ update(v);
	//~ wypisz(v->lew);
	//~ printf("%d : %d\n", v->id, v->war);
	//~ wypisz(v->pra);
//~ }

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		node *ter=new node();
		ter->id=i;
		ter->war=x;
		korz=scal(korz, ter);
		//~ wypisz(korz);
		//~ debug();
	}
	while(q--)
	{
		char c;
		int x;
		scanf(" %c%d", &c, &x);
		if (c=='<')
		{
			auto raz=split(korz, cut_leq(x-1));
			if (raz.first)
				raz.first->obr^=1;
			korz=scal(raz.first, raz.second);
		}
		else
		{
			auto raz=split(korz, cut_leq(x));
			if (raz.second)
				raz.second->obr^=1;
			korz=scal(raz.first, raz.second);
		}
	}
	dfs(korz);
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}