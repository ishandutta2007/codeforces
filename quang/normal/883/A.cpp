#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100010;
const long long INF = (1e18 + 10);

int n, m, a, num;
long long d;
long long t[N];

int getHas(long long u) {
	int low = 0, high = n + 1;
	while (high - low > 1) {
		int mid = (low + high) >> 1;
		if (1ll * a * mid <= u) {
			low = mid;
		} else {
			high = mid;
		}
	}
	return low;
}

main() {
	ios_base::sync_with_stdio(0);
	// cin.tie(0);
	cin >> n >> m >> a >> d;
	for (int i = 1; i <= m; i++) {
		cin >> t[i];
	}
	// while (1) {
	// 	n = rand() % 10 + 1;
	// 	m = rand() % 10 + 1;
	// 	a = rand() % 10 + 1;
	// 	d = rand() % 10 + 1;
	// 	vector<int> b;
	// 	t[0] = 1;
	// 	for (int i = 1; i <= m; i++) {
	// 		t[i] = t[i - 1] + rand() % 10; 
	// 		b.push_back(t[i]);
	// 	}
	// 	for (int i = 1; i <= n; i++) {
	// 		b.push_back(i * a);
	// 	}
	// 	sort(b.begin(), b.end());
	// 	int ans = 0;
	// 	for (int i = 0; i < b.size(); i++) {
	// 		int j = i;
	// 		while (j + 1 < b.size() && b[j + 1] - b[i] <= d) {
	// 			j++;
	// 		}
	// 		ans++;
	// 		i = j;
	// 	}

		long long curTime = 0;
		int has = 0;
		int res = 0;
		int num = 1 + d / a;
		num = min(num, n);
		// cout << num << endl;
		for (int i = 1; i <= m; i++) {
			if (curTime >= t[i]) {
				continue;
			}
			if (has < n) {
				int low = 0, high = n + 1;
				while (high - low > 1) {
					int mid = (low + high) >> 1;
					if (1ll * (mid - 1) * num + 1 + has > n) {
						high = mid;
						continue;
					}
					if (1ll * a * ((mid - 1) * num + 1 + has) + d < t[i]) {
						low = mid;
					} else {
						high = mid;
					}
				}
				res += low;
				curTime = 1ll * a * ((low - 1) * num + 1 + has) + d;
				has += low * num;
				has = min(has, n);
				// cout << i << " " << low << endl;
			}
			long long now = t[i];
			if (has < n) {
				now = min(now, 1ll * a * (has + 1));
			}
			res++;
			curTime = now + d;
			has = getHas(curTime);
		}	
		int rest = n - has;
		if (rest > 0) {
			res += (rest - 1) / num + 1;
		}
		cout << res << endl;
	// 	if (res != ans) {
	// 		cout << res << " " << ans << endl;
	// 		cout << n << " " << m << " " << a << " " << d << endl;
	// 		for (int i = 1; i <= m; i++) {
	// 			cout << t[i] << " ";
	// 		}
	// 		cout << endl;
	// 		break;
	// 	}
	// }
	return 0;
}