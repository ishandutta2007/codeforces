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
const int nax=130*1007;
const ll mod=998244353;
const ll modk=mod*mod*2;

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
	if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) {ans[i+j] += a[i]*b[j];ans[i+j]%=mod;}
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
			REP(i, ans.size()) {ans[i]+= (llround(prod[i].real)%mod)*mul; ans[i]%=mod;}
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

vector <ll> brut(vector <ll> raz, vector <ll> dwa)
{
	vector <ll> ret(raz.size()+dwa.size()-1, 0);
	for (int i=0; i<(int)raz.size(); i++)
	{
		for (int j=0; j<(int)dwa.size(); j++)
		{
			ret[i+j]+=raz[i]*dwa[j];
			ret[i+j]%=mod;
		}
	}
	return ret;
}

int n, k;

vector <int> graf[nax];
int oj[nax];
int roz[nax];

ll sil[nax];
ll odw[nax];
ll kom[nax];

ll dpgor[nax];
ll dpdol[nax];

ll wyn;

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

vector <ll> polacz(vector <vector <ll> > wek)
{
	int r=wek.size();
	priority_queue <pair<int,int> > kol;
	for (int i=0; i<r; i++)
		kol.push({-wek[i].size(), i});
	while((int)kol.size()>1)
	{
		int x=kol.top().second;
		kol.pop();
		int y=kol.top().second;
		kol.pop();
		wek[x]=multiply(wek[x], wek[y], true);
		kol.push({-wek[x].size(), x});
	}
	return wek[kol.top().second];
}

void dod(ll &a, ll b)
{
	if ((a+=b)>=modk)
		a-=modk;
}

void obcykaj(int v)
{
	vector < vector <ll> > mam;
	for (int i : graf[v])
		mam.push_back({1, roz[i]});
	if (v!=1)
		mam.push_back({1, n-roz[v]});
	auto wez=polacz(mam);
	map <int,ll> rozy;
	for (const auto &i : mam)
		rozy[i[1]]=0;
	//~ debug() << v << " " << mam << " " << wez;
	for (auto i : rozy)
	{
		ll x=i.first;
		ll sum=0;
		ll y=0;
		//~ debug() << "dla " << x;
		for (int i=0; i<min(k+1, (int)wez.size()); i++)
		{
			sum=(wez[i]-x*sum)%mod;
			if (sum<0)
				sum+=mod;
			dod(y, sum*kom[i]);
		}
		rozy[i.first]=y%mod;
	}
	//~ debug() << rozy;
	for (int i : graf[v])
		dpgor[i]=rozy[roz[i]];
	if (v!=1)
		dpdol[v]=rozy[n-roz[v]];
}

void dfs1(int v)
{
	for (int &i : graf[v])
	{
		if (i==oj[v])
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	roz[v]=1;
	for (int i : graf[v])
	{
		oj[i]=v;
		dfs1(i);
		roz[v]+=roz[i];
	}
	obcykaj(v);
}

ll dfs2(int v)
{
	ll ret=0;
	for (int i : graf[v])
	{
		ll w=dfs2(i);
		wyn=(wyn+ret*w)%mod;
		ret=(ret+w)%mod;
	}
	if (v!=1)
	{
		ret=(ret+dpdol[v])%mod;
		wyn=(wyn+ret*dpgor[v])%mod;
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &k);
	if (k==1)
	{
		wyn=n;
		wyn*=(n-1);
		wyn%=mod;
		printf("%lld\n", dziel(wyn, 2));
		return 0;
	}
	if (n==1)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	sil[0]=1;
	for (int i=1; i<=k; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[k]=dziel(1, sil[k]);
	for (int i=k-1; i>=0; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	for (int i=0; i<=k; i++)
	{
		//~ kom[i]=odw[i]*odw[k-i];
		kom[i]=odw[k-i];
		kom[i]%=mod;
		kom[i]*=sil[k];
		kom[i]%=mod;
	}
	dfs1(1);
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ debug() << i << "  " << dpdol[i] << " " << dpgor[i];
	//~ }
	dfs2(1);
	
	printf("%lld\n", wyn);
	return 0;
}