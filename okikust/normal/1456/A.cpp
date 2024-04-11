#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
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


int main() {
	int  t, n, p, k;
	char a[N];
	int x, y;
	int s,ans;
	rep(i, N)a[i] = 0;
	int xx, yy;
	cin >> t;
	rep(tt, t) {
		cin >> n >> p >> k;
		cin >> a;
		cin >> xx >> yy;
		ans = 2000000000;
		rep(i, k) {
			x = n - i;
			s = 0;
			while (x >= p) {
				if (a[x - 1] == '0')s += xx;
				y = ((x - p)*yy) + s;
				ans = min(ans, y);
				x -= k;
			}
		}
		cout << ans << endl;
		rep(i, n + 1)a[i] = 0;
	}


	return 0;
}