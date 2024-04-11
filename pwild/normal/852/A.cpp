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

string str(ll n) {
	string res;
	for (; n; n /= 10) res += char('0' + n%10);
	reverse(all(res));
	return res;
}

string step(string s, bool pr = false) {
	ll sum = 0;
	FOR(i,0,sz(s)) {
		if (pr) {
			if (i) cout << "+";
			cout << s[i];
		}
		sum += s[i]-'0';
	}
	if (pr) cout << endl;
	return str(sum);
}

const ll N = 3e6;
ll dp[N];

mt19937 gen;

bool random_splitting(string s) {	
	ll n = sz(s);
	vb split(n-1,true);
	uniform_int_distribution<int> dis(0,n-2);
	
	vl glues(n-1);
	iota(all(glues),0);
	shuffle(all(glues),gen);

	ll sum = 0, cur = 0;
	FOR(i,0,n) {
		cur = 10*cur + s[i]-'0';
		if (i < n-1 && split[i]) sum += cur, cur = 0;
	}
	sum += cur;

	auto part = [&](ll i, ll j) {
		ll res = 0;
		while (i < j) res = 10*res + s[i++]-'0';
		return res;
	};
	
	for (ll g: glues) {
		if (sum >= N) break;
		if (sum < N && dp[sum] <= 2) {
			cur = 0;
			FOR(i,0,n) {
				cout << s[i];
				if (i < n-1 && split[i]) cout << "+";
			}
			cout << endl;
			step(step(str(sum),true),true);
			return true;
		}
		
		split[g] = false;
		
		ll pg = g-1;
		while (pg >= 0 && !split[pg]) pg--;
		ll ng = g+1;
		while (ng < n-1 && !split[ng]) ng++;
		
		if (ng-pg > 7) break;

		sum -= part(pg+1,g+1) + part(g+1,ng+1);
		sum += part(pg+1,ng+1);
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(n,1,10) dp[n] = 0;
	FOR(n,10,N) {
		ll ds = 0;
		for (ll m = n; m; m /= 10) ds += m % 10;
		dp[n] = dp[ds]+1;
	}
	
	string s; cin >> s >> s;
	
	ll ds = 0;
	for (char c: s) ds += c-'0';
	
	if (sz(s) == 1) {
		cout << s << endl;
		cout << s << endl;
		cout << s << endl;
		return 0;
	}
	while (!random_splitting(s)) { }
}