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

#define REP(i,n) for(int i = 0; i < int(n); ++i)
/*Precision error max_ans/1e15 (2.5e18) for (long) doubles.
So integer rounding works for doubles with answers 0.5*1e15,
e.g. for sizes 2^20 and RANDOM positive integers up to 45k.
Those values assume DBL_MANT_DIG=53 and LDBL_MANT_DIG=64.
For input in [0, M], you can decrease everything by M/2.
If there are many small vectors, uncomment "BRUTE FORCE".*/
typedef double ld; // 'long double' is 2.2 times slower
struct C {
	ld real, imag;
	C operator * (const C & he) const {
		return C{real * he.real - imag * he.imag,
				real * he.imag + imag * he.real};
	}
	void operator += (const C & he) {
		real += he.real; imag += he.imag;
	}
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].real, om[k].imag * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.real - y.real, x.imag - y.imag};
			}
	}
	if(rev) REP(i, n) a[i].real /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b, bool split = false) {
	if(a.empty() || b.empty()) return {};
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	/* if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
		return ans; } */
	while(n&(n-1)) ++n;
	// http://codeforces.com/blog/entry/48417
	auto speed = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].real + w[j].real * r, w[i].imag
				- w[j].imag * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { // standard fast version
		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].real = a[i];
		REP(i, b.size()) in[i].imag = b[i];
		dft(in, false);
		REP(i, n) done[i] = speed(in, i, 0) * speed(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].real) : done[i].real;
	//REP(i,ans.size())err=max(err,abs(done[i].real-ans[i]));
	}
	return ans;
}

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n, m;

void out(vi wek)
{
	sort(wek.begin(), wek.end());
	wek.resize(unique(wek.begin(), wek.end())-wek.begin());
	printf("%d\n", (int)wek.size());
	for (int i : wek)
		printf("%d ", i);
	if (!wek.empty())
		printf("\n");
	exit(0);
}

const ll mod=1000*1000*1000+7;
ll h=100*1000+3;
ll pot[nax];

ll potuj(ll x)
{
	if (x<nax)
		return pot[x];
	if (x&1)
		return (potuj(x-1)*h)%mod;
	ll w=potuj(x/2);
	return (w*w)%mod;
}

void jeden()
{
	vi wek;
	ll s=0;
	for (int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		wek.push_back(x);
		s+=x;
	}
	s*=2;
	vi wyn, kandy;
	while(s>=0)
	{
		if (!(s%n))
			kandy.push_back((s/n)%m);
		s-=m;
	}
	ll nor=0;
	ll odw=0;
	for (int i : wek)
	{
		nor=(nor+potuj(i))%mod;
		odw=(odw+potuj(m-i))%mod;
	}
	
	sort(kandy.begin(), kandy.end());
	kandy.resize(unique(kandy.begin(), kandy.end())-kandy.begin());
	int w=0;
	for (int i : kandy)
	{
		while(w<(int)wek.size() && wek[w]<=i)
		{
			odw=(odw-potuj(m-wek[w])+potuj(mod-1-wek[w])+mod)%mod;
			w++;
		}
		if (nor==(odw*potuj(i))%mod)
			wyn.push_back(i);
	}
	
	out(wyn);
}

int main()
{
	pot[0]=1;
	for (int i=1; i<nax; i++)
		pot[i]=(pot[i-1]*h)%mod;
	scanf("%d%d", &n, &m);
	if (m>2*n+17)
		jeden();
	vi raz(m, 0);
	vi dwa(m, 1);
	for (int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		raz[x]=1;
		dwa[x]=0;
	}
	vi trz=multiply(raz, dwa);
	for (int i=m; i<(int)trz.size(); i++)
		trz[i%m]+=trz[i];
	vi wyn;
	for (int i=0; i<m; i++)
		if (i<(int)trz.size() && !trz[i])
			wyn.push_back(i);
	out(wyn);
	return 0;
}