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
const int nax=1007;
const int vax=nax*nax;
const ll mod=998244353;

void ff()
{
	fflush(stdout);
}

int n, k;

int poz[nax][nax];

int suma[nax];

int wszystko(vi &wek)
{
	for (int i : wek)
		if (i!=wek[0])
			return -1;
	return wek[0];
}

vector<pii> wym[nax];

//~ bitset<vax> jest[nax];

ll sup[nax];

ll kwa(ll v)
{
	return v*v;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=0; i<k; i++)
	{
		for (int j=0; j<n; j++)
			scanf("%d", &poz[i][j]);
		sort(poz[i], poz[i]+n);
		for (int j=0; j<n; j++)
		{
			suma[i]+=poz[i][j];
			sup[i]+=poz[i][j]*(ll)poz[i][j];
		}
	}
	debug() << range(suma, suma+k);
	debug() << range(sup, sup+k);
	int zly=-1;
	int powi=0;
	for (int i=0; i<k; i++)
	{
		vi wek;
		if (i==0 || i==k-1)
		{
			for (int j=1; j<k; j++)
			{
				if (j!=i && j-1!=i)
					wek.push_back(suma[j]-suma[j-1]);
			}
			int wez=wszystko(wek);
			if (wez==-1)
				continue;
			zly=i;
			powi=wez;
			break;
		}
		for (int j=1; j<k; j++)
		{
			if (j!=i && j-1!=i)
				wek.push_back(suma[j]-suma[j-1]);
		}
		int spec=suma[i+1]-suma[i-1];
		int wez=wszystko(wek);
		if (wez==-1)
			continue;
		if (wez*2!=spec)
			continue;
		zly=i;
		powi=wez;
		break;
	}
	debug() << zly << " " << powi;
	vi dob;
	for (int i=0; i<k; i++)
		if (i!=zly)
			dob.push_back(i);
	int a, b, c;
	for (int i=0; i+2<(int)dob.size(); i++)
	{
		if (dob[i]+1==dob[i+1] && dob[i]+2==dob[i+2])
		{
			a=dob[i];
			b=dob[i+1];
			c=dob[i+2];
		}
	}
	
	//~ for (int i=0; i<k; i++)
		//~ for (int j=0; j<n; j++)
			//~ jest[i][poz[i][j]]=1;
	//~ ll popr=sup[b]-sup[a]-suma[a]*powi;
	//~ debug() << imie(popr);
	ll mag=sup[c]-2*sup[b]+sup[a];
	ll dobsum=0;
	if (zly)
		dobsum=suma[zly-1]+powi;
	else
		dobsum=suma[zly+1]-powi;
	//~ assert(!(mag&1));
	//~ mag/=2;
	debug() << mag;
	int na=zly;
	int nb=zly+1;
	int nc=zly+2;
	while(nc>=k)
	{
		na--;
		nb--;
		nc--;
	}
	for (int i=0; i<n; i++)
	{
		ll brak=dobsum-suma[zly];
		ll supc=sup[nc];
		ll supb=sup[nb];
		ll supa=sup[na];
		debug() << imie(brak);
		if (zly==na)
		{
			supa=supa-kwa(poz[zly][i])+kwa(poz[zly][i]+brak);
		}
		if (zly==nb)
		{
			supb=supb-kwa(poz[zly][i])+kwa(poz[zly][i]+brak);
		}
		if (zly==nc)
		{
			supc=supc-kwa(poz[zly][i])+kwa(poz[zly][i]+brak);
		}
		if (supc-2*supb+supa==mag)
		{
			printf("%d %lld\n", zly, (ll)(poz[zly][i]+brak));
			break;
		}
	}
	/*for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			int ok=1;
			int roz=poz[b][j]-poz[a][i];
			int sta=poz[a][i]-roz*a;
			//~ debug() << i << " " << j << "  " << sta << " " << roz;
			if (roz<=0 || roz>1000)
				continue;
			for (int l=0; l<k; l++)
			{
				if (l==zly)
					continue;
				int x=sta+roz*l;
				if (x<0 || x>=vax || !jest[l][x])
				{
					ok=0;
					break;
				}
			}
			if (ok)
				wym[i].push_back({j, sta+zly*roz});
		}
		//~ debug() << i << " " << wym[i];
	}*/
	//~ for (int i=0; i<n; i++)
		//~ debug() << wym[i];
	//~ vi przed;
	//~ if (zly)
	//~ {
		//~ for (int i=0; i<n; i++)
			//~ przed.push_back(poz[zly-1][i]);
	//~ }
	//~ else
	//~ {
		//~ for (int i=0; i<n; i++)
			//~ przed.push_back(poz[zly+1][i]);
		//~ powi*=-1;
	//~ }
	//~ ll r2=0;
	//~ debug() << range(poz[zly], poz[zly]+n);
	//~ debug () << przed;
	//~ debug() << powi;
	ff();
	return 0;
}