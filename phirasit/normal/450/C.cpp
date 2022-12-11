#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, k;

int main() {
	cin >> n >> m >> k;
	if(k > n+m-2) {
		cout << -1 << endl;
		return 0;
	}
	long long ans1, ans2;
	if(k >= m) {
		ans1 = n/(k-m+2);
	}else {
		ans1 = (m/(k+1)) * n;
	}
	if(k >= n) {
		ans2 = m/(k-n+2);
	}else {
		ans2 = (n/(k+1)) * m;
	}
	
	cout << max(ans1, ans2) << endl;
	return 0;
}