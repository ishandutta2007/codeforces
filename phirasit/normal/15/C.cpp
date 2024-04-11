#include <iostream>

using namespace std;

int n;

long long calc(long long x, long long m) {
	if(m == 0) {
		return 0ll;
	}
	if(m == 1) {
		return x;
	}
	if(m == 2) {
		return x ^ (x + 1ll);
	}
	long long ls = x & (-x);
	if(m < ls) {
		long long ans = (m % 2 ? x : 0);
		m--;
		for(long long i = 0;i < 60;i++) {
			long long cnt = (m >> (i + 1ll)) * (1ll << i);
			if((m >> i) & 1ll) {
				cnt += (m & ((1ll << i) - 1ll)) + 1ll;
			}
			if(cnt % 2) {
				ans ^= (1ll << i);
			}
		}
		return ans;
	}else if(m == ls) {
		return m ^ ls;
	}else {
		return calc(x + ls, m - ls) ^ calc(x, ls);
	}
}
long long calc2(long long x, long long m) {
	if(m == 1) {
		return x;
	}
	return x ^ calc2(x+1, m-1);
}
int main() {
	cin >> n;
	long long ans = 0;
	for(int i = 0;i < n;i++) {
		long long x, m;
		cin >> x >> m;
//		cout << "#" << calc(x, m) << " " << calc2(x, m) << endl;
		ans ^= calc(x, m);
	}
	cout << (ans ? "tolik" : "bolik") << endl;
	return 0;
}