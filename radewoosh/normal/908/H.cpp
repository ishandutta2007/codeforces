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

void ans(int v)
{
	printf("%d\n", v);
	exit(0);
}

const int nax=50;
const int vax=(1<<23);
long long mod;

char wcz[nax];

int n;
int typ[nax][nax];

int oj[nax];
int saj[nax];

int fin(int v)
{
	if (oj[v]!=v)
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int v, int u)
{
	oj[fin(v)]=fin(u);
}

int k;
int num[nax];
int roz[nax];

int zak[nax][nax];
int maszak[nax];

int zab[vax];

long long sta[vax];
long long mno[vax];

int parz[vax];

int check_end()
{
	long long ret=0;
	
	for (int i=0; i<(1<<k); i++)
		ret+=parz[i]*mno[i];
	
	return (ret%mod);
}

void magjuj()
{
	for (int i=0; i<k; i++)
		for (int j=0; j<k; j++)
			maszak[i]|=(zak[i][j]<<j);
			
	for (int i=1; i<(1<<k); i++)
	{
		int v=__builtin_ctz(i);
		zab[i]=(zab[i^(1<<v)]|maszak[v]);
		parz[i]=(parz[i^(1<<v)]^1);
	}
	
	for (int i=0; i<(1<<k); i++)
	{
		if (parz[i]==parz[(1<<k)-1])
			parz[i]=1;
		else
			parz[i]=-1;
	}
	
	for (int i=0; i<(1<<k); i++)
		sta[i]=mno[i]=!(zab[i]&i);
	
	for (int i=0; i<k; i++)
		for (int j=0; j<(1<<k); j++)
			if (j&(1<<i))
				sta[j]+=sta[j^(1<<i)];
	
	for (int i=0; i<(1<<k); i++)
	{
		sta[i]%=mod;
		mno[i]=sta[i];
	}
	
	for (int h=1; 1; h++)
	{
		//~ debug() << range(mno, mno+(1<<k));
		if (check_end())
			ans(n-1+h);
		
		for (int i=0; i<(1<<k); i++)
			mno[i]=(mno[i]*sta[i])%mod;
	}
}

int main()
{
	srand(time(0));
	mod=1000*1000*1000+(rand()%1000);
	
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=n; j++)
		{
			if (wcz[j]=='A')
				typ[i][j]=0;
			if (wcz[j]=='O')
				typ[i][j]=1;
			if (wcz[j]=='X')
				typ[i][j]=2;
		}
	}
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (!typ[i][j])
				uni(i, j);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (typ[i][j]==2 && fin(i)==fin(j))
				ans(-1);
	
	
	for (int i=1; i<=n; i++)
		saj[fin(i)]++;
	
	for (int i=1; i<=n; i++)
	{
		if (oj[i]==i && saj[i]>1)
		{
			num[i]=k;
			k++;
		}
	}
	for (int i=1; i<=n; i++)
		if (saj[fin(i)]>1)
			roz[num[fin(i)]]++;
	debug() << range(roz, roz+k);
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (saj[i]==1 || saj[j]==1)
				continue;
			if (typ[i][j]==2)
				zak[num[fin(i)]][num[fin(j)]]=1;
		}
	}
	for (int i=0; i<k; i++)
		debug() << range(zak[i], zak[i]+k);
	if (!k)
		ans(n-1);
	magjuj();
	return 0;
}