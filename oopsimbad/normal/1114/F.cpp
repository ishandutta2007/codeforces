#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

const int MAXN = 400005;
const ll MOD = 1e9+7;

ll bseg[4*MAXN], mseg[4*MAXN], blz[4*MAXN], mlz[4*MAXN];

ll exp(ll b, ll e) {
    if(e == 0) return 1;
    if(e == 1) return b;
    ll res = exp(b,e >> 1);
    res *= res;
    res %= MOD;
    if(e & 1) {
        res *= b;
        res %= MOD;
    }
    return res;
}

void bprop(int li, int ri, int i) {
    if(li != ri-1) {
        blz[2*i+1] |= blz[i];
        blz[2*i+2] |= blz[i];
    }
    bseg[i] |= blz[i];
    blz[i] = 0;
}
ll bget(int l, int r, int li, int ri, int i) {
    if(l < li) l = li;
    if(r > ri) r = ri;
    if(r <= li || l >= ri) return 0;
    if(blz[i] != 0) bprop(li, ri, i);
    if(l == li && r == ri) return blz[i] | bseg[i];
    else {
        int m = (li+ri)/2;
        return bget(l, r, li, m, 2*i+1) | bget(l, r, m, ri, 2*i+2);
    }
}
void bupd(int l, int r, int li, int ri, int i, ll v) {
    if(l < li) l = li;
    if(r > ri) r = ri;
    if(r <= li || l >= ri) return;
    if(l == li && r == ri) {
        blz[i] |= v;
        if(blz[i] != 0) bprop(li, ri, i);
    } else {
        int m = (li+ri)/2;
        if(blz[i] != 0) bprop(li, ri, i);
        bupd(l, r, li, m, 2*i+1, v);
        bupd(l, r, m, ri, 2*i+2, v);
        bseg[i] = bseg[2*i+1] | bseg[2*i+2];
    }
}
void mprop(int li, int ri, int i) {
    if(li != ri-1) {
        mlz[2*i+1] *= mlz[i];
        mlz[2*i+1] %= MOD;
        mlz[2*i+2] *= mlz[i];
        mlz[2*i+2] %= MOD;
    }
    mseg[i] *= exp(mlz[i], ri-li);
    mseg[i] %= MOD;
    mlz[i] = 1;
}
ll mget(int l, int r, int li, int ri, int i) {
    if(l < li) l = li;
    if(r > ri) r = ri;
    if(r <= li || l >= ri) return 1;
    if(mlz[i] != 1) mprop(li, ri, i);
    if(l == li && r == ri) return mlz[i] * mseg[i] % MOD;
    else {
        int m = (li+ri)/2;
        return mget(l, r, li, m, 2*i+1) * mget(l, r, m, ri, 2*i+2) % MOD;
    }
}
void mupd(int l, int r, int li, int ri, int i, ll v) {
    if(l < li) l = li;
    if(r > ri) r = ri;
    if(r <= li || l >= ri) return;
    if(l == li && r == ri) {
        mlz[i] *= v;
        mlz[i] %= MOD;
        if(mlz[i] != 1) mprop(li, ri, i);
    } else {
        int m = (li+ri)/2;
        if(mlz[i] != 1) mprop(li, ri, i);
        mupd(l, r, li, m, 2*i+1, v);
        mupd(l, r, m, ri, 2*i+2, v);
        mseg[i] = exp(v, r-l) * mseg[i] % MOD;
    }
}

vector<ll> primes;
vector<ll> inv;
ll getBits(ll v) {
    ll res = 0;
    F0R(i, primes.size())
        if(v % primes[i] == 0)
            res |= 1LL << i;
    return res;
}
ll gcd(ll a, ll b, ll *x, ll *y)  { 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1;
    int res = gcd(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return res; 
} 
ll minv(int i) {
    ll x, y;
    gcd(i, MOD, &x, &y);
    return ((x % MOD) + MOD) % MOD;
}
void calcPrimes() {
    bool sieve[301];
    F0R(i, 301) sieve[i] = false;
    FOR(i, 2, 301) {
        if(!sieve[i]) {
            primes.pb(i);
            inv.pb(minv(i));
            for(int j = i*i; j <= 300; j += i)
                sieve[j] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q; cin >> n >> q;
    calcPrimes();
    F0R(i, 4*n) {
        mseg[i] = mlz[i] = 1;
        bseg[i] = blz[i] = 0;
    }
    F0R(i, n) {
        int a; cin >> a;
        mupd(i, i+1, 0, n, 0, a);
        bupd(i, i+1, 0, n, 0, getBits(a));
    }
    while(q--) {
        string s; cin >> s;
        if(s == "MULTIPLY") {
            int l, r; ll v; cin >> l >> r >> v;
            mupd(--l, r, 0, n, 0, v);
            bupd(l, r, 0, n, 0, getBits(v));
        } else {
            int l, r; cin >> l >> r;
            ll prod = mget(--l, r, 0, n, 0);
            ll bits = bget(l, r, 0, n, 0);
            F0R(i, primes.size()) {
                if((1LL << i) > bits) break;
                if(bits & (1LL << i)) {
                    prod = prod * ((1 + MOD - inv[i]) % MOD) % MOD;
                }
            }
            cout << prod << endl;
        }

    }
    return 0;
}