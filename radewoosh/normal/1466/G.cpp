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
const int nax=2000*1007;
const ll mod=1000*1000*1000+7;
ll ha;
const int alfa=26;

int n, q;

char wcz[nax];
char lit[nax];
vector<char> slo[nax];
int d;

vector<char> dod(vector<char> a, vector<char> b)
{
	for (char i : b)
		a.push_back(i);
	return a;
}

vector<char> dod(vector<char> a, char b)
{
	a.push_back(b);
	return a;
}

int licz[1000*107][alfa];

ll wyn;

int lew[nax];
int pra[nax];

ll p2[nax];

char pocz(int v)
{
	return slo[d][v-1];
}

char kon(int v)
{
	return slo[d][(int)slo[d].size()-v];
}

void query()
{
	wyn=0;
	int k;
	scanf("%d", &k);
	scanf("%s", wcz+1);
	int r=strlen(wcz+1);
	
	lew[0]=pra[0]=1;
	{
		ll a=0;
		ll b=0;
		ll mno=1;
		for (int i=1; i<=r; i++)
		{
			a=(a*ha+wcz[i])%mod;
			b=(b+kon(i)*mno)%mod;
			mno=(mno*ha)%mod;
			lew[i]=(a==b);
		}
	}
	{
		ll a=0;
		ll b=0;
		ll mno=1;
		for (int i=1; i<=r; i++)
		{
			a=(a*ha+wcz[r+1-i])%mod;
			b=(b+pocz(i)*mno)%mod;
			mno=(mno*ha)%mod;
			pra[i]=(a==b);
		}
	}
	//~ debug() << range(lew, lew+1+r) << range(pra, pra+1+r) << slo[d];
	for (int i=1; i<=r; i++)
	{
		if (!lew[i-1] || !pra[r-i])
			continue;
		ll mno=licz[k][wcz[i]-'a'];
		for (int j=1; j<=min(d, k); j++)
			if (lit[j]==wcz[i] && (int)slo[j-1].size()>=i-1 && (int)slo[j-1].size()>=r-i)
				mno=(mno+p2[k-j])%mod;
		wyn=(wyn+mno)%mod;
	}
	if ((int)slo[0].size()>=r)
	{
		ll a=0;
		ll b=0;
		ll mno=1;
		for (int i=1; i<=r; i++)
		{
			a=(a*ha+wcz[i])%mod;
			b=(b*ha+slo[0][i-1])%mod;
			mno=(mno*ha)%mod;
		}
		ll ile=0;
		if (a==b)
			ile++;
		int r0=slo[0].size();
		for (int i=r+1; i<=r0; i++)
		{
			b=(b*ha+slo[0][i-1])%mod;
			b=(b-slo[0][i-(r+1)]*mno)%mod;
			b%=mod;
			b+=mod;
			b%=mod;
			ile+=(a==b);
		}
		wyn=(wyn+ile*p2[k])%mod;
	}
	
	
	
	printf("%lld\n", wyn);
}

int pierwsza(ll ha)
{
	for (int i=2; i*i<=ha; i++)
		if (!(ha%i))
			return 0;
	return 1;
}

int main()
{
	srand(time(0));
	ha=4;
	while(!pierwsza(ha))
		ha=1000000+rand()%1000000;
	debug() << imie(ha);
	p2[0]=1;
	for (int i=1; i<nax; i++)
		p2[i]=(p2[i-1]*2)%mod;
	scanf("%d%d", &n, &q);
	scanf("%s", wcz+1);
	scanf("%s", lit+1);
	for (int i=1; wcz[i]; i++)
		slo[0].push_back(wcz[i]);
	for (int i=1; i<=n; i++)
	{
		if (2*(int)slo[i-1].size()+1<nax)
		{
			slo[i]=dod(dod(slo[i-1], lit[i]), slo[i-1]);
			d++;
		}
		else
		{
			break;
		}
	}
	//~ d=1;
	//~ debug() << slo[4];
	//~ debug() << imie(d);
	for (int i=d+1; i<=n; i++)
	{
		for (int j=0; j<alfa; j++)
			licz[i][j]=(licz[i-1][j]*2)%mod;
		int c=lit[i]-'a';
		licz[i][c]=(licz[i][c]+1)%mod;
	}
	while(q--)
		query();
	return 0;
}