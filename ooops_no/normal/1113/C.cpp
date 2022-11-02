#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

#define pb push_back
#define ll long long

const int n = (1 << 20) + 10;
int cnt[2][n];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	cnt[1][0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	ll ans = 0, m = 0;
	for (int i = 0; i < n; i++) {
		m ^= v[i];
		ans += cnt[i % 2][m];
		cnt[i % 2][m]++;
	}
	cout << ans;
}