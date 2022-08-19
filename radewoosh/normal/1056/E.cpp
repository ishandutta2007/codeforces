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
const ll mod=1000*1000*1000+7;
ll h;

int n, m;

char wzo[nax];
char tek[nax];

int tab[nax];

ll pot[nax];
ll hasz[nax];

int wyn;

int pri(int v)
{
	for (int i=2; i*i<=v; i++)
		if (!(v%i))
			return 0;
	return 1;
}

ll daj(int a, int b)
{
	a--;
	ll ret=hasz[b]-hasz[a]*pot[b-a];
	ret%=mod;
	if (ret<0)
		ret+=mod;
	return ret;
}

int mam[2];
ll usta[2];

int poloz(int h, ll w)
{
	if (usta[h]==-1)
		usta[h]=w;
	return (usta[h]==w);
}

int main()
{
	srand(time(0));
	h=100*1000+3+(rand()%10000);
	while(!pri(h))
		h=100*1000+3+(rand()%10000);
	
	
	scanf("%s", wzo+1);
	scanf("%s", tek+1);
	n=strlen(wzo+1);
	m=strlen(tek+1);
	
	pot[0]=1;
	for (int i=1; i<=m; i++)
	{
		pot[i]=(pot[i-1]*h)%mod;
		hasz[i]=(hasz[i-1]*h+(tek[i]-'a'+1))%mod;
	}
	for (int i=1; i<=n; i++)
		tab[i]=wzo[i]-'0';
	for (int i=1; i<=n; i++)
		mam[tab[i]]++;
	for (int i=1; i*mam[0]<=m; i++)
	{
		int j=m-i*mam[0];
		if (j%mam[1])
			continue;
		j/=mam[1];
		if (!i || !j)
			continue;
		usta[0]=usta[1]=-1;
		int dlu[]={i, j};
		int w=0;
		int czy=1;
		for (int l=1; l<=n; l++)
		{
			ll ter=daj(w+1, w+dlu[tab[l]]);
			if (!poloz(tab[l], ter))
			{
				czy=0;
				break;
			}
			w+=dlu[tab[l]];
		}
		if (usta[0]==usta[1])
			czy=0;
		wyn+=czy;
	}
	
	printf("%d\n", wyn);
	return 0;
}