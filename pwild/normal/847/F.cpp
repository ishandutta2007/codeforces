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

struct election {
	ll n, k, m, a;
	vl cnt, last;
	
	election(ll n, ll k, ll m, ll a): n(n), k(k), m(m), a(a), cnt(n), last(n,-oo) { }

	void cast(ll candidate, ll time) {
		cnt[candidate]++;
		last[candidate] = time;
	}
	
	bool is_elected(ll i) {
		if (cnt[i] == 0) return false;
		ll rank = 0;
		FOR(j,0,n) rank += cnt[j] > cnt[i] || (cnt[j] == cnt[i] && last[j] < last[i]);
		return rank < k;
	}

/*
	ll calc(ll i) {
		{
			ll maxv = cnt[i] + m-a;
			if (maxv == 0) return 3;
			ll better = 0;
			FOR(j,0,n) if (j != i) {
				ll lasti = (a < m) ? m-1 : last[i];
				better += cnt[j] > cnt[i] || (cnt[j] >= cnt[i] && last[j] < lasti);
			}
			if (better >= k) return 3;
		}
		
		if (cnt[i] == 0) return 2;

		vl need(n);
		need[i] = oo;
		FOR(j,0,n) if (j != i) {
			if (cnt[j] > cnt[i] || (cnt[j] == cnt[i] && last

		}


	}*/
};

ll go(election e, ll i) {
	ll n = e.n, k = e.k, m = e.m, a = e.a;
	
	election e3 = e;
	FOR(t,a,m) e3.cast(i,t);
	if (!e3.is_elected(i)) return 3;
	
	election e1 = e;
	
	if (!e1.is_elected(i)) return 2;

	vl need(n);
	need[i] = oo;
	FOR(j,0,n) if (j != i) {
		bool better = e1.cnt[j] > e1.cnt[i] || (e1.cnt[j] == e1.cnt[i] && e1.last[j] < e1.last[i]);
		need[j] = better ? 0 : e1.cnt[i]+1-e1.cnt[j];
	}
	sort(all(need));
	
	ll cnt = 0;
	FOR(j,0,k) cnt += need[j];
	return (cnt > m-a) ? 1 : 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k, m, a;
	cin >> n >> k >> m >> a;
	
	election e(n,k,m,a);
	
	FOR(t,0,a) {
		ll v; cin >> v;
		e.cast(v-1,t);
	}

	FOR(i,0,n) cout << go(e,i) << " \n"[i+1==n];
}