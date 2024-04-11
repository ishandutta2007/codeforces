#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> get_pr(int n) {
	vector<int> ans;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ans.push_back(i);
		}
	}
	if (n > 1) {
		ans.push_back(n);
	}
	return ans;
}

int get(vector<int> &tmp) {
	int n = tmp.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += tmp[i];
	}

	int m = (sum+1)/2;

	// move to box with m-th candy
	int mth = 0, pos = 0;
	for (int i = 0; i < n; i++) {
		if (mth + tmp[i] >= m) {
			pos = i; break;
		}
		mth += tmp[i];
	}

	// move everything to pos
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += tmp[i]*abs(i - pos);
	}
	return ans;
}

int solve(int n, vector<int> a, int sum, int k) {
	int sz = k;
	// size of each group

	int ans = 0;
	vector<int> tmp;
	int sumt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] + sumt >= sz) {
			tmp.push_back(sz - sumt);
			a[i] -= (sz - sumt);
			a[i] %= sz;

			ans += get(tmp); tmp.clear(); sumt = 0;
		}

		tmp.push_back(a[i]);
		sumt += a[i];
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, sum = 0; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum == 1) {
		cout << -1; exit(0);
	}

	int ans = 1e18;
	vector<int> dv = get_pr(sum);
	for (int i: dv) {
		ans = min(ans, solve(n, a, sum, i));
	}
	cout << ans << '\n';
 
	return 0;
}