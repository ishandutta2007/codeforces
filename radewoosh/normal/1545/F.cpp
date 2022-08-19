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
const int d=150;

int n, q;

int a[nax];
int b[nax];
int c[nax];

struct info
{
	vll wek;//a, b, c, ab, bc, abc
	info()
	{
		wek.resize(6);
	}
	void zeruj()
	{
		fill(wek.begin(), wek.end(), 0);
	}
	ll &operator[](int v)
	{
		return wek[v];
	}
	const ll &operator[](int v) const
	{
		return wek[v];
	}
};

info operator *(const info &a, const info &b)
{
	info ret=info();
	ret[0]=a[0]+b[0];
	ret[1]=a[1]+b[1];
	ret[2]=a[2]+b[2];
	ret[3]=a[3]+b[3]+a[0]*b[1];
	ret[4]=a[4]+b[4]+a[1]*b[2];
	ret[5]=a[5]+b[5]+a[0]*b[4]+a[3]*b[2];
	return ret;
}

struct drz
{
	vector<info> nor, blok, pref, blokpref;
	static const int dk=256;
	static const int dn=dk-1;
	static const int sz=8;
	int pr=0;
	drz()
	{
		
	}
	drz(int r)
	{
		nor.resize(r+dk+7);
		blok.resize(r/dk+7);
		pref.resize(r+dk+7);
		blokpref.resize(r/dk+7);
		pr=r;
	}
	void change(int v, info w)
	{
		nor[v]=w;
		int g=v>>sz;
		pref[(g<<sz)]=nor[(g<<sz)];
		for (int i=max((g<<sz)+1, v); i<(g<<sz)+dk; i++)
			pref[i]=pref[i-1]*nor[i];
		blok[g]=pref[(g<<sz)+dn];
		int a=dn;
		if (!g)
			blokpref[a>>sz]=blok[a>>sz];
		a+=dk;
		while(a<(int)nor.size())
		{
			if (a+dk*3>v)
				blokpref[a>>sz]=blokpref[(a>>sz)-1]*blok[a>>sz];
			a+=dk;
		}
	}
	void init()
	{
		for (int i=0; i<=pr; i++)
		{
			if (i&dn)
				pref[i]=pref[i-1]*nor[i];
			else
				pref[i]=nor[i];
		}
		for (int i=dn; i<pr; i+=dk)
			blok[i>>sz]=pref[i];
		int a=dn;
		blokpref[a>>sz]=blok[a>>sz];
		a+=dk;
		while(a<(int)nor.size())
		{
			blokpref[a>>sz]=blokpref[(a>>sz)-1]*blok[a>>sz];
			a+=dk;
		}
	}
	void small_change(int v, info w)
	{
		nor[v]=w;
	}
	ll czyt(int v)
	{
		info ret=info();
		if (v>>sz)
			ret=blokpref[(v>>sz)-1];
		ret=ret*pref[v];
		return ret[5];
	}
};

vi wystapi[nax];

vi zap[nax];

pii moc[nax];

vi spec;
int czyspec[nax];

drz specdrz[d+1];
vi ktomoze[nax];

ll glofen[nax];

void pisz(int v, ll w)
{
	for (int i=v; i<nax; i+=(i&(-i)))
		glofen[i]+=w;
}

ll czyt(int v)
{
	ll ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=glofen[i];
	return ret;
}


struct cipka
{
	const int dk=512;
	const int dn=dk-1;
	const int sz=9;
	vll nor;
	vll blok;
	cipka()
	{
		nor.resize(nax);
		blok.resize(nax);
	}
	void pisz(int v, ll w)
	{
		nor[v]+=w;
		blok[v>>sz]+=w;
	}
	ll czyt(int v)
	{
		ll ret=0;
		while(v&dn)
		{
			ret+=nor[v];
			v--;
		}
		ret+=nor[v];
		v/=dk;
		for (int i=0; i<v; i++)
			ret+=blok[i];
		return ret;
	}
};

cipka chuj;

