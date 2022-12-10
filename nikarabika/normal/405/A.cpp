// sobskdrbhvk
// remember... ):(
#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 * 1000 + 10;
int a[maxn],
	tmp[maxn],
	n;

void sort(int l, int r) {
	if (r - l == 1)
		return;
	int mid = (l + r) / 2;
	sort(l, mid);
	sort(mid, r);

	int i = l,
		j = mid;
	int ptr = l;
	while (i < mid or j < r) {
		if (i == mid) {
			tmp[ptr] = a[j];
			j++;
		}
		else if (j == r) {
			tmp[ptr] = a[i];
			i++;
		}
		else if (a[i] < a[j]) {
			tmp[ptr] = a[i];
			i++;
		}
		else {
			tmp[ptr] = a[j];
			j++;
		}
		ptr++;
	}
	for (int i = l; i < r; i++)
		a[i] = tmp[i];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(0, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[i == n - 1];
	return 0;
}