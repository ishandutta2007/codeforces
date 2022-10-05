#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
#define endl '\n'
using namespace std;
/*
 Time Complexity: O(max(N * M, K))
 Preprocessing: O(N * M)
 For Each Query: O(1)

 Memory: O(max(N, M))
 */
int main() {
	ios::sync_with_stdio(false);
	int n, m, k, x, l, r;
	cin >> n >> m;
	vector<int> a(m), cnt(m, 0), mx(n, 0);
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x >= a[j]) cnt[j]++;
			else cnt[j] = 0;
			a[j] = x;
			mx[i] = max(mx[i], cnt[j]);
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> l >> r;
		if (mx[r - 1] >= r - l)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}