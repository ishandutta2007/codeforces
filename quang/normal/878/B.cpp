#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k, m;
int a[N];
int b[N], cnt[N];
int nxt[N], pre[N];

void naive() {
	int top = 0;
	b[0] = -1;
	for (int it = 1; it <= m; it++) {
		for (int i = 1; i <= n; i++) {
			b[++top] = a[i];
			if (b[top] == b[top - 1]) {
				cnt[top] = cnt[top - 1] + 1;
			} else {
				cnt[top] = 1;
			}
			if (cnt[top] == k) {
				top -= k;
			}
			// for (int j = 1; j <= top; j++) {
			// 	cout << b[j] << " ";
			// }
			// cout << endl;
		}
	}
	cout << top << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int top = 0;
	b[0] = a[0] = -1;
	for (int i = 1; i <= n; i++) {
		b[++top] = a[i];
		if (b[top] == b[top - 1]) {
			cnt[top] = cnt[top - 1] + 1;
		} else {
			cnt[top] = 1;
		}
		if (cnt[top] == k) {
			top -= k;
		}
	}
	n = top;
	for (int i = 1; i <= n; i++) {
		a[i] = b[i];
	}
	long long res = 1ll * n * m;
	if (m <= 2) {
		naive();
		return 0;
	}
	a[n + 1] = -1;
	for (int i = 1; i <= n; i++) {
		pre[i] = (a[i] == a[i - 1]) ? pre[i - 1] + 1 : 1;
	}
	for (int i = n; i > 0; i--) {
		nxt[i] = (a[i] == a[i + 1]) ? nxt[i + 1] + 1 : 1;
	}
	int l = 1, r = n;
	while (l <= r) {

		int sum = pre[r] + nxt[l];
		//all
		// cout << l << " " << r << " " << res << " " << sum << endl;
		if (r - l + 1 == pre[r]) {
			long long num = 1ll * (r - l + 1) * m;
			res -= (num - (num % k));
			num %= k;
			// cout << res << " " << num << endl;
			if (num > 0) {
				break;
			}
			int top = 0;
			for (int i = 1; i < l; i++) {
				b[++top] = a[i];
				if (b[top] == b[top - 1]) {
					cnt[top] = cnt[top - 1] + 1;
				} else {
					cnt[top] = 1;
				}
				if (cnt[top] == k) {
					top -= k;
					res -= k;
				}
			}
			for (int i = r + 1; i <= n; i++) {
				b[++top] = a[i];
				if (b[top] == b[top - 1]) {
					cnt[top] = cnt[top - 1] + 1;
				} else {
					cnt[top] = 1;
				}
				if (cnt[top] == k) {
					top -= k;
					res -= k;
				}
			}
			break;
		}
		if (b[l] != b[r]) {
			break;
		}

		if (sum == k) {
			res -= 1ll * (m - 1) * k;
			l += nxt[l];
			r -= pre[r];
			continue;
		}
		if (sum < k) {
			break;
		}
		if (sum > k) {
			res -= 1ll * (m - 1) * k;
			break;
		}
	}
	cout << res << endl;
	return 0;
}