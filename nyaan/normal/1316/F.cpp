#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;
 
//#define int long long
typedef long long ll;
 
typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-9;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;
 
ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}
 
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}
 
ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
 
const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
using mP = pair<modint, modint>;
 
string sdir = "RDLU";
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
 
modint t2[1 << 19];
modint invt2[1 << 19];
modint inv2;
void init(int n) {
	t2[0] = 1;
	invt2[0] = 1;
	inv2 = (modint)1 / (modint)2;
	rep(i, n + 5) {
		t2[i + 1] = t2[i] * (modint)2;
		invt2[i + 1] = invt2[i] * inv2;
	}
}
 
struct SegT {
private:
	int n; vector<modint> node, lazy;
	const modint init_c = 0;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 1);
	}
	SegT(vector<modint> &v) {
		int sz = v.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 1);
		rep(i, sz) {
			node[i + n - 1] = v[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
    modint f(modint a, modint b) {
		return a+b;
	}
	void eval(int k, int l, int r) {
		if (lazy[k] == (modint)1)return;
		node[k] *= lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] *= lazy[k];
			lazy[2 * k + 2] *= lazy[k];
		}
		lazy[k] = 1;
	}
	void add(modint x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] *= x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	modint query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			modint vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			modint vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int c, modint x, int k = 0, int l = 0,int r=-1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= c || c+1 <= l)return;
		if (c <= l && r <= c + 1) {
			node[k] = x;
		}
		else {
			update(c, x, k * 2 + 1, l, (l + r) / 2);
			update(c, x, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
};
 
struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};
 
void solve() {
	int n; cin >> n; init(n);
 
 
	vector<LP> vs;
 
	vector<ll> in(n);
	rep(i, n) {
		cin >> in[i];
		vs.push_back({ in[i],i});
	}
 
	int q; cin >> q;
	vector<int> locs(q);
	vector<ll> vals(q);
	rep(i, q) {
		cin >> locs[i]; locs[i]--;
		cin >> vals[i];
 
		vs.push_back({ vals[i],i + n });
	}
	sort(all(vs));
 
	//SegT st1(n+q), st2(n+q);
	BIT memo(n + q);
	modint sum = 0;
 
	vector<modint>ori1(n + q, 0), ori2(n + q, 0);
	int tmp = 0;
	modint csum = 0;
	rep(i, n + q) {
		int id = vs[i].second;
		if (id < n) {
			modint ad = csum * invt2[tmp] * inv2*(modint)in[id];
			sum += ad;
 
			ori1[i] = t2[tmp]*(modint)in[id];
			ori2[i] = invt2[tmp] * (modint)in[id];
			memo.add(i, 1); tmp++;
			csum += ori1[i];
		}
	}
	SegT st1(ori1);
	SegT st2(ori2);
 
	vector<int> cur(n);
	vector<int> tloc(q);
	rep(i, n + q) {
		int id = vs[i].second;
		if (id < n) {
			cur[id] = i;
		}
		else {
			tloc[id - n] = i;
		}
	}
 
	cout << sum << endl;
	rep(i, q) {
		//cout << "loc " << i+n<<" "<<tloc[i] << endl;
		int loc = cur[locs[i]];
		modint val = in[locs[i]];
		modint dif = sum;
 
		
		//erase
		{
			int cl = memo.sum(0, loc);
			modint lesum = st1.query(0, loc);
			modint risum = st2.query(loc + 1, n + q);
			sum += lesum * risum*inv2;
			lesum = lesum * invt2[cl] * inv2*val;
			sum -= lesum;
			//cout << "hello " << i << " " << lesum << " " << risum << endl;
			risum = risum * t2[cl] * inv2*val;
			sum -= risum;
 
 
			memo.add(loc, -1);
			st1.update(loc, 0);
			st1.add(inv2, loc + 1, n + q);
			st2.update(loc, 0);
			st2.add(2, loc + 1, n + q);
		}
		dif = dif - sum;
		//cout << "isdif " << dif << endl;
		loc = tloc[i];
		val = vals[i];
		//add
		{
 
			int cl = memo.sum(0, loc);
			memo.add(loc, 1);
			st1.update(loc, val*t2[cl]);
			st1.add(2, loc + 1, n + q);
			st2.update(loc, val*invt2[cl]);
			st2.add(inv2, loc + 1, n + q);
 
 
			modint lesum = st1.query(0, loc);
			modint risum = st2.query(loc + 1, n + q);
			sum -= lesum * risum*inv2;
			lesum = lesum * invt2[cl] * inv2*val;
			sum += lesum;
			risum = risum * t2[cl] * inv2*val;
			sum += risum;
 
 
		}
		in[locs[i]] = vals[i];
		cur[locs[i]] = loc;
		//cout << "ans is ";
		cout << sum << '\n';
	}
 
}
 
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}