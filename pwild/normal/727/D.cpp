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

string shirt[] = {"S","M","L","XL","XXL","XXXL"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vl cnt(6);
	FOR(i,0,6) cin >> cnt[i];
	
	queue<ll> q[11];
	ll n; cin >> n;
	vl type(n), get(n);
	FOR(i,0,n) {
		string s; cin >> s;
		if (s[0] == 'S') type[i] = 0;
		else if (s[0] == 'M') type[i] = 2;
		else {
			type[i] = 4;
			while (s[0] == 'X') type[i] += 2, s = s.substr(1);
		}
		if (find(all(s),',') != end(s)) type[i]++;
		q[type[i]].push(i);
	}
	
	bool ok = true;
	FOR(i,0,6) {
		while (sz(q[2*i])) {
			ll j = q[2*i].front(); q[2*i].pop();
			if (cnt[i]) cnt[i]--, get[j] = i;
			else ok = false;
		}
	}
	FOR(i,0,5) {
		while (sz(q[2*i+1])) {
			ll j = q[2*i+1].front(); q[2*i+1].pop();
			if (cnt[i]) cnt[i]--, get[j] = i;
			else if (cnt[i+1]) cnt[i+1]--, get[j] = i+1;
			else ok = false;
		}
	}
	if (!ok) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	FOR(i,0,n) cout << shirt[get[i]] << "\n";
}