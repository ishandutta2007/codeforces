#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;


struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
        pos++;

		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it, --it;
    vector<int> loc(n); for (int i = 0; i < n; i++) loc[a[i]] = i;

    set<int> lset, rset;
    ll lsum = 0, rsum = 0;

    FT ft(n+1);
    vector<ll> inv(n);
    for (int i = 0; i < n; i++) {
        inv[i] = i-ft.query(loc[i]) + (i?inv[i-1]:0ll);
        ft.update(loc[i], 1);

        //cerr << lsum << ' ' << rsum << endl;
        if (sz(lset) && loc[i] > *lset.rbegin()) rsum += loc[i], rset.insert(loc[i]);
        else lsum += loc[i], lset.insert(loc[i]);

        //cerr << "PR\n";
        //for (auto it : lset) cerr << it << ' ';
        //cerr << endl;

        //cerr << "HERE\n";
        while (sz(lset) < sz(rset)) {
            int x = *rset.begin(); lset.insert(x), rset.erase(x);
            lsum += x, rsum -= x;
        }
        while (sz(lset) > sz(rset)+1) {
            int x = *lset.rbegin(); lset.erase(x), rset.insert(x);
            lsum -= x, rsum += x;
        }

        //cerr << "DONE\n";
        ll ans = inv[i];
        ll sz_l = sz(lset), sz_r = sz(rset), mx = *lset.rbegin();
        ans += rsum - mx*sz_r - sz_r*(sz_r+1)/2;
        ans += mx*sz_l - sz_l*(sz_l-1)/2 - lsum;
        cout << ans << ' ';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}