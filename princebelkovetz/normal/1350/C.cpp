#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <string>
#include <map>
using namespace std;
long long xf(long long n, long long m) {
	if (m == 0) { return n; }
	if (n < m) { return xf(m, n); }
	return xf(m, n % m);

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n, x = 0, cou;
	cin >> n;
	vector <long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector <long long> b;
	for (long long i = 1; i <= 200000; ++i) {
		cou = 0;
		bool c = false;
		for (long long j = 0; j < n; ++j) {
			if (a[j] % i == 0) cou++;
			else if (c) break;
			else c = true;
		}
		if (cou >= n - 1) b.push_back(i);
	}
	long long ans = b[0];
	for (long long i = 1; i < b.size(); ++i) {
		ans = ans * b[i] / xf(ans, b[i]);
		//cout << ans << " ";
	}
	
	cout << ans;
	return 0;
}