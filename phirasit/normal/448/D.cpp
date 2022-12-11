#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, k;

long long cnt(long long k) {
	long long ans = 0;
	for(long long i = 1;i <= n;i++) {
		ans += min(m, k/i);
	}
	return ans;
}
int main() {
	cin >> n >> m >> k;
	long long a = 1, b = n * m;
	while(a < b) {
		long long mid = (a + b) / 2;
		if(cnt(mid) >= k) {
			b = mid;
		}else {
			a = mid + 1;
		}
	}
	cout << a << endl;
	return 0;
}