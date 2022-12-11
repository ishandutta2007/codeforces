#include <iostream>

using namespace std;

long long w, m, k;

long long calc(long long x) {
	int l = 0;
	long long t = x;
	while(t) {
		l++;
		t /= 10;
	}
	long long v = 1, ans = 0;
	for(int i = 1;i <= l;i++) {
		if(i == l) {
			ans += (long long) (x - v + 1) * l;
		}else {
			ans += (long long) 9 * v * i;
		}
		v *= 10;
	}
	return ans;
}
int main() {
	
	cin >> w >> m >> k;
	
	w /= k;
	long long a = m-1, b = w + m;
	while(a < b) {
		long long mid = (a+b)/2 + 1;
		long long val = calc(mid) - calc(m-1);
		if(val > w) {
			b = mid - 1;
		}else {
			a = mid;
		}
	}
	cout << a-m+1 << endl;
	return 0;
}