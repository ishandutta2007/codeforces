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
	int t;
	int x, y;
	vector<int> a, b;
	int c, d;
	bool v;
	cin >> t;
	rep(tt, t) {
		v = true;
		cin >> x >> y;
		if (x > y)v = false;
		a.clear();
		b.clear();
		rep(i, 30) {
			if (x % 2 == 1)a.pb(i);
			if (y % 2 == 1)b.pb(i);
			x /= 2;
			y /= 2;
		}
		c = a.size();
		d = b.size();
		if (c < d)v = false;
		else {
			rep(i, d)if (b[i] < a[i])v = false;
		}
		if (v)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}