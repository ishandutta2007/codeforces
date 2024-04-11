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

typedef bitset<5000> bs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	
	string s;
	getline(cin,s);

	vector<vector<string>> assignments(n);

	FOR(i,0,n) {
		getline(cin,s);
		stringstream ss(s);
		while (ss >> s) assignments[i].pb(s);
	}
	
	map<string,ll> line;
	FOR(i,0,n) line[assignments[i][0]] = i;

	vector<bs> values[2];

	bs con[2];
	con[1].set();

	FOR(k,0,2) {
		values[k].resize(n);
		
		FOR(i,0,n) {
			vector<string> &a = assignments[i];
			if (sz(a) == 3) {
				values[k][i] = bs(a[2]);
			} else if (sz(a) == 5) {
				values[k][i] = (a[2] == "?") ? con[k] : values[k][line[a[2]]];
				bs &w = (a[4] == "?") ? con[k] : values[k][line[a[4]]];
				if (a[3] == "AND") values[k][i] &= w;
				else if (a[3] == "OR") values[k][i] |= w;
				else if (a[3] == "XOR") values[k][i] ^= w;
				else assert(0);
			} else assert(0);
		}
	}
	
	string bestmin(m,'.'), bestmax(m,'.');
	FOR(j,0,m) {
		ll cnt[2] = {0,0};
		FOR(k,0,2) FOR(i,0,n) cnt[k] += values[k][i][j];

		if (cnt[0] < cnt[1]) bestmin[j] = '0', bestmax[j] = '1';
		else if (cnt[0] > cnt[1]) bestmin[j] = '1', bestmax[j] = '0';
		else bestmin[j] = bestmax[j] = '0';
	}
	reverse(all(bestmin)), reverse(all(bestmax));
	cout << bestmin << endl;
	cout << bestmax << endl;

	//for (const auto &a: assignments) {
	//	for (const auto &s: a) cout << s << " ";
	//	cout << endl;
	//}
}