#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#define endl '\n'
typedef long long ll;
using namespace std;
typedef pair<int, int> Pii;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<int mod, int primitive_root>
class NTT {
public:
	int get_mod() const { return mod; }
	void _ntt(vector<ll>& a, int sign) {
		const int n = sz(a);
		assert((n ^ (n&-n)) == 0); //n = 2^k

		const int g = 3; //g is primitive root of mod
		int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod

		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}

		for (int m = 1; m < n; m *= 2) {
			const int m2 = 2 * m;
			const ll base = mod_pow(h, n / m2, mod);
			ll w = 1;
			FOR(x, m) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s];
					ll d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}

		for (auto& x : a) if (x < 0) x += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv(sz(input), mod);
		for (auto& x : input) x = x * n_inv % mod;
	}

	// 
	vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
		int ntt_size = 1;
		while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);

		ntt(_a);
		ntt(_b);

		FOR(i, ntt_size){
			(_a[i] *= _b[i]) %= mod;
		}

		intt(_a);
		return _a;
	}
};

ll garner(vector<Pii> mr, int mod){
	mr.emplace_back(mod, 0);

	vector<ll> coffs(sz(mr), 1);
	vector<ll> constants(sz(mr), 0);
	FOR(i, sz(mr) - 1){
		// coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) 
		ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
		if (v < 0) v += mr[i].first;

		for (int j = i + 1; j < sz(mr); j++) {
			(constants[j] += coffs[j] * v) %= mr[j].first;
			(coffs[j] *= mr[i].first) %= mr[j].first;
		}
	}

	return constants[sz(mr) - 1];
}
NTT<998244353,3>NTT_1;


const int N=100010;
const int inf=1000000001;
const int mod=998244353;
const int K=(1<<15);
struct Something{
    vector<ll>a;
    vector<ll>b;
    int n;
    Something(){
        a.resize(K,0);
        b.resize(K,0);
    }
};
vector<ll>mult_poly(vector<ll>a,vector<ll>b){
    vector<ll>ans=NTT_1.convolution(a,b);
    while (ans.size()>K) ans.pop_back();
//    cout<<ans.size()<<endl;
    return ans;
}
vector<ll>add_poly(vector<ll>a,vector<ll>b){
    for (int i=0;i<K;i++) a[i]+=b[i],a[i]%=mod;
    return a;
}
Something mult(Something A,Something B){
    Something res;
    res.n=A.n+B.n;
    res.a=mult_poly(A.a,B.a);
    vector<ll>a1=mult_poly(A.b,B.b);
    for (int i=K-1;i>=1;i--) a1[i]=a1[i-1];
    a1[0]=0;
    res.a=add_poly(res.a,a1);
    res.b=add_poly(mult_poly(A.a,B.b),mult_poly(A.b,B.a));
    vector<ll>b1=mult_poly(A.b,B.b);
    for (int i=0;i<K;i++) b1[i]=mod-b1[i];
    res.b=add_poly(res.b,b1);
    for (int i=K-1;i>=1;i--) b1[i]=b1[i-1];
    b1[0]=0;
    res.b=add_poly(res.b,b1);
    return res;
}
Something binpow(Something a,ll b){
    if (b==1) return a;
    if (b%2) return mult(a,binpow(a,b-1));
    else return binpow(mult(a,a),b/2ll);
}
void solve(){
    int n,k;cin>>n>>k;
    if (k>=K) exit(1);
    Something A;
    A.a[0]=1;
    A.a[1]=1;
    A.b[0]=1;
    A.n=1;
    A=binpow(A,n);
    for (int i=1;i<=k;i++) cout<<A.a[i]<<" ";
    cout<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}