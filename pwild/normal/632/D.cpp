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
	
	ll n, m; cin >> n >> m;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vl cnt(m+1);
	FOR(i,0,n) if (a[i] <= m) cnt[a[i]]++;
	vl cntdiv(m+1);
	FOR(i,1,m+1) for (ll j = i; j <= m; j += i) cntdiv[j] += cnt[i];
	
	ll bestx = 1;
	FOR(x,1,m+1) if (cntdiv[x] > cntdiv[bestx]) bestx = x;

	cout << bestx << " " << cntdiv[bestx] << endl;
	ll j = 0;
	FOR(i,0,n) if (bestx % a[i] == 0) {
		cout << i+1;
		if (++j == cntdiv[bestx]) cout << endl; else cout << " ";
	}

}