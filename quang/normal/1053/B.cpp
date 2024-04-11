#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int a[N];
int sum[N];
int even[N], odd[N];

int findEven(int u) {
	if (u == 0) {
		return 0;
	}
	return even[u - 1];
}

int findOdd(int u) {
	if (u == 0) {
		return 0;
	}
	return odd[u - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	even[0] = 1;
	odd[0] = 0;
	for (int i = 1; i <= n; i++) {
		long long u;
		cin >> u;
		int cnt = 0;
		while (u > 0ll) {
			cnt += (u % 2);
			u /= 2ll;
		}
		a[i] = cnt;
		sum[i] = sum[i - 1] + a[i];
		even[i] = even[i - 1] + (sum[i] % 2 == 0);
		odd[i] = odd[i - 1] + (sum[i] % 2 == 1);
	}
	long long res = 0;
	vector<pair<int, int> > mx;
	for (int i = 1; i <= n; i++) {
		while (!mx.empty() && a[i] >= mx.back().first) {
			mx.pop_back();
		}
		mx.push_back(make_pair(a[i], i));
		int id = mx.size() - 1;
		for (int j = i - 1; j >= max(0, i - 200); j--) {
			int tot = sum[i] - sum[j];
			if (mx[id].first * 2 <= tot && tot % 2 == 0) {
				res++;
			}
			while (id > 0 && mx[id - 1].second == j) {
				id--;
			}
		}
		int lastId = max(0, i - 200);
		if (sum[i] % 2 == 0) {
			res += findEven(lastId);
		} else {
			res += findOdd(lastId);
		}
	}
	cout << res << endl;
	return 0;
}