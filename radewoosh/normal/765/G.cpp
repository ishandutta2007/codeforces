#include <bits/stdc++.h>
using namespace std;

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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=500*1007;
const long long inf=(long long)1000*1000*1000*1000*1000*1000;
const long long mod=1000*1000*1000+7;
const long long jed=1;

const int vax=1007;
const int sax=43;

int s;
char wcz[nax];
int n;

int g;

long long wej;

vector < long long > dos[vax];

long long kom[vax][vax];

pair <long long, long long> tab[nax];

long long dp[nax][sax];
long long wez[sax];

long long wyn;

long long potuj(long long a, long long b)
{
	long long ret=1;
	while(b)
	{
		if (b&1)
		{
			ret*=a;
			ret%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return ret;
}

inline int test(const long long &a, const int &b)
{
	return (a&(jed<<b))>0;
}

void dodaj(long long &a, long long b)
{
	a+=b;
	if (a>=mod)
		a-=mod;
	if (a>=mod)
		a%=mod;
}

map <long long,long long> mapa[sax];

long long licz(int v, long long mas)
{
	if (v==g)
	{
		//debug() << v << " " << mas << " : " << dp[v][];
		return wez[__builtin_popcountll(mas^wej)];
	}
	if (mapa[v].count(mas))
		return mapa[v][mas];
	long long ret=0;
	for (int i=0; i<dos[v].size(); i++)
		dodaj(ret, licz(v+1, mas|dos[v][i]));
	debug() << v << " " << mas << " : " << ret;
	mapa[v][mas]=ret;
	return ret;
}

int main()
{
	for (int i=0; i<vax; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	scanf("%s", wcz);
	s=strlen(wcz);
	for (int i=0; i<s; i++)
		if (wcz[i]=='0')
			wej|=(jed<<i);
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	sort(tab+1, tab+1+n);
	g=n+1;
	for (int i=1; i<=n; i++)
	{
		if (tab[i].first>s)
		{
			g=min(g, i);
			continue;
		}
		for (int j=0; j<tab[i].first; j++)
		{
			int ok=1;
			long long daj=0;
			for (int l=j; l<s; l+=tab[i].first)
			{
				if (!test(wej, l))
					ok=0;
				daj|=(jed<<l);
			}
			if (!ok)
				continue;
			dos[i].push_back(daj);
		}
	}
	for (int i=1; i<=n; i++)
		debug() << i << " " << dos[i];
	dp[n+1][0]=1;
	for (int i=n+1; i>g; i--)
	{
		for (int j=0; j<=s; j++)
		{
			dodaj(dp[i-1][j+1], dp[i][j]);
			dodaj(dp[i-1][j], dp[i][j]*(tab[i-1].first-s+j));
		}
		debug() << i << range(dp[i], dp[i]+1+s);
	}
	debug() << g << range(dp[g], dp[g]+1+s);
	//for (int i=s; i; i--)
	//	dodaj(dp[g][i], dp[g][i-1]);
	int og=__builtin_popcountll(wej);
	for (int i=0; i<=og; i++)
	{
		for (int j=i; j<=og; j++)
		{
			long long x=1;
			for (int l=1; l<=j; l++)
				x=(x*l)%mod;
			dodaj(wez[i], ((dp[g][j]*x)%mod)*kom[og-i][j-i]);
		}
	}
	wyn=licz(1, 0);
	for (int i=1; i<=n; i++)
		wyn=(wyn*potuj(tab[i].first, tab[i].second-1))%mod;
	printf("%lld\n", wyn);
	return 0;
}