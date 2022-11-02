#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1000100
#define MOD 1000000007 //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	char a[N];
	char b[N];
	ll cd[N][3][3];
	rep(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	rep(i, 3)rep(j, 3)cd[0][i][j] = 0;
	rep(i, 3)rep(j, 3)cd[1][i][j] = 0;
	ll n, m;
	ll x = 0;
	ll y = 0;
	ll ans = 0;
	cin >> a;
	cin >> b;
	n = strlen(a);
	m = strlen(b);
	rep(i, m - 1) {
		rep(ii, 3)rep(jj, 3)cd[i + 2][ii][jj] = cd[i + 1][ii][jj];
		if ((b[i] == 'R') && (b[i + 1] == 'G'))cd[i + 2][0][1]++;
		if ((b[i] == 'R') && (b[i + 1] == 'B'))cd[i + 2][0][2]++;
		if ((b[i] == 'G') && (b[i + 1] == 'R'))cd[i + 2][1][0]++;
		if ((b[i] == 'G') && (b[i + 1] == 'B'))cd[i + 2][1][2]++;
		if ((b[i] == 'B') && (b[i + 1] == 'R'))cd[i + 2][2][0]++;
		if ((b[i] == 'B') && (b[i + 1] == 'G'))cd[i + 2][2][1]++;
	}
	rep(i, n) {
		if (i > 0) {
			if (b[x] == a[i - 1])x++;
			if ((y < (m - 1)) && (b[y] == a[i - 1]))y++;
			if (x >= m)break;
		}
		while (y < (m - 1)) {
			if (b[y] != a[i])y++;
			else break;
		}
		ans += (y - x + 1);
		if (i > 0) {
			if ((a[i - 1] == 'G') && (a[i] == 'R'))ans -= (cd[y + 1][0][1] - cd[x][0][1]);
			if ((a[i - 1] == 'B') && (a[i] == 'R'))ans -= (cd[y + 1][0][2] - cd[x][0][2]);
			if ((a[i - 1] == 'R') && (a[i] == 'G'))ans -= (cd[y + 1][1][0] - cd[x][1][0]);
			if ((a[i - 1] == 'B') && (a[i] == 'G'))ans -= (cd[y + 1][1][2] - cd[x][1][2]);
			if ((a[i - 1] == 'R') && (a[i] == 'B'))ans -= (cd[y + 1][2][0] - cd[x][2][0]);
			if ((a[i - 1] == 'G') && (a[i] == 'B'))ans -= (cd[y + 1][2][1] - cd[x][2][1]);
		}
	}
	cout << ans << endl;

	return 0;
}