/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>

#define pb push_back
typedef long long ll;

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < n * 2; i++) {
		int a;
		cin >> a;
		g[a].pb(i);
	}
	int now = g[1][0], now1 = g[1][1];
	ll cnt = g[1][0] + g[1][1];
	for (int i = 2; i <= n; i++) {
		ll c1 = abs(now - g[i][0]) + abs(now1 - g[i][1]);
		ll c2 = abs(now - g[i][1]) + abs(now1 - g[i][0]);
		if (c2 < c1) {
			cnt += c2;
			now = g[i][1];
			now1 = g[i][0];
		}
		else {
			cnt += c1;
			now = g[i][0];
			now1 = g[i][1];
		}
	}
	cout << cnt;
}