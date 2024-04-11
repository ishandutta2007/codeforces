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

const ll Q = 100100;

ll m, n;
ll type[Q], p[Q], a[Q], b[Q], res[Q];
vl ch[Q];

bool bk[1010][1010];
bool row[1010];
ll rowsum[1010];
ll sum = 0;

bool is_book(ll i, ll j) { return row[i] ^ bk[i][j]; }

void toggle_book(ll i, ll j) {
	ll d = is_book(i,j) ? -1 : 1;
	rowsum[i] += d;
	sum += d;
	bk[i][j] = !bk[i][j];
}

void toggle_row(ll i) {
	sum += n - 2*rowsum[i];
	rowsum[i] = n - rowsum[i];
	row[i] = !row[i];
}

void dfs(ll x) {
	ll i = a[x], j = b[x];
	bool tij = type[x] < 3 && (is_book(i,j) == (type[x] == 2));
	bool ti = type[x] == 3;
	if (tij) toggle_book(i,j);
	if (ti) toggle_row(i);
	res[x] = sum;
	for (ll y: ch[x]) dfs(y);
	if (tij) toggle_book(i,j);
	if (ti) toggle_row(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll q; cin >> m >> n >> q;
	
	FOR(i,1,q+1) {
		cin >> type[i] >> a[i];
		if (type[i] < 3) cin >> b[i];
		
		if (type[i] == 4) {
			p[i] = p[a[i]];
		} else {
			p[i] = i;
			ch[p[i-1]].pb(i);
		}
	}
	for (ll y: ch[0]) dfs(y);
	
	FOR(i,1,q+1) cout << res[p[i]] << "\n";
}