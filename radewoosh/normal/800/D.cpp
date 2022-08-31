//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

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

const int nax=1000*1007;
const int d=6;
const int l=1000*1000;
const long long mod=1000*1000*1000+7;

struct f
{
	long long jed=0;
	long long lin=0;
	long long kwa=0;
};

f operator + (f a, f b)
{
	f ret=f();
	ret.jed=a.jed+b.jed+a.jed*b.jed;
	ret.lin=a.lin+b.lin+a.lin*b.jed+a.jed*b.lin;
	ret.kwa=a.kwa+b.kwa+a.jed*b.kwa+a.kwa*b.jed+2*a.lin*b.lin;
	
	ret.jed%=mod;
	ret.lin%=mod;
	ret.kwa%=mod;
	
	return ret;
}

int n;

f init[nax];
long long mag[nax];

int pot[nax];

long long wyn;

int test(int v, int kt)
{
	v/=pot[kt];
	return (v%10);
}

int main()
{
	pot[0]=1;
	for (int i=1; i<=d; i++)
		pot[i]=(pot[i-1]*10);
	
	scanf("%d", &n);
	while(n--)
	{
		long long x;
		scanf("%lld", &x);
		f tu=f();
		tu.jed=1;
		tu.lin=x;
		tu.kwa=(x*x)%mod;
		init[x]=init[x]+tu;
	}
	for (int i=0; i<d; i++)
	{
		for (int j=l; j>=0; j--)
		{
			int pam=test(j, i);
			for (int k=1; k<=1 && pam; k++)
				init[j-k*pot[i]]=init[j-k*pot[i]]+init[j];
		}
	}
	for (int i=0; i<l; i++)
		mag[i]=init[i].kwa;
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<l; j++)
		{
			int pam=test(j, i);
			for (int k=1; k<=1 && pam; k++)
				mag[j-k*pot[i]]=(mag[j-k*pot[i]]-mag[j]+mod)%mod;
		}
	}
	for (int i=0; i<l; i++)
	{
		long long x=mag[i]*i;
		wyn^=x;
	}
	printf("%lld\n", wyn);
	return 0;
}