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
	int n;
	int a[N];
	int x, y;
	int ans = 1000;
	cin >> n;
	rep(i, n)cin >> a[i + 1];
	if (n > 200) {
		cout << 1 << endl;
		return 0;
	}
	a[0] = 0;
	rep(i, n)a[i + 1] ^= a[i];
	rep(i, n) {
		rep2(j, i + 1, n) {
			rep2(jj, j + 1, n) {
				x = a[i] ^ a[j];
				y = a[j] ^ a[jj];
				if (x > y) {
					ans = min(ans, jj - i - 2);
				}
			}
		}
	}
	if (ans == 1000)ans = -1;
	cout << ans << endl;
	return 0;
}