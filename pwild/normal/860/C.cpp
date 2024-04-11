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

ll parse(string &s) {
	bool ok = true;
	if (s[0] == '0') ok = false;
	ll res = 0;
	for (char c: s) {
		if (c < '0' || c > '9') ok = false;
		res = 10*res + c-'0';
	}
	if (!ok) res = -1;
	return res;
}

struct file {
	string name; ll val; bool is_ex;
};

string randstr() {
	string s(6,' ');
	FOR(i,0,6) s[i] = 'a' + rand() % 26;
	return s;
}

ll cnt[3][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	ll e = 0;
	
	vector<file> f(n);
	FOR(i,0,n) {
		cin >> f[i].name >> f[i].is_ex;
		f[i].val = parse(f[i].name);
		if (f[i].val > n) f[i].val = -1;
		e += f[i].is_ex;
	}
	
	set<ll> avail;
	FOR(i,0,n) avail.insert(i+1);
	set<ll> inds[3][2];
	
	vl val_to_ind(n+1,-1);

	FOR(i,0,n) {
		ll before = f[i].val == -1 ? 2 : (f[i].val <= e);
		ll after = f[i].is_ex;
		avail.erase(f[i].val);
		if (f[i].val != -1) val_to_ind[f[i].val] = i;
		inds[before][after].insert(i);
		cnt[before][after]++;
	}
	
	ll res = n - cnt[0][0] - cnt[1][1];
	

	if (res && !sz(avail)) {
		assert(cnt[0][1] == cnt[1][0]);
		res++;
		cout << res << endl;
		
		ll i = *begin(inds[0][1]);
		inds[0][1].erase(begin(inds[0][1]));
		avail.insert(f[i].val);

		string fresh;
		bool ok = false;
		do {
			fresh = randstr();
			ok = true;	
			FOR(i,0,n) if (f[i].name == fresh) ok = false;
		} while (!ok);
		
		cout << "move " << f[i].name << " " << fresh << "\n";
		f[i].name = fresh;
		f[i].val = -1;
		inds[2][1].insert(i);
	} else {
		cout << res << endl;
	}
	
	while (sz(avail)) {
		ll v = *begin(avail);
		avail.erase(begin(avail));
		
		ll i = -1, dst = v <= e;
		FOR(src,0,3) if (src != dst && sz(inds[src][dst])) {
			i = *begin(inds[src][dst]);
			inds[src][dst].erase(begin(inds[src][dst]));
			break;
		}
		assert(i != -1);
		if (f[i].val != -1) avail.insert(f[i].val);
		cout << "move " << f[i].name << " " << v << endl;
	}
}