ll znajdz(int v)
{
	//~ debug() << "pytam " << v;
	ll ret=chuj.czyt(v);
	for (int i : spec)
	{
		int x=upper_bound(ktomoze[i].begin(), ktomoze[i].end(), v)-ktomoze[i].begin();
		//~ debug() << i << " " << specdrz[czyspec[i]].czyt(x);
		ret+=specdrz[czyspec[i]].czyt(x);
	}
	return ret;
}

void normuj(vi &wek)
{
	sort(wek.begin(), wek.end());
	wek.resize(unique(wek.begin(), wek.end())-wek.begin());
}

int miejsce(int v, int g)
{
	return lower_bound(ktomoze[v].begin(), ktomoze[v].end(), g)-ktomoze[v].begin()+1;
}

void akcja(int v, int mno, int g)
{
	if (czyspec[v])
	{
		if (mno==-1)
		{
			//~ specdrz[czyspec[v]].change(miejsce(v, g), info());
		}
		else
		{
			info tu=info();
			if (b[a[g]]==v)
				tu[0]=1;
			if (a[g]==v)
				tu[1]=1;
			if (c[a[g]]==v)
				tu[2]=1;
			specdrz[czyspec[v]].change(miejsce(v, g), tu);
		}
	}
	else
	{
		ll x=0;
		ll y=0;
		for (int j : ktomoze[v])
		{
			if (c[a[j]]==v)
				chuj.pisz(j, mno*y);
			if (a[j]==v)
				y+=x;
			if (b[a[j]]==v)
				x++;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &c[i]);
	for (int i=1; i<=n; i++)
		wystapi[i]={a[i], b[a[i]], c[a[i]]};
	for (int i=1; i<=q; i++)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			zap[i]={typ, x, y};
			wystapi[x].push_back(y);
			wystapi[x].push_back(b[y]);
			wystapi[x].push_back(c[y]);
		}
		else
		{
			int x;
			scanf("%d", &x);
			zap[i]={typ, x};
		}
	}
	for (int i=1; i<=n; i++)
	{
		sort(wystapi[i].begin(), wystapi[i].end());
		wystapi[i].resize(unique(wystapi[i].begin(), wystapi[i].end())-wystapi[i].begin());
		for (int j : wystapi[i])
		{
			moc[j].first++;
			ktomoze[j].push_back(i);
		}
	}
	for (int i=1; i<=n; i++)
		moc[i].second=i;
	sort(moc+1, moc+1+n);
	reverse(moc+1, moc+1+n);
	for (int i=1; i<=n && i<=d; i++)
		spec.push_back(moc[i].second);
	for (int i=1; i<=(int)spec.size(); i++)
	{
		czyspec[spec[i-1]]=i;
		specdrz[i]=drz(ktomoze[spec[i-1]].size());
	}
	for (int i=1; i<=n; i++)
	{
		if (czyspec[i])
			continue;
		ll x=0;
		ll y=0;
		for (int j : ktomoze[i])
		{
			if (c[a[j]]==i)
				chuj.pisz(j, y);
			if (a[j]==i)
				y+=x;
			if (b[a[j]]==i)
				x++;
		}
	}
	for (int i : spec)
	{
		int g=czyspec[i];
		for (int j=0; j<(int)ktomoze[i].size(); j++)
		{
			info tu;
			int x=ktomoze[i][j];
			if (c[a[x]]==i)
				tu[2]=1;
			if (a[x]==i)
				tu[1]=1;
			if (b[a[x]]==i)
				tu[0]=1;
			specdrz[g].small_change(j+1, tu);
		}
		specdrz[g].init();
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << znajdz(i);
	for (int h=1; h<=q; h++)
	{
		if (zap[h][0]==1)
		{
			int k=zap[h][1];
			int x=zap[h][2];
			vi sta{a[k], b[a[k]], c[a[k]], x, b[x], c[x]};
			normuj(sta);
			for (int i : sta)
				akcja(i, -1, k);
			a[k]=x;
			for (int i : sta)
				akcja(i, 1, k);
		}
		else
		{
			int r=zap[h][1];
			printf("%lld\n", znajdz(r));
		}
	}
	//~ debug() << range(moc+1, moc+1+n);
	//~ debug() << spec;
	return 0;
}