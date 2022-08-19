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
const int n1=(1<<18);

int n, m;

int per[nax];

pii cie[nax];

vi drz[nax];

int ktlisc[nax];
int korz;
int gdz[nax];

ordered_set<int> zbi[400*1007];
ll inve[nax];
int ojc[nax];

ll wyn;

pii czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return cie[v];
	}
	if (a>grab || b<graa)
	{
		return {nax, 0};
	}
	return min(
		czyt((v<<1), a, (a+b)>>1, graa, grab),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

int rek(int a, int b)
{
	m++;
	int v=m;
	if (a==b)
	{
		ktlisc[v]=a;
		gdz[a]=v;
		return v;
	}
	int g=czyt(1, 1, n1, a, b-1).second;
	int x=rek(a, g);
	int y=rek(g+1, b);
	drz[v]={x, y};
	return v;
}

void ogar(int v, ll znak)
{
	int a=drz[v][0];
	int b=drz[v][1];
	ll ra=zbi[a].size();
	ll rb=zbi[b].size();
	//~ debug() << imie(ra) << imie(rb) << imie(inve[v]);
	wyn+=znak*min(inve[v], ra*rb-inve[v]);
}

void init(int i)
{
	if (ktlisc[i])
	{
		zbi[i].insert(per[ktlisc[i]]);
		return;
	}
	int a=drz[i][0];
	int b=drz[i][1];
	ojc[a]=ojc[b]=i;
	for (int j : zbi[a])
		inve[i]+=zbi[b].order_of_key(j);
	ogar(i, 1);
	zbi[i]=zbi[a];
	for (int j : zbi[b])
		zbi[i].insert(j);
}

vi dajsc(int v)
{
	vi ret;
	while(v)
	{
		ret.push_back(v);
		v=ojc[v];
	}
	return ret;
}

void jeden(const vi &wek, int sta, int now)
{
	for (int i=1; i<(int)wek.size(); i++)
	{
		int v=wek[i];
		ogar(v, -1);
		if (drz[v][0]==wek[i-1])
		{
			inve[v]-=zbi[drz[v][1]].order_of_key(sta);
			inve[v]+=zbi[drz[v][1]].order_of_key(now);
		}
		else
		{
			int roz=drz[v][0];
			inve[v]-=roz-(int)zbi[drz[v][0]].order_of_key(sta);
			inve[v]+=roz-(int)zbi[drz[v][0]].order_of_key(now);
		}
		ogar(v, 1);
		//~ debug() << v << " ma teraz " << inve[v];
	}
}

void query()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a==b)
		return;
	if (a>b)
		swap(a, b);
	vi raz=dajsc(gdz[a]);
	vi dwa=dajsc(gdz[b]);
	//~ debug() << raz << " " << dwa;
	int wsp=-1;
	while(raz.back()==dwa.back())
	{
		wsp=raz.back();
		raz.pop_back();
		dwa.pop_back();
	}
	assert(wsp>0);
	int wara=per[a];
	int warb=per[b];
	swap(per[a], per[b]);
	jeden(raz, wara, warb);
	jeden(dwa, warb, wara);
	int ka=raz.back();
	int kb=dwa.back();
	ogar(wsp, -1);
	//~ debug() << wsp << " mialo " << inve[wsp];
	zbi[ka].erase(wara);
	zbi[kb].erase(warb);
	
	inve[wsp]-=(int)zbi[kb].order_of_key(wara);
	inve[wsp]+=(int)zbi[ka].size()-(int)zbi[ka].order_of_key(wara);
	
	inve[wsp]-=(int)zbi[ka].size()-(int)zbi[ka].order_of_key(warb);
	inve[wsp]+=(int)zbi[kb].order_of_key(warb);
	if (wara<warb)
		inve[wsp]++;
	else
		inve[wsp]--;
	//~ debug() << wsp << " ma " << inve[wsp];
	
	
	for (int i : raz)
	{
		zbi[i].erase(wara);
		zbi[i].insert(warb);
	}
	for (int i : dwa)
	{
		zbi[i].erase(warb);
		zbi[i].insert(wara);
	}
	ogar(wsp, 1);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	for (int i=1; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		cie[n1-1+i]={x, i};
	}
	for (int i=n1-1; i; i--)
		cie[i]=min(cie[2*i], cie[2*i+1]);
	korz=rek(1, n);
	assert(korz==1);
	assert(m==n-1+n);
	//~ for (int i=1; i<=m; i++)
		//~ debug() << i << " " << ktlisc[i] << " " << drz[i];
	for (int i=m; i; i--)
		init(i);
	debug() << imie(wyn);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		query();
		printf("%lld\n", wyn);
	}
	return 0;
}