#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll a[30];
unordered_map<ll,ll> vl[30], vr[30];
ll fac[20];

int main() {
	ios_base::sync_with_stdio(false);
	fac[0] = 1;
	FOR(i,1,19) fac[i] = fac[i-1]*i;

	ll n, k, s; cin >> n >> k >> s;
	FOR(i,0,n) cin >> a[i];
	FOR(mask1,0,1 << (n/2)) {
		for (ll mask2 = mask1; ; mask2 = (mask2-1) & mask1) {
			bool ok = true;
			ll cur = 0;
			FOR(i,0,n/2) {
				if (mask2 & (1 << i)) {
					if (a[i] > 18) { ok = false; break; }
					cur += fac[a[i]];
				} else if (mask1 & (1 << i)) {
					cur += a[i];
				}
			}
			if (!ok) continue;
			vl[__builtin_popcount(mask2)][cur]++;
			if (mask2 == 0) break;
		}
	}
	FOR(mask1,0,1 << ((n+1)/2)) {
		for (ll mask2 = mask1; ; mask2 = (mask2-1) & mask1) {
			bool ok = true;
			ll cur = 0;
			FOR(i,0,(n+1)/2) {
				if (mask2 & (1 << i)) {
					if (a[n/2+i] > 18) { ok = false; break; }
					cur += fac[a[n/2+i]];
				} else if (mask1 & (1 << i)) {
					cur += a[n/2+i];
				}
			}
			if (!ok) continue;
			vr[__builtin_popcount(mask2)][cur]++;
			if (mask2 == 0) break;
		}
	}
	ll res = 0;
	FOR(kl,0,k+1) FOR(kr,0,k+1) if (kl+kr <= k) {
		for (const auto &p: vl[kl]) if (has(vr[kr],s-p.xx)) {
			res += p.yy * vr[kr][s-p.xx];
		}
	}
	cout << res << endl;

}