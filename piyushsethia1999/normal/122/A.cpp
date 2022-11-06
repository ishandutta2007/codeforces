#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int a[1001];

int c(int i) {
	while (i) {
		if (i % 10 == 4 || i % 10 == 7) {}
		else return 0;
		i /= 10;
	}
	return 1;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	for (int i = 1; i <= 1000; ++i) {
		if (a[i]) {

		} else {
			if (c(i)) {
				for (int j = i; j <= 1000; j += i) {
					a[j] = 1;
				}
			} else {
			}
		}
	}
	int n; cin >> n;
	cout << (a[n] ? "YES" : "NO");
}