#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

const int M = 50005, N = 26;

int n;
int T = 0;
vector<int> a;

bool dp[N][M * N] = {};
int to[N][M * N] = {};

void upd(int v) {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M * (i + 1); j++)
			if (dp[i][j] && !dp[i + 1][j + v]) {
				dp[i + 1][j + v] = true;
				to[i + 1][j + v] = v;
			}
	}
}

int ans = md;
int y;
int opti;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	n *= 2;
	a.resize(n);
	for (auto &i : a) cin >> i, T += i;
	sort(a.begin(), a.end());

	dp[0][0] = 1;
	for (int i = n - 2; i >= 1; i--) {
		upd(a[i + 1]);
		for (int j = 0; j < M * N; j++)
			if (dp[n / 2 - 1][j]) {
				int S2 = a[i] + j;
				int S1 = T - S2;
				int m1 = a[0];
				int m2 = a[i];
				int res = max(S1 + m2, S2 + m1);
				if (res < ans) {
					ans = res;
					y = j;
					opti = i;
				}
			}
	}
	vector<int> arr1, arr2;
	multiset<int> SS;
	for (const auto &i : a) SS.insert(i);
	arr1.push_back(a[opti]);
	SS.erase(SS.find(a[opti]));
	int pos = y, x = n / 2 - 1;
	while (x > 0) {
		int v = to[x][pos];
		pos -= v;
		x--;
		arr1.push_back(v);
		SS.erase(SS.find(v));
	}
	sort(arr1.rbegin(), arr1.rend());
	for (const auto &i : SS) cout << i << " "; cout << '\n';
	for (const auto &i : arr1) cout << i << " "; cout << '\n';
}