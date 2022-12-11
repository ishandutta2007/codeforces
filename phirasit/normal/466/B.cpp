#include <iostream>
#include <algorithm>

#define LL long long

using namespace std;

LL n, a, b;
LL x, y, ans = -1;

int main() {
	cin >> n >> a >> b;
	n *= 6;
	bool flag = false;
	if(a > b) {
		swap(a, b);
		flag = true;
	}
	for(LL i = 1;i <= n;i++) {
		LL x1 = i;
		LL y1 = n / i + !!(n%i);
		if(x1 > y1) {
			break;
		}
		if(x1 < a) {
			x1 = a;
		}
		if(y1 < b) {
			y1 = b;
		}
		if(ans == -1 || x1*y1 < ans) {
			ans = x1 * y1;
			x = x1;
			y = y1;
		}
	}
	if(flag) {
		swap(x, y);
	}
	cout << ans << endl << x << " " << y << endl;
	return 0;
}