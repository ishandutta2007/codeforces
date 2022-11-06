#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += a[i];
	}
	if ((n == 1 && cnt == 1) || (cnt == n - 1 && n != 1)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}