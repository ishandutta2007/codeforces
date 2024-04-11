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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, maxh; cin >> n >> maxh;

	vector<pll> task(n);
	FOR(i,0,n) {
		cin >> task[i].xx >> task[i].yy;
		task[i].yy = -task[i].yy;
	}
	sort(all(task));

	ll i = 0;
	priority_queue<ll,vl,greater<ll>> q;
	FOR(h,1,maxh+1) {
		if (sz(q) % 2) q.push(0);
		priority_queue<ll,vl,greater<ll>> qn;
		while (sz(q)) {	
			ll a = q.top(); q.pop();
			ll b = q.top(); q.pop();
			qn.push(a+b);
		}
		q = qn;
		while (task[i].xx == h) q.push(task[i++].yy);
	}

	cout << -q.top() << endl;

}