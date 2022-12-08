#include <bits/stdc++.h>
#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

const int dd = (int)3e5 + 1;

int A[dd], B[dd];
long long sumB[dd];

long long get(int l, int r) {
	return sumB[r] - sumB[l];
}

int n, m;

int check(int j, long long sum) {
	int l = j, r = m + 1;
	while (r - l > 1) {
		int mid = l + r >> 1;
		if (get(j, mid) <= sum) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (get(j, l) == sum) {
		return l;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	long long sumA = 0;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		sumA += A[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> B[i];
		sumB[i + 1] = sumB[i] + B[i];
	}
	if (sumA != sumB[m]) {
		cout << "-1\n";
		return 0;
	}
	int ans = 0, j = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += A[i];
		int tmp;
		err("%d %lld\n", j, sum);
		if (tmp = check(j, sum)) {
			++ans;
			j = tmp;
			sum = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}