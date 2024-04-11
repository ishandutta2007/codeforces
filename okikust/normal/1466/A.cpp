#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int t, n, k;
	int x, y, z;
	int s, ans;
	vector<int>a;
	vector<int>b;
	bool v;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		a.clear();
		rep(i, n) {
			cin >> x;
			a.pb(x);
		}
		b.clear();
		rep(i, n) {
			rep(j, i) {
				b.pb(a[i] - a[j]);
			}
		}
		sort(all(b));
		k = b.size();
		ans = 0;
		x = -1;
		rep(i, k) {
			if (x < b[i]) {
				ans++;
				x = b[i];
			}
		}
		cout << ans << endl;
	}


	return 0;
}