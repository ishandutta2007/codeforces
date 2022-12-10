#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
int a[maxn],
	b[maxn],
	k[maxn],
	p[maxn],
	n, u, r;
long long ans = -1e18;

void check_score(int arr[]) {
	long long cur = 0;
	for (int i = 0; i < n; i++)
		cur += 1LL * arr[i] * k[i];
	if (cur > ans)
		ans = cur;
}

void op1(int src[], int dst[]) {
	for (int i = 0; i < n; i++)
		dst[i] = src[i] ^ b[i];
}

void op2(int src[], int dst[]) {
	for (int i = 0; i < n; i++)
		dst[i] = src[p[i]] + r;
}

void bt(int arr[], int rem, bool last_op=1) {
	if (rem % 2 == 0)
		check_score(arr);
	if (rem == 0)
		return;

	int na[n];
	op2(arr, na);
	bt(na, rem - 1, 1);

	if (last_op != 0) {
		op1(arr, na);
		bt(na, rem - 1, 0);
	}
}

int main() {
	cin >> n >> u >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < n; i++)
		cin >> p[i], p[i]--;
	bt(a, u);
	cout << ans << endl;
	return 0;
}