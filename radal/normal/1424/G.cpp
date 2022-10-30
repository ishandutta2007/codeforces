#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

map<ll, ll> pnt, pnt_rev;
ll D[MAXN], B[MAXN], n;
vector<pll> v;
set<ll> pv;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back({x, y});
		pv.insert(x);
		pv.insert(y);
	}

	ll ind = 0;
	for (ll u : pv) {
		ind++;
		pnt[u] = ind;
		pnt_rev[ind] = u;
	}

	for (int i = 0; i < v.size(); i++) v[i].X = pnt[v[i].X], v[i].Y = pnt[v[i].Y], B[v[i].X]++, D[v[i].Y]++;
	ll cnt = 0, mx = 0, mx_pnt = 0;
	for (int i = 0; i < MAXN; i++) {
		cnt -= D[i];
		cnt += B[i];
		if (cnt > mx) mx = cnt, mx_pnt = i;
	}

	cout << pnt_rev[mx_pnt] << sep << mx << endl; 
	return 0;
}