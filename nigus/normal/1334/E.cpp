#pragma GCC optimize("O3")   //
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 2000001;

typedef unsigned long long ull;
typedef long double ld;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(ld(a) * ld(b) / ld(M));
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	trav(a, A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 0, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

ull D;

map<ll,vi> M;

map<ll,ll> I;
vl P;
vi F;

ll FAC[101] = {0};
ll INV[101] = {0};

vl divs;

void rec(ll i, ll x, vi &temp){
    if(i == sz(P)){
        vi temp2;
        trav(t, temp){
            temp2.push_back(t);
        }
        M[x] = temp2;
        divs.push_back(x);
        return;
    }
    ll t = 1;
    rep(c1,0,F[i]+1){
        temp.push_back(c1);
        rec(i+1,x*t,temp);
        temp.pop_back();
        t *= P[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    ll t = 1;
    rep(c1,0,101){
        FAC[c1] = t;
        INV[c1] = modpow(t,mod-2,mod);
        t *= ll(c1+1);
        t %= mod;
    }

    cin >> D;
    vector<ull> fact = factor(D);

    trav(f, fact){
        if(I.find(f) == I.end()){
            I[f] = sz(P);
            P.push_back(f);
            F.push_back(0);
        }
        F[I[f]]++;
    }

    vi temp;
    rec(0,1, temp);

    /*
    trav(d, divs){
        cerr << d << ": ";
        vi ff = M[d];
        trav(x, ff){
            cerr << x << ",";
        }cerr << "\n";
    }
    */

    cin >> q;
    rep(c1,0,q){
        ll x,y;
        cin >> x >> y;
        vi tx = M[x];
        vi ty = M[y];
        ll tn = 0;
        ll tp = 0;
        ll inv1 = 1;
        ll inv2 = 1;

        rep(c2,0,sz(P)){
            int diff = ty[c2] - tx[c2];
            if(diff < 0){
                inv1 *= INV[-diff];
                inv1 %= mod;
                tn += -diff;
            }
            if(diff > 0){
                inv2 *= INV[diff];
                inv2 %= mod;
                tp += diff;
            }
        }
        inv1 *= FAC[tn];
        inv1 %= mod;
        inv2 *= FAC[tp];
        inv2 %= mod;
        cout << (inv1*inv2)%mod << "\n";
    }


    return 0;
}