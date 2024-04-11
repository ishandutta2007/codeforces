#include <bits/stdc++.h>

using namespace std;

const int N = 200100;
const long long INF = 3000000000000000000ll;

int n;
long long t;
long long a[N];
int x[N];
int minVal[N], maxVal[N];
long long b[N];
int f[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (x[i] < i) {
			cout << "No\n";
			return 0;
		}
		minVal[i] = i;
		maxVal[i] = n + 1;
	}
	a[n + 1] = INF + 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		f[x[i]]++;
		cnt++;
		cnt -= f[i];
		if (cnt > 0) {
			minVal[i] = i + 1;
		} else {
			minVal[i] = i;
		}
		maxVal[x[i]] = x[i] + 1;
	}
	b[0] = 0ll;
	for (int i = 1; i <= n; i++) {
		long long val = max(b[i - 1] + 1, a[minVal[i]] + t);
		if (i < n) {
			if (val >= a[maxVal[i]] + t) {
				cout << "No\n";
				return 0;
			} else {
				b[i] = val;
			}
		} else {
			if (val > INF) {
				cout << "No\n";
				return 0;
			} else {
				b[i] = val;
			}
		}
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; i++) {
		cout << b[i] << ' ';
	}
	cout << "\n";
	return 0;
}