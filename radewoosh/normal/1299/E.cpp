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
//~ const ll mod=1000*1000*1000+7;

void eukl(ll &x, ll &y, ll a, ll b) {
	if (!a) { x = 0; y = 1; return; }
	eukl(y, x, b % a, a);
	x -= y * (b / a);
}
ll mno(ll a, ll b, ll mod) { // a moze byc ujemne
	return ((ll)a*b)%mod;
}
pll crt2(ll p, ll a, ll q, ll b) {
	if (a==-1)
		return {-1, -1};     // Zarwno wynik, jak i argumenty s
	ll x, y;                 // postaci x = first (mod second).
	eukl(x, y, a, b);        // Jeli kongruencja jest niespenialna
	ll nwd=x*a+y*b;          // to zwraca (-1, -1).
	if ((p%nwd)!=(q%nwd))
		return {-1, -1};
	a/=nwd; b/=nwd;
	ll nww=a*b;
	ll ret=mno(x*a, q/nwd, nww)+mno(y*b, p/nwd, nww);
	if ((ret%=nww)<0) ret+=nww;
	return {ret*nwd+(p%nwd), nww*nwd};
}
pll crt(vector <pll> wek) {
	pll ret={0, 1};
	for (auto i : wek)
		ret=crt2(ret.first, ret.second, i.first, i.second);
	return ret;
}


void ff()
{
	fflush(stdout);
}

int n;

//~ int fake[nax];

//~ void init(int v)
//~ {
	//~ for (int i=1; i<=v; i++)
		//~ fake[i]=i;
	//~ reverse(fake+1, fake+1+n);
	//~ while(fake[1]>v/2)
		//~ shandom_ruffle(fake+1, fake+1+n);
	//~ debug() << range(fake+1, fake+1+n);
//~ }

int licz=0;

int pyt(vi wek)
{
	licz++;
	assert(licz<=18*n);
	printf("? %d", (int)wek.size());
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	int x;
	scanf("%d", &x);
	return x;
	//~ int w=0;
	//~ for (int i : wek)
		//~ w+=fake[i];
	//~ return !(w%wek.size());
}

void ans(vi wek)
{
	if (wek[0]>n/2)
		for (int &i : wek)
			i=n+1-i;
	printf("!");
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	exit(0);
}

vi wyjmij(vi wek, int v)
{
	for (int &i : wek)
	{
		if (i==v)
		{
			swap(i, wek.back());
			wek.pop_back();
			return wek;
		}
	}
	assert(0);
}

int main()
{
	srand(time(0));
	scanf("%d", &n);
	//~ init(n);
	const int k=min(8, n/2);
	vi parz, nparz;
	parz.push_back(1);
	for (int i=2; i<n; i++)
	{
		if (pyt({1, i}))
			parz.push_back(i);
		else
			nparz.push_back(i);
	}
	if (parz.size()<nparz.size())
		parz.push_back(n);
	else
		nparz.push_back(n);
	//~ debug() << imie(parz);
	//~ debug() << imie(nparz);
	vi ros, mal;
	for (int h=1; h<=k; h++)
	{
		shandom_ruffle(parz.begin(), parz.end());
		shandom_ruffle(nparz.begin(), nparz.end());
		vi wsz;
		for (int i : parz)
			wsz.push_back(i);
		for (int i : nparz)
			wsz.push_back(i);
		for (int &i : nparz)
		{
			if (i==nparz.back() || pyt(wyjmij(wsz, i)))
			{
				ros.push_back(i);
				swap(i, nparz.back());
				nparz.pop_back();
				break;
			}
		}
		for (int &i : parz)
		{
			if (i==parz.back() || pyt(wyjmij(wsz, i)))
			{
				mal.push_back(i);
				swap(i, parz.back());
				parz.pop_back();
				break;
			}
		}
		
		
		swap(parz, nparz);
	}
	//~ debug() << imie(ros);
	//~ debug() << imie(mal);
	vi odp(n);
	for (int i=0; i<k; i++)
		odp[ros[i]-1]=i+1;
	for (int i=0; i<k; i++)
		odp[mal[i]-1]=n-i;
	//~ debug() << imie(odp);
	
	if (2*k==n)
		ans(odp);
	
	vector <vi> weks;
	weks.push_back({3, 5, 8});
	weks.push_back({3, 5, 7, 2});
	weks.push_back({3, 5, 7, 4});
	weks.push_back({3, 5, 7, 8});
	
	vi chce;
	for (vi i : weks)
	{
		int mno=1;
		for (int j : i)
			mno*=j;
		if (mno>n)
		{
			chce=i;
			break;
		}
	}
	
	//~ vi chce{3, 5, 7, 8};
	
	for (vi hh : {parz, nparz})
	{
		for (int i : hh)
		{
			vector <pll> daj;
			for (int r : chce)
			{
				vector <pii> wych;
				for (int w=0; w<r; w++)
				{
					vi wez{i};
					int jest=0;
					for (int j=0; j<r; j++)
					{
						if (j!=w)
						{
							wez.push_back(ros[j]);
							jest=(jest+j+1)%r;
						}
					}
					int brak=(r-jest)%r;
					wych.push_back({brak, w});
				}
				//~ sort(wych.begin(), wych.end());
				shandom_ruffle(wych.begin(), wych.end());
				//~ for (int w=0; w<r; w++)
				for (int h=0; h<r; h++)
				{
					int w=wych[h].second;
					vi wez{i};
					int jest=0;
					for (int j=0; j<r; j++)
					{
						if (j!=w)
						{
							wez.push_back(ros[j]);
							jest=(jest+j+1)%r;
						}
					}
					int brak=(r-jest)%r;
					if (h+1==r || pyt(wez))
					{
						daj.push_back({brak, r});
						break;
					}
				}
			}
			odp[i-1]=crt(daj).first;
		}
	}
	ans(odp);
	return 0;
}