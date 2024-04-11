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

ll dc(ll n) {
	ll res = 0;
	while (n) res++, n /= 10;
	return res;
}

string minnum(vl cnt) {
	ll n = 0;
	FOR(i,0,10) n += cnt[i];
	string res(n,' ');
	if (!n) return "";
	if (n == cnt[0]) return "!";
	FOR(i,1,10) if (cnt[i]) {
		res[0] = '0'+i;
		cnt[i]--;
		break;
	}
	ll pos = 1;
	FOR(i,0,10) FOR(j,0,cnt[i]) res[pos++] = '0'+i;
	return res;
}

bool less(const string &s, const string &t) {
	if (sz(s) != sz(t)) return sz(s) < sz(t);
	return lexicographical_compare(all(s),all(t));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string ns, suff; cin >> ns >> suff;
	
	vl cnt(10);

	ll m = sz(ns);
	FOR(i,0,m) cnt[ns[i]-'0']++;
	FOR(i,0,sz(suff)) cnt[suff[i]-'0']--;
	
	FOR(k,1,1e6+10) {
		if (dc(k) + k != m) continue;
		
		vl kcnt(10);
		for (ll x = k; x; x /= 10) kcnt[x%10]++;
		
		bool ok = true;
		FOR(i,0,10) if (kcnt[i] > cnt[i]) ok = false;
		if (!ok) continue;
	
		vl ncnt(10);
		FOR(i,0,10) ncnt[i] = cnt[i] - kcnt[i];
			
		vector<string> res;
		if (suff[0] != '0') {
			string res1 = suff;
			FOR(i,0,10) FOR(j,0,ncnt[i]) res1.pb('0'+i);
			res.pb(res1);
		}

		if (k == sz(suff)) {
			res.pb(suff);
		} else if (ncnt[0] < k - sz(suff)) {
			string res2;
			FOR(i,1,10) if (ncnt[i]) {
				res2.pb('0'+i);
				ncnt[i]--;
				break;
			}
			FOR(i,0,suff[0]-'0') FOR(j,0,ncnt[i]) res2.pb('0'+i);
			ll a = 0;
			while (a < sz(suff) && suff[a] == suff[0]) a++;
			if (a < sz(suff) && suff[a] < suff[0]) {
				for (auto c : suff) res2.pb(c);
				FOR(i,suff[0]-'0',10) FOR(j,0,ncnt[i]) res2.pb('0'+i);
			} else {
				FOR(j,0,ncnt[suff[0]-'0']) res2.pb(suff[0]);
				for (auto c : suff) res2.pb(c);
				FOR(i,suff[0]-'0'+1,10) FOR(j,0,ncnt[i]) res2.pb('0'+i);

			}
			res.pb(res2);	
		}
		if (!sz(res)) continue;
		if (sz(res) == 1) cout << res[0] << endl;
		if (sz(res) == 2) {
			if (res[0] < res[1]) cout << res[0] << endl;
			else cout << res[1] << endl;
		}
		return 0;	

	}

}