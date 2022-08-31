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

void ff()
{
	fflush(stdout);
}

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=200*1007;
const ll mod=998244353;

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
		bool split = true, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { // [0,B] into [-B/2, B/2]
		assert(a.size() == b.size()); // equal size!!!
		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] = (ans[i+j]+a[i]*b[j])%mod;
		return ans; }
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
			mul%=mod;
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += speed(t[0], i, x) * speed(t[1], i, y);
			dft(prod, true); // remember: llround(prod[i].real)%MOD*mul !!!
			REP(i, ans.size()) ans[i]+= ((llround(prod[i].real)%mod)*mul)%mod;
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
	for (ll &i : ans)
		i%=mod;
	return ans;
}

int n;
ll cel;

vi graf[nax];

int roz[nax];
int jump[nax];
int ojc[nax];

ll dziel(ll a, ll b)
{
	a%=mod;
	b%=mod;
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

void dfs1(int v, int oj)
{
	roz[v]=1;
	for (int &i : graf[v])
	{
		if (i==oj)
		{
			swap(graf[v].back(), i);
			graf[v].pop_back();
			break;
		}
	}
	for (int &i : graf[v])
	{
		ojc[i]=v;
		dfs1(i, v);
		roz[v]+=roz[i];
		if (roz[i]>roz[graf[v][0]])
			swap(i, graf[v][0]);
	}
	if (graf[v].empty())
		jump[v]=v;
	else
		jump[v]=jump[graf[v][0]];
}

void pusz(vll &wek)
{
	wek.insert(wek.begin(), 0);
}

vll huffman(vector <vll> wek)
{
	if (wek.empty())
		return vll{1};
	priority_queue <pii> kol;
	for (int i=0; i<(int)wek.size(); i++)
		kol.push({-wek[i].size(), i});
	while((int)kol.size()>1)
	{
		int x=kol.top().second;
		kol.pop();
		int y=kol.top().second;
		kol.pop();
		wek[x]=multiply(wek[x], wek[y]);
		kol.push({-wek[x].size(), x});
	}
	return wek[kol.top().second];
}

vector <vll> zbi[nax];
vll trz[nax];

vi wekg;

vll dod(vll a, vll b)
{
	while((int)a.size()<(int)b.size())
		a.push_back(0);
	for (int i=0; i<(int)b.size(); i++)
		a[i]=(a[i]+b[i])%mod;
	return a;
}

pair <vll,vll> rek(int a, int b)
{
	if (a==b)
		return {vll{1}, trz[wekg[a]]};
	int s=(a+b)/2;
	auto raz=rek(a, s);
	auto dwa=rek(s+1, b);
	return {dod(raz.first, multiply(raz.second, dwa.first)), multiply(raz.second, dwa.second)};
}

vll dfs2(int v)
{
	int u=jump[v];
	vi wek;
	while(u!=ojc[v])
	{
		for (int i : graf[u])
			if (jump[i]!=jump[u])
				zbi[u].push_back(dfs2(i));
		wek.push_back(u);
		u=ojc[u];
	}
	reverse(wek.begin(), wek.end());
	for (int i : wek)
	{
		trz[i]=huffman(zbi[i]);
		pusz(trz[i]);
	}
	wekg=wek;
	auto wez=rek(0, (int)wek.size()-1);
	return dod(wez.first, wez.second);
}

ll spo[nax];

int main()
{
	scanf("%d%lld", &n, &cel);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1, 0);
	
	vll wez=dfs2(1);
	for (int i=1; i<=n; i++)
		spo[i]=wez[i];
	
	ll wyn=0;
	ll li=1;
	ll mi=1;
	for (int i=1; i<=n; i++)
	{
		wyn=(wyn+dziel(mi, li)*spo[i])%mod;
		li=(li*(i))%mod;
		mi=(mi*((cel%mod)+i))%mod;
	}
	printf("%lld\n", wyn);
	return 0;
}