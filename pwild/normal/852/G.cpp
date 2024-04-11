#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f;
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

const ll N = 6e6;
ll S = 1;
ll go[N][5], last_match[N], cnt[N];

void insert(string s) {
	ll cur = 0;
	for (char c: s) {
		if (go[cur][c-'a'] == -1) go[cur][c-'a'] = S++;
		cur = go[cur][c-'a'];
	}
	cnt[cur]++;
}

ll rec(string &s, ll q, ll i, ll cur) {
	if (cur == -1) return 0;
	if (i == sz(s)) {
		if (last_match[cur] < q) {
			last_match[cur] = q;
			return cnt[cur];
		}
		return 0;
	}
	if (s[i] == '?') {
		ll res = rec(s,q,i+1,cur);
		FOR(j,0,5) res += rec(s,q,i+1,go[cur][j]);
		return res;
	} else {
		return rec(s,q,i+1,go[cur][s[i]-'a']);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m; cin >> n >> m;
	
	memset(go,-1,sizeof go);
	while (n--) {
		string s; cin >> s;
		insert(s);
	}
	FOR(q,1,m+1) {
		string s; cin >> s;
		cout << rec(s,q,0,0) << endl;
	}
}