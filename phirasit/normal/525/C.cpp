#include <iostream>
#include <algorithm>
#include <vector>

#define N 1000010

using namespace std;

long long sum[N];
int n;

int main() {
	cin >> n;
	if(n < 4) {
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0;i < n;i++) {
		int val;
		cin >> val;
		sum[val]++;
	}
	int tmp = 0;
	long long ans = 0, ls = -1;
	for(long long i = N-1;i > 0;i--) {
		long long val = sum[i] + tmp;
		if(ls != -1 && val >= 2) {
			ans += ls * i;
			val -= 2;
			ls = -1;
		}
		ans += (val / 4) * i * i;
		val %= 4;
		if(val >= 2) {
			ls = i;
			val -= 2;
		}
		if(val == sum[i] + tmp) {
			tmp = sum[i] % 2;
		}else {
			tmp = val % 2;
		}
	}
	cout << ans << endl;
	return 0;
}