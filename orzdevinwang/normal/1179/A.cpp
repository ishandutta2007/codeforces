#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, q, a[N], ns[N][2], l, r;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> q;
	L(i, 1, n) {
		cin >> a[i];
	}
	int l = 1, r = n;
	L(i, 1, n) {
		ns[i][0] = a[l], ns[i][1] = a[l + 1];
		int mx = max (a[l], a[l + 1]), mn = min(a[l], a[l + 1]);
		l += 1, a[l] = mx, r += 1, a[r] = mn;
	}
//	L(i, l, r) 
//		cout << a[i] << ' ';
//	cout << '\n';
	while (q--) {
		ll m;
		cin >> m;
		if(m <= n) {
			cout << ns[m][0] << ' ' << ns[m][1] << '\n';
		}
		else {
			m -= n, m = (m - 1) % (n - 1) + 1;
			cout << a[l] << ' ' << a[m + l] << '\n';
		}
	}
	return 0;
}