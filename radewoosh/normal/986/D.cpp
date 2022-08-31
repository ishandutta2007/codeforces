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
const int nax=1500*1007;

#define REP(i,n) for(int i = 0; i < int(n); ++i)
typedef double ld; // 'long double' is 2.2 times slower
struct C { ld real, imag;
	C operator * (const C & he) const {
		return C{real * he.real - imag * he.imag,
				real * he.imag + imag * he.real};
	}
	void operator += (const C & he) { real += he.real; imag += he.imag; }
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
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
		bool split = false, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { // [0,B] into [-B/2, B/2]
		assert(a.size() == b.size()); // equal size!!!
		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	/* if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
		return ans; } */
	while(n&(n-1)) ++n;
	auto speed = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].real + w[j].real * r, w[i].imag
				- w[j].imag * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { // standard fast version
		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].real = a[i] - big;
		REP(i, b.size()) in[i].imag = b[i] - big;
		dft(in, false);
		REP(i, n) done[i] = speed(in, i, 0) * speed(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].real) : done[i].real;
	//REP(i,ans.size())err=max(err,abs(done[i].real-ans[i]));
	}
	else { // Split big INTEGERS into pairs a1*M+a2,
		const T M = 1<<15; // where M = sqrt(max_absvalue).
		vector<C> t[2]; // This version is 2.2-2.5 times slower.
		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a; // below use (in[i]-big) if normalized
			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul *= M) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
			dft(prod, true); // remember: llround(prod[i].real)%MOD*mul !!!
			REP(i, ans.size()) ans[i]+= llround(prod[i].real)*mul;
		}
	}
	if(normalize) {
		T so_far = 0;
		REP(i, ans.size()) {
			if(i < (int) a.size()) so_far += a[i] + b[i];
			else so_far -= a[i-a.size()] + b[i-a.size()];
			ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
		}
	}
	return ans;
}

char wcz[nax];
vector <int> wek;

ll wyn=1e18;

void podziel()
{
	if (wek[0]&1)
		wek[0]++;
	for (int i=0; i<(int)wek.size(); i++)
	{
		if (wek[i]&1)
			wek[i-1]+=5;
		wek[i]/=2;
	}
	for (int i=0; i<(int)wek.size(); i++)
	{
		if (wek[i]>9)
		{
			assert(i+1!=(int)wek.size());
			wek[i+1]+=wek[i]/10;
			wek[i]%=10;
		}
	}
	while(!wek.back())
		wek.pop_back();
}

const int d=4;

vector <ll> sprez(const vector <ll> &a)
{
	vector <ll> ret;
	ll mno;
	for (int i=0; i<(int)a.size(); i++)
	{
		if (!(i%d))
		{
			ret.push_back(0);
			mno=1;
		}
		ret.back()+=a[i]*mno;
		mno*=10;
	}
	return ret;
}

vector <ll> rozsprez(const vector <ll> &a)
{
	vector <ll> ret;
	for (int i=0; i<(int)a.size(); i++)
	{
		ret.push_back(a[i]);
		for (int h=1; h<d; h++)
			ret.push_back(0);
	}
	return ret;
}

vector <ll> brut(vector <ll> a)
{
	for (int i=0; i<(int)a.size(); i++)
		a[i]*=3;
	for (int i=0; i<(int)a.size(); i++)
	{
		if (a[i]>9)
		{
			if (i+1==(int)a.size())
				a.push_back(0);
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
	while(!a.back())
		a.pop_back();
	return a;
}

vector <ll> mnoz(const vector <ll> &a, const vector <ll> &b)
{
	auto aa=sprez(a);
	auto bb=sprez(b);
	//~ debug() << aa.size() << " razy " << bb.size();
	auto wez=rozsprez(multiply(aa, bb));
	//~ debug() << a << "*" << b << " to " << wez;
	for (int i=0; i<(int)wez.size(); i++)
	{
		if (wez[i]>9)
		{
			if (i+1==(int)wez.size())
				wez.push_back(0);
			wez[i+1]+=wez[i]/10;
			wez[i]%=10;
		}
	}
	while(!wez.back())
		wez.pop_back();
	return wez;
}

int czyok(vector <ll> ter)
{
	if ((int)ter.size()!=(int)wek.size())
		return ter.size()>wek.size();
	for (int i=(int)ter.size()-1; i>=0; i--)
		if (ter[i]!=wek[i])
			return ter[i]>wek[i];
	return 1;
}

int szacuj()
{
	int w=floor(log(10)*(wek.size()-1)/log(3));
	return max(1, w-4);
}

vector <ll> pamwek;
ll pamwyk;

ll solve(int h)
{
	ll wyk=szacuj();
	ll pam=wyk;
	vector <ll> sta{1};
	vector <ll> pot{3};
	if (!h)
	{
		while(wyk)
		{
			//~ debug() << "jesz " << wyk;
			if (wyk&1)
				sta=mnoz(sta, pot);
			wyk>>=1;
			if (wyk)
				pot=mnoz(pot, pot);
		}
		pamwyk=pam;
		pamwek=sta;
	}
	else
	{
		pam=pamwyk;
		sta=pamwek;
	}
	while(!czyok(sta))
	{
		pam++;
		sta=brut(sta);
	}
	return pam;
}

int main()
{
	scanf("%s", wcz);
	//~ for (int i=0; i<1500*1000; i++)
		//~ wcz[i]='9';
	for (int i=0; wcz[i]; i++)
		wek.push_back(wcz[i]-'0');
	reverse(wek.begin(), wek.end());
	for (int h=0; h<3; h++)
	{
		//~ debug() << wek;
		//~ debug() << "start " << h;
		if (wek.size()==1 && wek[0]==1)
		{
			wyn=min(wyn, h*2LL);
			podziel();
			continue;
		}
		wyn=min(wyn, h*2ll+solve(h)*3LL);
		podziel();
	}
	printf("%lld\n", max(wyn, 1LL));
	return 0;
}