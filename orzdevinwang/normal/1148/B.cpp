#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 7;
int n, m, k, ta, tb, a[N], b[N], ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> ta >> tb >> k;
	if(k >= n || k >= m) return cout << -1 << endl, 0;
	L(i, 1, n) cin >> a[i];
	L(i, 1, m) cin >> b[i];
	L(i, 0, k) {
		//  i 
		if(a[i + 1] + ta > b[m - (k - i)]) return cout << -1 << endl, 0;
		int wz = lower_bound(b + 1, b + n + 1, a[i + 1] + ta) - b;
		ans = max(ans, b[wz + (k - i)] + tb);
	}
	cout << ans << endl;
	return 0;
}