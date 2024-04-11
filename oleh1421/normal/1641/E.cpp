#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=100010;
const ll mod=998244353;
const ll mod1=mod*mod;
const int K=155;
const ll inf=1000000000000000001;
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



ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
ll pw2[N];
ll a[N];
ll p[N];
ll s[N];
ll s1[N];
ll sum[N*2];
ll x[N],y[N];
void mult(int l,int r){
    if (l==r) return;
    int m=(l+r)/2;
    mult(l,m);
    mult(m+1,r);
    vector<ll>a,b;
    for (int i=l;i<=m;i++) a.push_back(x[i]);
    for (int i=m+1;i<=r;i++) b.push_back(y[i]);
    auto ans=NTT_1.convolution(a,b);
    for (int i=0;i<ans.size();i++){
        if (ans[i]){
            sum[i+l+m+1]+=ans[i];
            sum[i+l+m+1]%=mod;
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>p[i];
    pw2[0]=1;
    s[0]=0;
    s1[0]=0;
    for (int i=1;i<=n;i++){
        pw2[i]=(pw2[i-1]*2ll)%mod;
        s[i]=(s[i-1]+a[i])%mod;
        s1[i]=(s1[i-1]+a[i]*i)%mod;

    }
    ll res=0ll;
    for (int l=1;l<=m;l++){
        ll tot=pw2[m-l]-1ll;
        tot*=pw2[l-1];
        tot%=mod;
        tot*=(s[p[l]-1]*p[l]-s1[p[l]-1])%mod;
        tot%=mod;
        res+=tot;
        res%=mod;
    }
    for (int r=1;r<=m;r++){
        ll tot=(s[p[r]]*p[r]-s1[p[r]])%mod;
        tot*=pw2[m-r];
        tot%=mod;
        tot*=pw2[r-1]-1ll;
        tot%=mod;
        res+=tot;
        res%=mod;

    }
    for (int i=1;i<=m;i++){
        ll val=(s[p[i]]*p[i]-s1[p[i]])%mod;
        val*=pw2[m-i]%mod;
        val%=mod;
        res+=val;
        res%=mod;
    }
    for (int i=m;i>=1;i--){
        ll val=(s1[n]-s1[p[i]-1])-(s[n]-s[p[i]-1])*(p[i]);
        val%=mod;
        val*=pw2[i-1];
        val%=mod;
        res+=val;
        res%=mod;
    }
    for (int i=1;i<=m;i++){
        x[p[i]]=pw2[i-1];
        y[p[i]]=pw2[m-i];
    }
//    for (int i=1;i<=n;i++){
//        for (int j=i+1;j<=n;j++){
//            sum[i+j]+=x[i]*y[j];
//            if (sum[i+j]>=mod1) sum[i+j]-=mod1;
//            //sum[i+j]%=mod;
//        }
//    }
    mult(1,n);
    for (int i=0;i<=n*2;i++) sum[i]%=mod;
    for (int S=0;S<=n*2;S++){
//            ll val=(s1[(p[l]+p[r])/2]-s1[p[l]-1]-(s[(p[l]+p[r])/2]-s[p[l]-1])*p[l])+((s[p[r]]-s[(p[l]+p[r])/2])*(p[r])-(s1[p[r]]-s1[(p[l]+p[r])/2]));
        ll val=(s1[S/2]*2ll-s[S/2]*S);
        val%=mod;
        val*=sum[S];
        val%=mod;
        res+=val;
        res%=mod;

    }


    res*=binpow(pw2[m]-1,mod-2);
    res%=mod;
    res+=mod;
    res%=mod;
    cout<<res<<endl;

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
6 7
1 2 1
2 3 3
3 1 5
4 5 2
5 6 4
6 4 6
3 4 1
1
5 1

**/