#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int>v(n), cnt(n), one(n), two(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[i] = a;
		v[i] -= 1;
		one[i] = max(0, i - k);
		two[i] = min(n - 1, i + k);
		cnt[i] = two[i] - one[i] + 1;
		if (a != 0) {
			cnt[i] += cnt[v[i]] - max(0, min(two[i], two[v[i]]) - max(one[i], one[v[i]]) + 1);
		}
		cout << cnt[i] << " ";
	}
}