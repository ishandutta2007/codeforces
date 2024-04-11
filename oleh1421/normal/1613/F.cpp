#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
mt19937 rnd(time(nullptr));
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
const int N=250100;
const ll mod=998244353;
int d[N];
ll f[N];
ll dp[N];

vector<ll>rec(int l,int r){
    if (l==r){
        vector<ll>ans={1,d[l]};
        return ans;
    }
    int m=(l+r)/2;
    vector<ll>a=rec(l,m);
    vector<ll>b=rec(m+1,r);
    return NTT_1.convolution(a,b);
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        d[x]++;
        d[y]++;
    }
    for (int i=2;i<=n;i++) d[i]--;
    f[0]=1;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    vector<ll>dp=rec(1,n);
    while (dp.size()<n+1) dp.push_back(0);
//    dp[0]=1;
//    for (int i=1;i<=n;i++){
//        for (int j=n-1;j>=0;j--){
//            dp[j+1]=(dp[j+1]+dp[j]*d[i])%mod;
//        }
//    }
    ll res=0ll;
    for (int i=0;i<=n;i++){
        ll cur=f[n-i]*dp[i]%mod;
        if (i%2) cur=mod-cur;
        res=(res+cur)%mod;
    }
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/*
10
100 2
4 4
25 25 25 25
25 25 25 25

10
100 3
5 5 5
10 10 10 10 60
10 10 10 10 60
10 10 10 10 60



10
5000 7
16 16 16 16 16 18 16
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 15 15 3 3 3 3 3 3 2 2 5 5 3 3 1 1
10 10 10 10 10 10 10 10 3 3 3 3 3 3 1 1

19638


2 2
2 2
1 1
1 1

10000 7
16 18 16 16 16 16 16
10 10 10 10 10 10 10 10 3 3 3 3 3 3 1 1
15 15 15 15 3 3
3 3 3 2 2 5
5 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 10 10 10 10 4 4 4 4 3 3 3 3 1 1
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1
15 15 15 15 4 4 4 4 4 4 4 4 3 3 1 1



15000 7
4 7 10 13 12 8 8
1000 1000 1000 12000
1000 1000 1000 1000 1000 1000 9000
1000 1000 1000 1000 1000 1000 1000 1000 1000 6000
1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 3000
1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 4000
1000 1000 1000 1000 1000 1000 1000 8000
1000 1000 1000 1000 1000 1000 1000 8000


10
20 7
4 7 10 13 12 8 8
1 1 1 17
1 1 1 1 1 1 14
1 1 1 1 1 1 1 1 1 11
1 1 1 1 1 1 1 1 1 1 1 1 8
1 1 1 1 1 1 1 1 1 1 1 9
1 1 1 1 1 1 1 13
1 1 1 1 1 1 1 13
*/