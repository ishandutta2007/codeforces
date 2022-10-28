#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
    FT(){};
	void upd(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll qry(int pos) { 
		ll res = 0;
		for (++pos; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
    ll qry(int l, int r){ return qry(r)-qry(l-1); }
};

const int MAXA = 3e5+10;

FT sm(MAXA+1), cnt(MAXA+1), me(MAXA+1);
int n, a[MAXN];
ll pr[MAXN];


#define int ll
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        ll ans = 0;
        for (int j = 0; j < MAXA; j += a[i]) {
            int k = min<int>(MAXA-1, j+a[i]-1);

            ans += sm.qry(j, k)-j*cnt.qry(j, k);
        }
        sm.upd(a[i], a[i]), cnt.upd(a[i], 1);
        pr[i] = ans;
    }
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < MAXA; j += a[i]) {
            int k = min<int>(MAXA-1, j+a[i]-1);
            me.upd(j, j);
            me.upd(k+1, -j);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < MAXA; j += a[i]) {
            int k = min<int>(MAXA-1, j+a[i]-1);
            me.upd(j, -j);
            me.upd(k+1, j);
        }

        pr[i] -= me.qry(a[i]);
        pr[i] += a[i]*i;
    }
    for (int i = 0; i < n; i++) {
        if (i) pr[i] += pr[i-1];
        cout << pr[i] << ' ';
    }

    //me mod them
    // [...]
    cout << '\n';
}
#undef int
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}