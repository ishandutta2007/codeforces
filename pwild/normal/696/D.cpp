#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const ll M = 300, K = 26;
ll cnt = 1;
struct state {                        
	ll pred, lastc, link, go[K];
	bitset<200> mask;
} st[M];

const bitset<200> zeros;

ll go(ll i, ll c);

ll link(ll i) {
	if (st[i].link != -1) return st[i].link;
	if (!i || !st[i].pred) return st[i].link = 0;
	return st[i].link = go(link(st[i].pred),st[i].lastc);
}

ll go(ll i, ll c) {
	if (st[i].go[c] != -1) return st[i].go[c];
	if (!i) return st[i].go[c] = 0;
	return st[i].go[c] = go(link(i),c);
}

bitset<200> mask(ll i, vb &mark) {
	if (mark[i]) return st[i].mask;
	mark[i] = true;
	st[i].mask |= mask(link(i),mark);
	return st[i].mask;
}

void add_string(const string &s, ll j) {
	ll i = 0;
	for (const char &cc: s) {
		ll c = cc-'a';
		if (st[i].go[c] == -1) {
			st[cnt] = {i,c,-1,{},zeros};
			fill_n(st[cnt].go,K,-1);
			st[i].go[c] = cnt++;            
		}
		i = st[i].go[c];
	}
	st[i].mask.set(j);
}

vvl operator*(const vvl &a, const vvl &b) {
	ll n = sz(a);
	vvl c(n,vl(n,-oo));
	FOR(i,0,n) FOR(k,0,n) FOR(j,0,n) c[i][j] = max(c[i][j],a[i][k]+b[k][j]);
	return c;
}

vvl power(vvl a, ll k) {
	ll n = sz(a);
	vvl res(n,vl(n,-oo));
	FOR(i,0,n) res[i][i] = 0;
	while (k) {
		if (k & 1) res = res*a;
		a = a*a;
		k /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	cnt = 1;
	st[0] = {0,-1,0,{},zeros};
	fill_n(st[0].go,K,-1);
	
	FOR(i,0,n) {
		string s; cin >> s;
		add_string(s,i);
	}
	
	vb mark(cnt);
	FOR(i,0,cnt) {
		link(i);
		FOR(c,0,K) go(i,c);
		mask(i,mark);
	}
	
	vvl A(cnt,vl(cnt,-oo));
	FOR(i,0,cnt) FOR(c,0,K) {
		ll j = st[i].go[c], w = 0;
		FOR(h,0,n) if (st[j].mask[h]) w += a[h];
		A[i][j] = max(A[i][j],w);
	}
	
	A = power(A,k);
	
	ll res = 0;
	FOR(i,0,cnt) res = max(res,A[0][i]);
	cout << res << endl;
}