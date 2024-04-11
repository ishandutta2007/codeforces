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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

bool is_op(char c) {
	for (char d: "$^#&") if (c == d) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<string,ll> var2node;
	ll m = 0;
	vector<tuple<char,ll,ll>> nodes;
	vector<string> original_var;
	map<tuple<char,ll,ll>,ll> operations;

	auto add_node = [&](string a) {
		original_var.pb(a);
		nodes.eb('=',-1,m);
		var2node[a] = m++;
	};

	ll n; cin >> n;
	while (n--) {
		string asn; cin >> asn;
		ll ii = 0;
		while (asn[ii] != '=') ii++;

		string a = asn.substr(0,ii);
		asn = asn.substr(ii+1), ii = 0;
		while (ii < sz(asn) && !is_op(asn[ii])) ii++;
		
		if (ii == sz(asn)) {
			string b = asn;
			if (!var2node.count(b)) {
				add_node(b);
			}
			var2node[a] = var2node[b];
		} else {
			string b = asn.substr(0,ii), c = asn.substr(ii+1);
			char op = asn[ii];
			if (!var2node.count(b)) {
				add_node(b);
			}
			if (!var2node.count(c)) {
				add_node(c);
			}
			tuple<char,ll,ll> tpl = make_tuple(op,var2node[b],var2node[c]);
			if (!operations.count(tpl)) {
				nodes.pb(tpl);
				original_var.pb(a);
				operations[tpl] = m++;
			}
			var2node[a] = operations[tpl];
		}
	}
	
	if (!var2node.count("res")) {
		cout << 0 << endl;
		return 0;
	}

	auto fresh = [&]() {
		string s = "aaaa";
		while (var2node.count(s)) {
			FOR(i,0,4) s[i] = 'a' + rand() % 26;
		}
		var2node[s] = -1;
		return s;
	};
	
	vector<string> res;
	map<ll,string> new_var;

	function<string(ll)> rec = [&](ll cur) {
		if (new_var.count(cur)) return new_var[cur];
		
		char op;
		ll a, b;
		tie(op,a,b) = nodes[cur];
		if (op == '=') return original_var[cur];
		
		string stra = rec(a), strb = rec(b);
		
		string str = (cur == var2node["res"]) ? "res" : fresh();
		res.pb(str + "=" + stra + op + strb);
		return new_var[cur] = str;
	};
	
	string lst = rec(var2node["res"]);
	if (lst != "res") res.pb("res=" + lst);
	cout << sz(res) << endl;
	for (string str: res) cout << str << endl;

}