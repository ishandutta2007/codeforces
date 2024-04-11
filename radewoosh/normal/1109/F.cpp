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
const int vax=1007;
const int nax=200*1007;
const int kax=1000*1007;
const int n1=(1<<18);

struct Value
{
	void touch(Value * left, Value * right) { }
	void update(Value * left, Value * right) { }
};

struct Splay : Value
{
	Splay *l, *r, *p;
	bool flip;

	template<typename ...Args>
	Splay(const Args & ...args)
		: Value(args...)
		,l(nullptr) ,r(nullptr) ,p(nullptr)
		,flip(false)
	{
	}

  // Sprawdza, czy wierzchoek jest rootem splejowym.
  // Aby sprawdzi, czy wierzchoek jest rootem drzewa, trzeba napisa:
  // if (v == v->root()) { ... }
	bool isRoot()
	{
		return !p || (p->l != this && p->r != this);
	}

	void touch()
	{
		if(flip)
		{
			swap(l, r);
			if(l) l->flip = !l->flip;
			if(r) r->flip = !r->flip;
			flip = false;
		}
		Value::touch(l, r);
	}

	void update()
	{
		Value::update(l, r);
	}

	static void connect(Splay * p, Splay * c, bool left)
	{
		(left ? p->l : p->r) = c;
		if(c) c->p = p;
	}

	/* Zakada, e nie jest ,,rootem'' */
	void rotate()
	{
		Splay * f = p;
		Splay * t = f->p;
		f->touch();
		touch();
		bool isr = f->isRoot();
		bool left = (this == f->l);
		connect(f, left ? r : l, left);
		connect(this, f, !left);
		if(isr) this->p = t;
		else connect(t, this, f == t->l);
		if(f->r) f->r->touch();
		if(f->l) f->l->touch();
		f->update();
	}

	void splay()
	{
		while(!isRoot())
		{
			Splay * r = p->p;
			if(!p->isRoot()) (((p->l == this) == (r->l == p)) ? p : this)->rotate();
			rotate();
		}
		touch();
		if(l) l->touch();
		if(r) r->touch();
		update();
	}

	/* Podnosi wierzchoek do gry (bdzie korzeniem splaya, w ktrym znajduje si korze drzewa :P). */
	static Splay * lastDisc;
	void expose()
	{
		Splay * r = nullptr;
		lastDisc = nullptr;
		for(Splay * q = this; q; q = q->p)
		{
			q->splay();
			q->r = r;
			q->update();
			r = q;
			lastDisc = q;
		}
		splay();
	}

	void link(Splay * to)
	{
		expose();
		assert(l == nullptr); // to powinien by root
		p = to;
	}

	Splay * root()
	{
		expose();
		Splay * s = this;
		while(s->l)
		{
			s = s->l;
			s->touch();
		}
		s->splay();
		return s;
	}

	/* Wywoaj funkcj f na poddrzwie reprezentujcym ciek od korzenia do wierzchoka. */
	void applyF(std::function<void(Splay*)> f)
	{
		expose();
		if(r == nullptr) f(this);
		else
		{
			Splay * s = r;
			while(s->l)
			{
				s = s->l;
				s->touch();
			}
			s->splay();
			f(s->l);
		}
	}

	/* Sprawia, e wierzchoek jest rootem w swoim drzewie. */
	void makeRoot()
	{
		applyF([] (Splay * s) {
			s->flip = !s->flip;
		});
	}

	/* Zakada, e (*this) nie jest korzeniem drzewa.
	 * Usuwa krawd znajdujc si nad danym wierzchokiem. */
	void cut()
	{
		expose();
		assert(l != nullptr); // jest rootem, nie mona obci...
		Splay * s = l;
		while(s->r) s = s->r;
		s->splay();
		s->r->p = nullptr;
		s->r = nullptr;
	}

	/* Zwraca lca(this, v) */
	Splay * lca(Splay * v)
	{
		expose();
		v->expose();
		return lastDisc;
	}

};

Splay * Splay::lastDisc;

/* Wywoaj funkcj f na poddrzewie reprezentujcym ciek od a do b.
 * UWAGA! zmienia korze drzewa.
 * Jeli jest to niepodane, po wywoaniu funkcji naley zrobi makeRoot() na starym roocie. */
