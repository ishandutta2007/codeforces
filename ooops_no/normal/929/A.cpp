#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	int last = 1e8;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] - last > m) {
			cout << -1;
			return 0;
		}
		last = v[i];
	}
	int i = 1, now = v[0], cnt = 1;
	while (i < n) {
		if (now + m >= v[i]) {
			i++;
		}
		else {
			now = v[i - 1];
			cnt++;
		}
	}
	cout << cnt;
}