#include <iostream>

using namespace std;

long long n, m;
long long d[110000];
long long a[110000];

bool check (long long days) {
	static bool passed[110000];
	for (long long i = 1; i <= m; i++)
		passed[i] = false;
	long long daysnec = 0;
	for (long long i = days; i >= 1; i--) {
		if (d[i] != 0 && passed[d[i]] == false) {
			passed[d[i]] = true;
			daysnec += a[d[i]];
		} else
			if (daysnec > 0) daysnec--;
	}
	for (long long i = 1; i <= m; i++)
		if (passed[i] == false) return false;
	return daysnec == 0;
}

int main () {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> d[i];
	for (long long i = 1; i <= m; i++)
		cin >> a[i];
	long long l = 0, r = n, ans = -1;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check (mid)) {
			ans = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	cout << ans << endl;
}