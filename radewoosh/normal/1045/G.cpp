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


using ll=int;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=100*1007;
const int inf=2*1000*1000*1007;

int n, k;

map <ll,vector <pll> > mapa;

long long wyn;

int drz[nax];

map <int,int> ska;
unordered_map <int,int> ska_fast, ska_fast_lb;

inline void pisz(const int &v, const int &w)
{
	for (int i=v; i<=n+7; i+=((-i)&i))
		drz[i]+=w;
}

inline void czys(const int &v)
{
	for (int i=v; i<=n+7; i+=((-i)&i))
		drz[i]=0;
}

inline int czyt(const int &v)
{
	int ret=0;
	for (int i=v; i; i-=((-i)&i))
		ret+=drz[i];
	return ret;
}
	
pll lew[nax], pra[nax];

long long self(const vector <pll> &wek)
{
	//~ sort(wek.begin(), wek.end());
	int m=wek.size();
	long long ret=m*(m-1LL)/2;
	for (int i=0; i<m; i++)
	{
		int bsa=0;
		int bsb=i;
		int bss;
		ll lim=wek[i].first-wek[i].second;
		while(bsa<bsb)
		{
			bss=(bsa+bsb)>>1;
			if (lim<=wek[bss].first)
				bsb=bss;
			else
				bsa=bss+1;
		}
		ret-=(i-bsa);
		
		bsa=i;
		bsb=m-1;
		lim=wek[i].first+wek[i].second;
		while(bsa<bsb)
		{
			bss=(bsa+bsb+2)>>1;
			if (lim>=wek[bss].first)
				bsa=bss;
			else
				bsb=bss-1;
		}
		ret-=(bsa-i);
	}
	int num=0;
	for (const pll &i: wek)
	{
		lew[num]={i.first, i.first+i.second};
		pra[num]={i.first-i.second, i.first};
		num++;
	}
	sort(lew, lew+m);
	sort(pra, pra+m);
	int w=0;
	for (int j=0; j<m; j++)
	{
		const pll i=pra[j];
		while(w<m && lew[w].first<i.first)
		{
			pisz(ska_fast[lew[w].second], 1);
			w++;
		}
		ret-=czyt(ska_fast_lb[i.second]);
	}
	for (int i=0; i<w; i++)
		czys(ska_fast[lew[i].second]);
	
	return -ret;
}

int main()
{
	//~ ska_fast.reserve(1<<21);
	//~ ska_fast_lb.reserve(1<<21);
	
	scanf("%d%d", &n, &k);
	//~ n=1e5;
	//~ k=20;
	vi zbi;
	for (int i=1; i<=n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		//~ a=rand()%1000000;
		//~ b=rand()%1000000;
		//~ c=rand()%100;
		ska[a+b]=0;
		mapa[c].push_back({a, b});
		zbi.push_back(a);
	}
	ska[-inf]=0;
	ska[inf]=0;
	int num=0;
	for (auto i : ska)
	{
		num++;
		ska[i.first]=num;
		ska_fast[i.first]=num;
	}
	for (int i : zbi)
	{
		auto it=ska.lower_bound(i);
		it--;
		ska_fast_lb[i]=it->second;
	}
	vector <pll> ter, pot;
	for (auto i : mapa)
	{
		pot.clear();
		ter=i.second;
		auto j=mapa.find(i.first);
		while(1)
		{
			j++;
			if (j==mapa.end() || j->first-i.first>k)
				break;
			pot.resize(pot.size()+j->second.size());
			for (int l=0; l<(int)j->second.size(); l++)
				pot[(int)pot.size()-1-l]=j->second[l];
			//~ for (auto l : j->second)
				//~ pot.push_back(l);
		}
		//~ debug() << ter << " " << pot;
		//~ wyn+=-biny(ter, pot);
		ter.resize(ter.size()+pot.size());
		for (int j=0; j<(int)pot.size(); j++)
			ter[ter.size()-1-j]=pot[j];
		sort(ter.begin(), ter.end());
		sort(pot.begin(), pot.end());
		wyn+=self(ter)-self(pot);
	}
	printf("%lld\n", wyn);
	return 0;
}