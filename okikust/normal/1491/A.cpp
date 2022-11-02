#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
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
	int n, q;
	vector<int>a;
	int x, y;
	int c1 = 0;
	cin >> n >> q;
	rep(i, n) {
		cin >> x;
		a.pb(x);
		if (x == 1)c1++;
	}
	rep(i, q) {
		cin >> x;
		if (x == 1) {
			cin >> y;
			y--;
			if (a[y] == 0) c1++;
			else c1--;
			a[y] = 1 - a[y];
		}
		else {
			cin >> y;
			if (c1 >= y)cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}