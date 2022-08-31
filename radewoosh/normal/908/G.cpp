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

const int nax=707;
using ll=long long;
const ll mod=1000*1000*1000+7;

int n;

char wcz[nax];

ll wyn;

ll kom[nax][nax];

ll pot[nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

//~ inline ll sum(int a, int b)
//~ {
	//~ return (pot[b]-pot[a]+mod)%mod;
//~ }

ll pam[11][nax];

ll potpam[nax][nax];
ll potlicz[nax][nax];
ll potsum[nax][nax];

void precalc()
{
	for (int i=0; i<=10; i++)
	{
		potpam[i][0]=1;
		
		potsum[i][1]=i;
		potlicz[i][1]=i;
		for (int j=1; j<=n; j++)
		{
			potpam[i][j]=(potpam[i][j-1]*i)%mod;
		}
		for (int j=2; j<=n; j++)
		{
			potlicz[i][j]=(potlicz[i][j-1]*10)%mod;
			potsum[i][j]=(potsum[i][j-1]+potlicz[i][j])%mod;
		}
		
	}
	for (int i=1; i<10; i++)
	{	
		for (int j=0; j<=n; j++)
		{
			for (int l=0; j+l<=n; l++)
			{
				if (i==1 && j+l==0)
					debug() << potpam[i][j] << " " << potpam[9-i][l] << " " << potpam[10][l];
				dod(pam[i][j+l], ((potpam[i][j]*potpam[9-i][l])%mod)*((potpam[10][l]*kom[j+l][j])%mod));
			}
		}
	}
}

inline ll f3(int cyf, int wol)
{
	debug() << cyf << " " << wol << "  " << pam[cyf][wol];
	return pam[cyf][wol];
}

inline ll f2(int cyf, int ile, int wol)
{
	//~ return pam[cyf][ile][wol];
	debug() << cyf << " " << ile << " " << wol << "   " << potsum[cyf][ile];
	return (f3(cyf, wol)*potsum[cyf][ile])%mod;
}

inline ll f(int cyf, int ile, int wol, int lew, int pra)
{
	if (!ile)
		return 0;
	//~ assert(ile+wol+lew+pra==n);
	debug() << cyf << " " << ile << " " << wol << " " << lew << " " << pra;
	return (f2(cyf, ile, wol)*potpam[10][pra])%mod;
}

void zap(vector <int> &wek, int k)
{
	debug() << wek << " " << k;
	int ile[17];
	int sile[17];
	memset(sile, 0, sizeof(sile));
	memset(ile, 0, sizeof(ile));
	for (int i : wek)
		ile[i]++;
	int m=k;
	for (int i=1; i<10; i++)
		k+=ile[i];
	//~ for (int i=1; i<=k; i++)
		//~ dod(pot[i], pot[i-1]);
		
	for (int i=1; i<10; i++)
		sile[i]=sile[i-1]+ile[i];
		
	for (int i=1; i<10; i++)
		for (int j=ile[i]; j<=ile[i]+m; j++)
			dod(wyn, kom[m][j-ile[i]]*f(i, j, ile[i]+m-j, sile[i-1]+n-k, sile[9]-sile[i]));
	debug() << "teraz " << wyn;
}

int main()
{
	for (int i=0; i<nax; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	
	precalc();
	
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<wcz[i]-'0'; j++)
		{
			vector <int> wek;
			for (int l=1; l<i; l++)
				wek.push_back(wcz[l]-'0');
			wek.push_back(j);
			zap(wek, n-i);
		}
		//~ dod(wyn, wcz[i]-'0');
	}
	
	sort(wcz+1, wcz+1+n);
	
	for (int i=1; i<=n; i++)
		dod(wyn, (wcz[i]-'0')*potpam[10][n-i]);
	
	printf("%lld\n", wyn);
	return 0;
}