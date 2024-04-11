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

struct flight {
	ll day, city, cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m, k; cin >> n >> m >> k;
	
	vector<flight> fr, to;

	while (m--) {
		ll d, f, t, c;
		cin >> d >> f >> t >> c;
		if (f) to.pb({d,f-1,c});
		if (t) fr.pb({d,t-1,c});
	}
	sort(all(to),[&](const flight &f, const flight &g) { return f.day < g.day; });
	sort(all(fr),[&](const flight &f, const flight &g) { return f.day > g.day; });

	const ll T = 1e6 + 2;
	
	vl to_cost(T+1,0);
	vl best_to_cost(n,oo);
	vl to_cnt(T+1,0);
	
	ll to_pnt = 0;
	FOR(day,1,T+1) {
		to_cnt[day] = to_cnt[day-1];
		to_cost[day] = to_cost[day-1];
		while (to_pnt < sz(to) && to[to_pnt].day == day) {
			flight f = to[to_pnt];
			if (best_to_cost[f.city] == oo) {
				best_to_cost[f.city] = f.cost;
				to_cost[day] += f.cost;
				to_cnt[day]++;				
			} else if (f.cost < best_to_cost[f.city]) {
				to_cost[day] += f.cost - best_to_cost[f.city];
				best_to_cost[f.city] = f.cost;
			}
			to_pnt++;
		}
	}

	vl fr_cost(T+1,0);
	vl best_fr_cost(n,oo);
	vl fr_cnt(T+1,0);
	
	ll fr_pnt = 0;
	FORD(day,0,T) {
		fr_cnt[day] = fr_cnt[day+1];
		fr_cost[day] = fr_cost[day+1];
		while (fr_pnt < sz(fr) && fr[fr_pnt].day == day) {
			flight f = fr[fr_pnt];
			if (best_fr_cost[f.city] == oo) {
				best_fr_cost[f.city] = f.cost;
				fr_cost[day] += f.cost;
				fr_cnt[day]++;				
			} else if (f.cost < best_fr_cost[f.city]) {
				fr_cost[day] += f.cost - best_fr_cost[f.city];
				best_fr_cost[f.city] = f.cost;
			}
			fr_pnt++;
		}
	}

	ll res = oo;
	FOR(day,1,T+1) {
		if (to_cnt[day-1] < n) continue;
		if (day+k > T) continue;
		if (fr_cnt[day+k] < n) continue;

		res = min(res, to_cost[day-1]+fr_cost[day+k]);
	}
	if (res == oo) res = -1;
	cout << res << endl;
}