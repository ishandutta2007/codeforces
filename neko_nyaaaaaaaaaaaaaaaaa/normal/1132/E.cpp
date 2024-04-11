#include <bits/stdc++.h>
using namespace std;

#define int long long
int w, reserve, sum;
int c[9];
vector<int> a;

const int mmm = 50000;

void process() {
	vector<int> aux(9);
	for (int i = 1; i <= 8; i++) {
		aux[i] = min(mmm/i, c[i]);
		c[i] -= aux[i];
	}

	int rev = min(mmm, w);
	w -= rev;
	for (int i = 8; i >= 1; i--) {
		if (w <= 0) break;

		int k = min(w/i, c[i]);
		c[i] -= k;
		reserve += i*k;
		w -= i*k;
	}
	w += rev;

	for (int i = 1; i <= 8; i++) {
		c[i] += aux[i];
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
		
	cin >> w;
	for (int i = 1; i <= 8; i++) {
		cin >> c[i];
		sum += c[i]*i;
	}

	if (sum <= w) {cout << sum; return 0;}

	process();

	for (int i = 1; i <= 8; i++) {
		for (int j = 1, k = 1; c[i] > 0 && k <= 250; j = min(c[i], j+1), k++) {
			a.push_back(i*j);
			c[i] -= j;
		}
	}

	int n = a.size();
	vector<int> dp(3*mmm);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for(int j = mmm; j >= 0; j--) {
			dp[j + a[i]] |= dp[j];
		}
	}

	int ans = reserve;
	for (int i = 0; i <= w; i++) {
		ans = max(ans, i*dp[i] + reserve);
	}

	cout << ans;

	return 0;
}