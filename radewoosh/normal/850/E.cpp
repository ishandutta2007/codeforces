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


using ll=long long;
const ll md = 1000*1000*1000+7;
const ll inv2 = (md + 1) / 2;

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


const int nax=(1<<21)+7;
const long long mod=1000*1000*1000+7;

int n, m;

char wcz[nax];

long long wyn;

int main()
{
	scanf("%d", &n);
	t=m=(1<<n);
	scanf("%s", wcz);
	vector <ll> jed, dwa;
	for (int i=0; i<m; i++)
	{
		jed.push_back(0);
		dwa.push_back(0);
		if (wcz[i]=='1')
			jed.back()=1;
		else
			dwa.back()=1;
	}
	vector <ll> trz=convolute(jed, dwa);
	for (int i=0; i<m; i++)
	{
		wyn+=(1<<__builtin_popcount(i))*trz[i];
		wyn%=mod;
	}
	wyn*=3;
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}