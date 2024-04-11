#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	ll t;
	ll n;
	vector<ll>a;
	vector<ll>m;
	ll x;
	ll ans;
	ll cur, nxt;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		a.clear();
		m.clear();
		rep(i, n) {
			cin >> x;
			a.pb(x);
			m.pb(-1);
		}
		ans = 0;
		rep(i, n) {
			if (a[i] > (n - i)) {
				ans += (a[i] - (n - i));
				a[i] = n - i;
			}
			while (a[i] > 1) {
				cur = i;
                ans++;
				while (cur < n) {
					nxt = cur + a[cur];
					a[cur] = max((ll)1, a[cur] - 1);
					if (m[cur] >= 0)cur = m[cur];
					else cur = nxt;
					
				}
			}
			nxt = n;
			rep3(j, n - 1, 0) {
				if (a[j] > 1)nxt = j;
				else m[j] = nxt;
			}
		}
		cout << ans << endl;
	}
	return 0;
}