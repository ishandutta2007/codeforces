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

using ll=long long;
const int nax=1000*1007;
const int d=17;
const int m=(1<<d);
const ll mod=1000*1000*1000+7;

const ll md=mod;
const ll inv2 = (mod + 1) / 2;

int t;

void fft1(vector <ll> &a, int n) {
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += 2 * len) {
      for (int j = 0; j < len; j++) {
        int u = a[i + j];
        int v = a[i + j + len];
        a[i + j] = (u + v) % md;
        a[i + j + len] = (u - v + md) % md;
      }
    }
  }
}

void fft2(vector <ll> &a, int n) {
  for (int len = n / 2; len >= 1; len >>= 1) {
    for (int i = 0; i < n; i += 2 * len) {
      for (int j = 0; j < len; j++) {
        int u = a[i + j];
        int v = a[i + j + len];
        a[i + j] = (u + v) * inv2 % md;
        a[i + j + len] = (u - v + md) * inv2 % md;
      }
    }
  }
}
 
vector <ll> convolute(vector <ll> a, vector <ll> b) {
  fft1(a, t);
  fft1(b, t);
  for (int i = 0; i < t; i++) {
    a[i] = (a[i] * b[i]) % md;
  }
  fft2(a, t);
  return a;
}


int n;

ll tab[nax];

ll ile[nax];

ll fib[nax];

ll raz[nax];
ll dwa[nax];
ll trz[nax];

inline ll dod(ll &a, ll b)
{
	if ((a+=b)>=mod)
		a-=mod;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	fib[0]=0;
	fib[1]=1;
	for (int i=2; i<=m; i++)
		fib[i]=(fib[i-1]+fib[i-2])%mod;
		
	for (int i=1; i<=n; i++)
		ile[tab[i]]++;
	
	for (int i=0; i<m; i++)
	{
		for (int j=i; 1; j=((j-1)&i))
		{
			raz[i]+=ile[j]*ile[i^j];
			if (!j)
				break;
		}
	}
	for (int i=0; i<m; i++)
		dwa[i]=ile[i];
	
	vector <ll> daj;
	t=m;
	for (int i=0; i<m; i++)
		daj.push_back(ile[i]);
	auto wez=convolute(daj, daj);
	for (int i=0; i<m; i++)
		trz[i]=wez[i];
		
	debug() << range(raz, raz+10);
	debug() << range(dwa, dwa+10);
	debug() << range(trz, trz+10);
	
	for (int i=0; i<m; i++)
	{
		raz[i]%=mod;
		dwa[i]%=mod;
		trz[i]%=mod;
		
		raz[i]*=fib[i];
		dwa[i]*=fib[i];
		trz[i]*=fib[i];
		
		raz[i]%=mod;
		dwa[i]%=mod;
		trz[i]%=mod;
	}
	debug() << range(raz, raz+10);
	debug() << range(dwa, dwa+10);
	debug() << range(trz, trz+10);
	
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (!(j&(1<<i)))
			{
				dod(raz[j], raz[j^(1<<i)]);
				dod(dwa[j], dwa[j^(1<<i)]);
				dod(trz[j], trz[j^(1<<i)]);
			}
		}
	}
	for (int i=0; i<m; i++)
	{
		raz[i]*=dwa[i];
		raz[i]%=mod;
		raz[i]*=trz[i];
		raz[i]%=mod;
	}
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (!(j&(1<<i)))
			{
				dod(raz[j], mod-raz[j^(1<<i)]);
			}
		}
	}
	ll wyn=0;
	for (int i=0; i<d; i++)
		dod(wyn, raz[1<<i]);
	printf("%lld\n", wyn);
	
	return 0;
}