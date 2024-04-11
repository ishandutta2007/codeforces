#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
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


int main(void){
	int t, n, k, m, ans;
	int a[N];
	int c[N];
	bool v;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		v = true;
		rep(i, n)c[i] = 0;
		rep(i, n) {
			cin >> a[i];
			a[i]--;
			c[a[i]]++;
		}
		rep(i, n) {
			if (((2 * c[i]) - 1) > n)v = false;
		}
		if (!v)cout << -1 << endl;
		else {
			rep(i, n)c[i] = 0;
			k = 0;
			c[a[0]]++;
			c[a[n - 1]]++;
			rep(i, n - 1) {
				if (a[i] == a[i + 1]) {
					c[a[i]]++;
					c[a[i + 1]]++;
					k++;
				}
			}
			m = 0;
			rep(i, n)m = max(m, c[i]);
			ans = k + max(0, m - k - 2);
			cout << ans << endl;
		}
	}
	return 0;
}