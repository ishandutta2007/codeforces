#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;

const int N = 1e6 + 7;
mt19937_64 orz(time(0) ^ clock());
ll Mul(ll x, ll y, ll mod) {
	ll o = x * y - (ll) ((long double) x * y / mod + 0.1) * mod;
	return o < 0 ? o + mod : o;
}
ll qpow(ll x, ll y, ll mod) {
	ll res = 1;
	for(; y; x = Mul(x, x, mod), y >>= 1) if(y & 1) res = Mul(res, x, mod);
	return res;
}
const int testp[8] = {2, 3, 5, 7, 13, 17, 61, 233};
bool MR(ll x) {
	if(x <= testp[7]) {
		L(i, 2, sqrt(x)) if(x % i == 0) return false;
		return true;
	}
	int j, k = 0; ll a = x - 1;
	for(; ! (a & 1); a >>= 1, ++k) ;
	L(i, 0, 7) {
		ll z = qpow(testp[i], a, x);
		if(z == 1 || z == x - 1) continue;
		for(j = 0; j < k; ++j) {
			z = Mul(z, z, x);
			if(z == x - 1) break;
		}
		if(j == k) return false;
	}
	return true;
}
int top;
ll f[N], seed;
ll PR(ll x) {
	seed = orz() % (x - 1) + 1, top = 0;
	ll val1 = seed, val2 = seed, prd = 1;
	while(1) {
		val1 = (Mul(val1, val1, x) + seed) % x;
		val2 = (Mul(val2, val2, x) + seed) % x;
		val2 = (Mul(val2, val2, x) + seed) % x;
		f[++top] = abs(val1 - val2), prd = Mul(prd, f[top], x); 
		if(top == 100) {
			if(__gcd(prd, x) > 1) break;
			top = 0, prd = 1;
		}
	}
	L(i, 1, top) if(__gcd(f[i], x) > 1) return __gcd(f[i], x);
	return assert(0), 114514;
}
ll a[N];
int tot;
void solve(ll x) {
	if(x == 1) return;
	if(MR(x)) return a[++tot] = x, void();
	ll t = PR(x);
	while(t == x) t = PR(x);
	solve(t), solve(x / t);
}
void get(ll x) {
	tot = 0;
	L(i, 2, testp[7]) while(x % i == 0) a[++tot] = i, x /= i;
	solve(x);
	sort(a + 1, a + tot + 1);
}

int n;
ll w[N], h[N], c[N];
map < pair < ll, ll >, ll > mp;
map < ll, ll > W, H;
ll all;
ll arr1[N], arr2[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	ll A = 0;
	L(i, 1, n) cin >> w[i] >> h[i] >> c[i], mp[make_pair(w[i], h[i])] += c[i], W[w[i]] += c[i], H[h[i]] += c[i], all += c[i], 
		A = __gcd(A, c[i]);
	for(auto u : W) {
		for(auto v : H) {
			ll dnt = mp[make_pair(u.first, v.first)];
			if((__int128) v.second * u.second != (__int128) dnt * all)
				return cout << 0 << '\n', 0;
			if((__int128) u.second * v.second != (__int128) dnt * all)
				return cout << 0 << '\n', 0;
		} 
	}
	
	ll prd = 1, cnt = 0;
	get(A);
	L(i, 1, tot) {
		if(a[i] != a[i - 1]) prd *= cnt + 1, cnt = 0;
		++cnt;
	}
	prd *= cnt + 1;
	cout << prd << '\n';
	return 0;
}