void applyF(Splay * a, Splay * b, std::function<void(Splay*)> f)
{
	a->makeRoot();
	b->applyF(f);
}

int nast = 0;
Splay spleje[nax];

template<typename ...Args>
Splay * newTree(const Args & ...args)
{
	return &spleje[nast++];
	//return new Splay(args...);
}

void deleteTree(Splay * t)
{
	if(t->l) deleteTree(t->l);
	if(t->r) deleteTree(t->r);
	delete t;
}

int n, m, k;
int tab[vax][vax];
pii gdz[nax];

int najd[nax];

int rx[]={1, -1, 0, 0};
int ry[]={0, 0, 1, -1};

vi kra[nax];

void edge(int a, int b)
{
	if (a>b)
		swap(a, b);
	kra[a].push_back(b);
	kra[b].push_back(a);
}

int razem(int a, int b)
{
	return (spleje[a].root()==spleje[b].root());
}

int lacz(int a, int b)
{
	//~ debug() << "lacze " << a << " " << b;
	spleje[a].expose();
	spleje[b].expose();
	spleje[a].makeRoot();
	spleje[a].link(&spleje[b]);
	//~ debug() << "ok";
}

int tnij(int a, int b)
{
	//~ debug() << "tne " << a << " " << b;
	spleje[a].expose();
	spleje[a].makeRoot();
	spleje[b].cut();
	//~ debug() << "ok";
}

int moge(vector <pii> wek)
{
	for (int i=0; i<(int)wek.size(); i++)
	{
		int a=wek[i].first;
		int b=wek[i].second;
		if (razem(a, b))
		{
			for (int j=0; j<i; j++)
				tnij(wek[j].first, wek[j].second);
			return 0;
		}
		lacz(a, b);
	}
	return 1;
}

pii drz[kax];
int dod[kax];

pii daj(int v)
{
	return {drz[v].first+dod[v], drz[v].second};
}

pii inf{-1e9, 0};

ll wyn;

pii lacz(pii a, pii b)
{
	if (a.first==b.first)
		return {a.first, a.second+b.second};
	return max(a, b);
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (v==1)
		debug() << graa << " " << grab << " " << w;
	if (a>=graa && b<=grab)
	{
		dod[v]+=w;
		return;
	}
	if (a>grab || b<graa)
		return;
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	drz[v]=lacz(daj(v*2), daj(v*2+1));
}

pii czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return daj(v);
	}
	if (a>grab || b<graa)
		return inf;
	pii r1=czyt((v<<1), a, (a+b)>>1, graa, grab);
	pii r2=czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
	pii r=lacz(r1, r2);
	r.first+=dod[v];
	return r;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			scanf("%d", &tab[i][j]);
			gdz[tab[i][j]]={i, j};
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (j<m)
				edge(tab[i][j], tab[i][j+1]);
			if (i<n)
				edge(tab[i][j], tab[i+1][j]);
		}
	}
	k=n*m;
	int w=1;
	for (int i=1; i<=k; i++)
	{
		w=max(w, i);
		while(w<k)
		{
			vector <pii> wek;
			for (int j : kra[w+1])
				if (j>=i && j<=w)
					wek.push_back({w+1, j});
			if (moge(wek))
				w++;
			else
				break;
		}
		najd[i]=w;
			for (int j : kra[i])
				if (j>=i && j<=w)
					tnij(i, j);
		debug() << i << " " << najd[i];
	}
	debug() << range(najd+1, najd+1+k);
	
	for (int i=1; i<=n1; i++)
		drz[i+n1-1].second++;
	for (int i=n1-1; i; i--)
		drz[i]=lacz(drz[i*2], drz[i*2+1]);
	
	debug() << "Tak";
	
	for (int i=k; i; i--)
	{
		debug() << i;
		pisz(1, 1, n1, i+1, k, -1);
		for (int j : kra[i])
			if (j>i)
				pisz(1, 1, n1, j, k, 1);
		pii wez=czyt(1, 1, n1, i, najd[i]);
		//~ debug() << imie(czyt(1, 1, n1, 4, 4));
		//~ debug() << wez;
		if (wez.first==0)
			wyn+=wez.second;
	}
	
	
	
	printf("%lld\n", wyn);
	return 0;
}