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
	
	vector<string> s(3);
	FOR(i,0,3) cin >> s[i];
	vvl cnt(3,vl(26));
	FOR(i,0,3) FOR(j,0,sz(s[i])) cnt[i][s[i][j]-'a']++;
	
	ll bestk1 = 0, bestk2 = 0;
	FOR(k1,0,sz(s[0])+1) {
		bool ok = true;
		FOR(c,0,26) if (cnt[0][c] < cnt[1][c]*k1) ok = false;
		if (!ok) break;
		ll k2 = sz(s[0]);
		FOR(c,0,26) if (cnt[2][c]) k2 = min(k2,(cnt[0][c]-k1*cnt[1][c])/cnt[2][c]);
		if (k1 + k2 > bestk1 + bestk2) bestk1 = k1, bestk2 = k2;
	}
	FOR(i,0,bestk1) cout << s[1];
	FOR(i,0,bestk2) cout << s[2];
	FOR(c,0,26) cnt[0][c] -= bestk1*cnt[1][c] + bestk2*cnt[2][c];
	FOR(c,0,26) FOR(i,0,cnt[0][c]) cout << char('a'+c);
	cout << endl;

}