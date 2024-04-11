#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	vi a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	int sum1 = 0, sum2 = 0;
	int cur = 1;

	string ans;

	if (a[0] <= b[0]) {
		sum1 += a[0];
		ans.push_back('A');
	}
	else {
		sum2 += b[0];
		ans.push_back('G');
	}
	for (int i = 1; i < n; i++) {
		if (abs(sum1 + a[i] - sum2) <= 500) {
			sum1 += a[i];
			ans.push_back('A');
		}
		else {
			sum2 += b[i];
			ans.push_back('G');
		}
	}

	cout << ans;
	return 0;
}