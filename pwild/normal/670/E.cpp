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
	
	ll n, m, p; cin >> n >> m >> p;
	p--;
	string s; cin >> s;
	list<char> a(all(s));
	auto it = begin(a);
	FOR(i,0,p) it++;
	string q; cin >> q;
	FOR(i,0,m) {
		if (q[i] == 'L') it--;
		if (q[i] == 'R') it++;
		if (q[i] == 'D') {
			if (*it == '(') {
				ll d = 0;
				do {
					if (*it == '(') d++; else d--;
					auto oit = it++;
					a.erase(oit);
				} while (d);
				if (it == end(a)) it--;
			} else {
				ll d = 0;
				do {
					if (*it == '(') d--; else d++;
					auto oit = it--;
					a.erase(oit);
				} while (d);
				it++;
				if (it == end(a)) it--;
			}
		}

	}
	cout << string(all(a)) << endl;
}