#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, q;
vector<int> inversion(25);
vector<int> not_inversion(25);

void merge_count(vector<int> &a, int left, int right, int lv) {
	int mid = (left + right)/2;
	for (int i = left; i <= mid; i++) {
		int p = lower_bound(a.begin() + mid + 1, a.begin() + right + 1, a[i]) - (a.begin() + 1);
		if (a[p] < a[i]) {
			inversion[lv] += p - mid;
		}
		
		p = upper_bound(a.begin() + mid + 1, a.begin() + right + 1, a[i]) - a.begin();
		if (a[p] > a[i]) {
			not_inversion[lv] += right - p + 1;
		}
	}
	sort(a.begin() + left, a.begin() + right + 1);
}

void inversion_count(vector<int> &a, int left, int right, int lv) {
	if (left == right) return;

	int mid = (right + left)/2;

	inversion_count(a, left, mid, lv+1);
	inversion_count(a, mid+1, right, lv+1);
	merge_count(a, left, right, lv);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n; m = (1LL << n);
	vector<int> a(m+1);
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	inversion_count(a, 1, m, 0);
	
	/*for (int i = 0; i <= n; i++) {
		cout << inversion[i] << " " << not_inversion[i] << "\n";
	}
	cout << endl; */
	
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		x = n-x;
		for (int i = x; i <= n; i++) {
			swap(inversion[i], not_inversion[i]);
		}
		
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			ans += inversion[i];
		}
		cout << ans << '\n';
	}
	
	return 0;
}