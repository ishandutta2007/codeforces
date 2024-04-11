#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 1000001;

const ll root = 62;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

typedef vector<ll> vl;
void ntt(vl& a, vl& rt, vl& rev, int n) {
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
				ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
				a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
				ai += (ai + z >= mod ? z - mod : z);
	}
}

vl conv(const vl& a, const vl& b) {
	if (a.empty() || b.empty())
		return {};
	int s = sz(a)+sz(b)-1, B = 32 - __builtin_clz(s), n = 1 << B;
	vl L(a), R(b), out(n), rt(n, 1), rev(n);
	L.resize(n), R.resize(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
	ll curL = mod / 2, inv = modpow(n, mod - 2);
	for (int k = 2; k < n; k *= 2) {
		ll z[] = {1, modpow(root, curL /= 2)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	ntt(L, rt, rev, n); ntt(R, rt, rev, n);
	rep(i,0,n) out[-i & (n-1)] = L[i] * R[i] % mod * inv % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}


vl ex(const vl &a, ll to){
    if(to == 0)return {1};
    if(to == 1)return a;
    int s = sz(a)*to - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    vl L(a), out(n), rt(n, 1), rev(n);
    L.resize(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
	ll curL = mod / 2, inv = modpow(n, mod - 2);
	for (int k = 2; k < n; k *= 2) {
		ll z[] = {1, modpow(root, curL /= 2)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	ntt(L, rt, rev, n);
	rep(i,0,n) out[-i & (n-1)] = (modpow(L[i], to) * inv) % mod;
	ntt(out, rt, rev, n);
	return {out.begin(), out.begin() + s};
}


ll DP[2001][4001] = {0};
bool DPC[2001][4001] = {0};

vl A;

ll dp(ll i, ll diff){
    if(i == n)return (diff == 2000);
    if(diff >= 4001)return 0;
    if(DPC[i][diff])return DP[i][diff];
    ll ans = 0;
    ll nex = (i+1)%n;
    if(A[i] == A[nex]){
        ans = (k*dp(i+1,diff))%mod;
    }
    else{
        ans = (dp(i+1,diff+1) + dp(i+1,diff-1) + (k-2)*dp(i+1,diff))%mod;
    }
    DPC[i][diff] = 1;
    DP[i][diff] = ans;
    return ans;
}

ll diffs = 0;

vl diffv;
vl res;

void fast(){
    res.push_back(0);
    res.push_back(0);
    for(int c1 = sz(res)-1; c1 >= 0; c1--){
        if(c1 > 1)res[c1] += res[c1-2];
        if(c1 > 0)res[c1] += (k-2)*res[c1-1];
        res[c1] %= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
    rep(c1,0,n){
        cin >> a;
       // a = random2()%k + 1;
        A.push_back(a);
    }

    ll sames = 0;

    rep(c1,0,n){
        if(A[c1] == A[(c1+1)%n]){
            sames++;
        }
    }
    diffs = n-sames;
    ll look = n-sames;

    ll extra = 1;
    rep(c1,0,sames){
        extra *= k;
        extra %= mod;
    }


    diffv.push_back(1);
    diffv.push_back(k-2);
    diffv.push_back(1);

    res.push_back(1);
/*
    for(ll c1 = 30; c1 >= 0; c1--){
        res = conv(res,res);

        if((diffs & (1 << c1)) != 0){
            //res = conv(res, diffv);
            fast();
        }
    }
*/

    res = ex(diffv, diffs);

/*
    cerr << diffs << "\n";
    rep(c1,0,sz(res)){
        cerr << res[c1] << " ";
    }cerr << "\n";
*/


    ll ans = 0;

    rep(c1,look+1,sz(res)){
        ans += res[c1];
       // cerr << res[c1] << "  dfs\n";
        ans %= mod;
    }
    ans *= extra;
    ans %= mod;

    cout << ans << "\n";

    return 0;
}