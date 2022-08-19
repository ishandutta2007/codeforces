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
const ll mod=998244353;

int n, m;

pii prz[nax];

pii kra[nax];

ll sil[nax];
ll odw[nax];

int zly[nax];

int dos[nax];

int k;
int num[nax];
pii zak[nax][2];
pii supprz[nax];

ll chce[nax];

ll wyn;

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

ll komb(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

int wprze(int v, pii p)
{
	return p.first<=v && v<=p.second;
}

int stamas=-1;
ll stalud;

//~ int oj[nax];

//~ int fin(int v)
//~ {
	//~ if (v!=oj[v])
		//~ oj[v]=fin(oj[v]);
	//~ return oj[v];
//~ }

//~ void uni(int a, int b)
//~ {
	//~ oj[fin(a)]=fin(b);
//~ }

//~ void reset()
//~ {
	//~ for (int i=0; i<k; i++)
		//~ oj[i]=i;
//~ }

void ogarnij(int mas, ll lud)
{
	if (mas==stamas && lud==stalud)
		return;
	stamas=mas;
	stalud=lud;
	
	for (int i=0; i<=k; i++)
		chce[i]=0;
	
	int ter=mas;
	while(1)
	{
		ll mno=__builtin_popcount(ter);
		if (mno&1)
			mno=mod-1;
		else
			mno=1;
		
		ll nap=0;
		for (int i=0; i<m; i++)
		{
			if (ter&(1<<i))
			{
				nap|=(1LL<<kra[i].first);
				nap|=(1LL<<kra[i].second);
			}
		}
		
		int a=__builtin_popcountll(nap);
		int b=__builtin_popcountll(lud^nap);
		for (int i=0; i<=b; i++)
			chce[a+i]=(chce[a+i]+mno*komb(b, i))%mod;
		
		if (!ter)
			break;
		ter=(ter-1)&mas;
	}
	
	debug() << imie(mas) << imie(lud) << imie(range(chce, chce+1+k));
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[nax-1]=inv(sil[nax-1]);
	for (int i=nax-2; i>=0; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &prz[i].first, &prz[i].second);
	for (int i=0; i<m; i++)
	{
		scanf("%d%d", &kra[i].first, &kra[i].second);
		zly[kra[i].first]=zly[kra[i].second]=1;
	}
	for (int i=1; i<=n; i++)
	{
		if (zly[i])
		{
			num[i]=k;
			supprz[k]=prz[i];
			k++;
			continue;
		}
		dos[prz[i].first]++;
		dos[prz[i].second+1]--;
	}
	for (int i=0; i<m; i++)
	{
		zak[i][0]=prz[kra[i].first];
		zak[i][1]=prz[kra[i].second];
		kra[i].first=num[kra[i].first];
		kra[i].second=num[kra[i].second];
	}
	for (int i=1; i<=n; i++)
	{
		dos[i]+=dos[i-1];
		int mas=0;
		for (int j=0; j<m; j++)
			if (wprze(i, zak[j][0]) && wprze(i, zak[j][1]))
				mas|=(1<<j);
		ll mam=0;
		for (int j=0; j<k; j++)
			if (wprze(i, supprz[j]))
				mam|=(1LL<<j);
		ogarnij(mas, mam);
		for (int j=0; j<=k; j++)
			wyn=(wyn+komb(dos[i], i-j)*chce[j])%mod;
	}
	printf("%lld\n", wyn);
	return 0;
}