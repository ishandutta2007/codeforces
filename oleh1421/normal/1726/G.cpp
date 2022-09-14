//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef pair<int, int> Pii;
typedef long long ll;

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
		assert((n ^ (n&-n)) == 0);

		const int g = 3;
		int h = (int)mod_pow(g, (mod - 1) / n, mod);
		if (sign == -1) h = (int)mod_inv(h, mod);

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
//#define prev aboba
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=600010;
const ll mod=998244353;
const ll inf=1e18;
ll f[N];
ll rf[N];
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll C(int n,int k){
    if (k>n || k<0) return 0;
    return f[n]*rf[n-k]%mod*rf[k]%mod;
}
int a[N],b[N];
void solve(){
    int n;cin>>n;
    f[0]=1;
    for (int i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    rf[n]=binpow(f[n],mod-2);
    for (ll i=n;i>=1;i--){
        rf[i-1]=(rf[i]*i)%mod;
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    vector<pair<int,int> >v;
    int mx=0;
    for (int i=1;i<=n;i++){
        int x=a[i],y=b[i];
        v.push_back({x,y});
        mx=max(mx,x);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++){
        a[i+1]=v[i].first;
        b[i+1]=v[i].second;
    }
    for (int i=1;i<n;i++){
        if (a[i]==a[i+1] && b[i]==1 && b[i+1]==1 && a[i]!=mx){
            cout<<0<<endl;
            return;
        }
    }
    bool check=false;
    for (int i=1;i<n;i++){
        if (a[i]==a[i+1] && b[i]==1 && b[i+1]==1){
            check=true;
            break;
        }
    }
    ll ans=0;

    if (!check){
        int L=mx+1,R=6*n;
        ll res=1ll;
        for (int i=1;i<=n;i++){
            if (b[i]==0){
                int cnt=1;

                while (i+cnt<=n && a[i+cnt]==a[i] && b[i+cnt]==b[i]){
                    cnt++;
                }

                R=min(R,i-1+a[i]);
//                int del=(i-1)-(x-a[i]);
//                if (del<0 || del>=i){
//                    res=0;
//                    break;
//                }
                res*=f[cnt];
                res%=mod;
                i+=cnt-1;

            } else {
                L=max(L,n+a[i]-i);
                R=min(R,n+a[i]-1);
//                (n+a[i]-i)<=x<i+(n+a[i]-i)
//                int del=(x-a[i])-(n-i);
//                if (del<0 || del>=i){
//                    res=0;
//                    break;
//                }
            }
        }
        if (L<=R) ans+=res*(R-L+1ll);
        ans%=mod;

    }
    {
        int x=mx;
        ll res=1ll;
        for (int i=1;i<=n && a[i]+b[i]<=mx;i++){
            if (b[i]==0){
                int cnt=1;
                while (i+cnt<=n && a[i+cnt]==a[i] && b[i+cnt]==b[i]){
                    cnt++;
                }
                int del=(i-1)-(x-a[i]);
//                cout<<i-1<<" "<<x-a[i]<<endl;
                if (del<0 || del>=i){
                    res=0;
                    break;
                }
                res*=f[cnt];
                res%=mod;
                i+=cnt-1;

            } else {
                int del=(x-a[i])-(n-i);
                if (del<0 || del>=i){
                    res=0;
                    break;
                }
            }
        }
        int cnt=0;
        for (int i=1;i<=n;i++){
            cnt+=(a[i]+b[i]==mx+1);
        }
        for (int i=n-cnt+1;i<=n;i++){
            res*=i;
            res%=mod;
        }
        ans+=res;
        ans%=mod;
    }
    cout<<ans<<'\n';


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5
*/