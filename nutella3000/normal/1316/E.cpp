#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1, max_p = 7;


struct person {
	int a;
	vector<int> s;

	person() {}

	person(int a1, vector<int> s1) {
		a = a1;
		for(int i : s1) s.emplace_back(i);
	}

	bool operator<(person b) {
		return a > b.a;
	}
};



int n, p, k;
int dp[max_n][(1 << max_p)];
person a[max_n];

void scan() {
	cin >> n >> p >> k;
	int temp[n];
	for(int i = 0;i < n;i++) cin >> temp[i];

	for(int i = 0;i < n;i++) {
		vector<int> temp1(p);
		for(int j = 0;j < p;j++) cin >> temp1[j];
		a[i] = person(temp[i], temp1);
	}

	sort(a, a + n);
}

void solve() {
	scan();

	for(int i = 0;i < n;i++) {
		for(int mask = 0;mask < (1 << p);mask++) {
			int ans = -inf;
			
			int cnt = 0;
			for(int j = 0;j < p;j++) if ((mask & (1 << j))) cnt++;

			for(int j = 0;j < p;j++) {
				if ((mask & (1 << j)) == 0) continue;
				int temp = 0;
				if (i != 0) temp = dp[i - 1][mask - (1 << j)];
				if (i == 0 && mask - (1 << j) != 0) temp = -inf;
				ans = max(ans, temp + a[i].s[j]);
			}

			if (i == 0) {
				if (mask == 0) ans = max(ans, a[i].a);
			}else{
				if (i - cnt + 1 > k) ans = max(ans, dp[i - 1][mask]);
				else ans = max(ans, dp[i - 1][mask] + a[i].a);
			}

			dp[i][mask] = ans;
		//	cout << dp[i][mask] << " ";
		}
		//cout << '\n';
	}

	cout << dp[n - 1][(1 << p) - 1];
}

signed main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	solve();
}