#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 250001;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

const ll root = 62;
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int deg[MAXN] = {0};

ll FAC[MAXN] = {0};
ll INV[MAXN] = {0};

ll F[MAXN] = {0};

ll bin(ll i, ll j){
    if(i < j || i < 0 || j < 0)return 0;
    ll num = FAC[i];
    ll den = (INV[i-j]*INV[j])%mod;
    return (num*den)%mod;
}

vector<vl> V;

vl dq(int i, int j){
    if(i == j-1)return V[i];
    int mid = (i+j)/2;
    return conv(dq(i, mid), dq(mid, j));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   // freopen("fhc.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;


    cin >> n;

    ll t = 1;
    rep(c1,0,n+1){
        FAC[c1] = t;
        t *=ll(c1+1);
        t %= mod;
    }

    INV[n] = modpow(FAC[n], mod-2);
    for(ll c1 = n-1; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1] * (c1+1))%mod;
    }

    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
    }
    rep(c1,1,n){
        deg[c1]--;
    }
    rep(c1,0,n){
        F[deg[c1]]++;
    }

    vl res = {1};
    rep(c1,1,n){
        m = F[c1];
        if(m > 0){
            vl vv;
            ll mp = 1;
            for(ll i = 0; i <= m; i++){
                vv.push_back((bin(m,i) * mp)%mod);
                mp *= ll(c1);
                mp %= mod;
            }
            V.push_back(vv);
            //res = conv(res, vv);
        }
    }

    res = dq(0, sz(V));

    ll ans = 0;
    t = 1;
    rep(c1,0,sz(res)){
        ans += (mod+t) * ((res[c1] * FAC[n-c1])%mod);
        ans %= mod;
        t *= -1;
    }
    cout << ans << "\n";


    return 0;
}