#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
const int MAXN = 400005;
const ll MOD = 998244353;
 
bool comparelen(vll v1, vll v2) {
	return v1.size() > v2.size();
}
ll powA(ll a, ll e) {
	if(e == 0) return 1;
	if(e == 1) return a;
	ll r = powA(a, e >> 1);
	r = r*r % MOD;
	if(e & 1) r = a*r%MOD;
	return r;
}
vll gen(int n) {
	ll r = powA(3, (MOD-1LL)/n);
	vll v;
	v.pb(1);
	ll c = 1;
	F0R(i, n-1) v.pb(c = c*r % MOD);
	return v;
}
void fft(vll& v, vll& r, int n, bool inverse) {
	for(int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		while(j & bit) {
			j ^= bit;
			bit >>= 1;
		}
		j ^= bit;
		if(i < j) swap(v[i], v[j]);
	}
	for(int l = 2; l <= n; l <<= 1)
		for(int i = 0; i < n; i += l)
			F0R(j, l/2) {
				int rind = n/l*j; if(inverse && rind != 0) rind = (n-rind);
				ll a = v[i+j], b = v[i+j+l/2]*r[rind] % MOD;
				v[i+j] = (a+b)%MOD; v[i+j+l/2] = (MOD+a-b)%MOD;
			}
	if(inverse) {
		ll inv = powA(n, MOD-2LL);
		F0R(i, n) v[i] = (v[i]*inv)%MOD;
	}
}
vll mult(vll v1, vll v2) {
	int sz = v1.size() + v2.size() - 1, n = 1 << 32-__builtin_clz(sz-1);
	vll roots = gen(n);
	v1.resize(n); v2.resize(n);
	fft(v1, roots, n, false); fft(v2, roots, n, false);
	vll res;
	F0R(i, n) res.pb(v1[i]*v2[i]);
	fft(res, roots, n, true);
	res.resize(sz);
	return res;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    unordered_map<int,int> m;
    F0R(i, n) {
    	int a; cin >> a;
    	m[a]++;
    }
    priority_queue<vll, vector<vll>, std::function<bool(vll,vll)>> pq(comparelen);
    for(auto x : m) {
    	vll v(x.s+1);
    	fill(v.begin(), v.end(), 1);
    	pq.push(v);
    }
    while(pq.size() >= 2) {
    	vll v1 = pq.top(); pq.pop();
    	vll v2 = pq.top(); pq.pop();
    	vll res = mult(v1,v2);
    	pq.push(res);
    }
    vll ans = pq.top();
    cout << ans[ans.size()/2] << endl;
    cin >> n;
    return 0;
}