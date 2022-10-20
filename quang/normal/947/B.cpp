#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int v[N], t[N];
long long sumT[N];
long long add[N];
int cnt[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		sumT[i] = sumT[i - 1] + t[i];
	}
	for (int i = 1; i <= n; i++) {
		int low = i - 1, high = n + 1;
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			long long val = sumT[mid] - sumT[i - 1];
			if (val >= v[i]) {
				high = mid;
			} else {
				low = mid;
			}
		}
		cnt[i] += cnt[i - 1];
		cnt[i]++;
		cnt[low + 1]--;
		add[low + 1] += v[i] - sumT[low] + sumT[i - 1];
		// cout << i << " " << low << " " << cnt[i] << " " << add[i] << endl;
		cout << 1ll * t[i] * cnt[i] + add[i] << " ";
	}
	cout << endl;
	// for (int i =1; i <= n; i++) {
	// 	cout << cnt[i] << " " << add[i] << endl;
	// }
	return 0;
}