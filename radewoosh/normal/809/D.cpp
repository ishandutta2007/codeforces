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

const int inf=1000*1000*1007;

struct node
{
	int id;
	int roz;
	int prior;
	node * lew;
	node * pra;
	node * oj;
	
	long long narz;
	long long war;
	
	node(int idid)
	{
		prior=rand();
		lew=NULL;
		pra=NULL;
		oj=NULL;
		roz=1;
		id=idid;
		narz=0;
		war=inf;
	}
	node()
	{
		prior=rand();
		lew=NULL;
		pra=NULL;
		oj=NULL;
		roz=1;
		narz=0;
		war=inf;
	}
};
inline void update(node * v)
{
	if (v==NULL)
		return;
	v->roz=1;
	v->war+=v->narz;
	if (v->lew!=NULL)
	{
		v->lew->narz+=v->narz;
		v->roz+=v->lew->roz;
	}
	if (v->pra!=NULL)
	{
		v->pra->narz+=v->narz;
		v->roz+=v->pra->roz;
	}
	v->narz=0;
	//tutaj dodajemy wszystkie operacje zwizane z funkcjami m.in. drzewa przedziaowego, tzn. lazy propagation itp.
}
node * merge(node * v, node * u)
{
	if (v==NULL)
		return u;
	if (u==NULL)
		return v;
	if ((v->prior)>=(u->prior))
	{
		update(v);//czasem mona usun
		v->pra=merge(v->pra, u);
		if (v->pra!=NULL)
			v->pra->oj=v;
		update(v);
		return v;
	}
	else
	{
		update(u);//czasem mona usun
		u->lew=merge(v, u->lew);
		if (u->lew!=NULL)
			u->lew->oj=u;
		update(u);
		return u;
	}
}
pair <node *, node *> split(node * v, const function <bool(node*)> &is_left)//is_left ma stwierdza, czy dany wierzchoek powinien by w lewej czci
{
	if (v==NULL)
		return make_pair(v, v);
	pair <node *, node *> ret;
	update(v);//czasem mona usun
	v->oj=NULL;
	if (is_left(v))
	{
		ret=split(v->pra, is_left);
		v->pra=ret.first;
		if (v->pra!=NULL)
			v->pra->oj=v;
		ret.first=v;
	}
	else
	{
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
function <bool(node*)> cut_v(int v)//ucnina v pierwszych elementow
{
	gl_help=v;
	return [](node* u)->bool
	{
		int pom=1;
		if (u->lew!=NULL)
			pom+=u->lew->roz;
		if (pom>gl_help)
			return false;
		gl_help-=pom;
		return true;
	};
}
function <bool(node*)> cut_cos(int v)//ucnina v pierwszych elementow - kuamstfo
{
	gl_help=v;
	return [](node* u)->bool
	{
		update(u);
		return u->war<gl_help;
	};
}

int n;

node *korz=NULL;

int main()
{
	korz=new node();
	korz->war=0;
	scanf("%d", &n);
	for (int i=1; i<=n+3; i++)
	{
		node *tu=new node;
		korz=merge(korz, tu);
	}
	for (int i=1; i<=n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		auto jed=split(korz, cut_cos(l));
		auto dwa=split(jed.second, cut_cos(r));
		auto trz=split(dwa.second, cut_v(1));
		trz.first->narz=0;
		trz.first->war=l;
		if (dwa.first!=NULL)
			dwa.first->narz++;
		korz=merge(jed.first, merge(trz.first, merge(dwa.first, trz.second)));
	}
	auto jed=split(korz, cut_cos(inf-1));
	printf("%d\n", jed.first->roz-1);
	return 0;
}