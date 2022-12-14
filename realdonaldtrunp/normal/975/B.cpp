#include "bits/stdc++.h"
using namespace std;

deque<long long int> d;
deque<long long int> v;

int main() {
	for (int i = 0; i < 14; i++) {
		int a;
		scanf("%d", &a);
		d.push_back(a);
	}
	int cnt = 15;
	long long int outt = LLONG_MIN;
	while (cnt--) {
		long long int cnt = d.front();
		d.push_back(d.front());
		d.pop_front();
		v = d;
		v.back() = 0LL;
		for (int i = 0; i < v.size(); i++) {
			long long int add = (cnt / 14LL);
			if ((cnt % 14) - 1LL >= i) {
				add++;
			}
			v[i] += add;
		}
		long long int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] % 2 == 0LL) {
				ans += v[i];
			}
		}
		outt = max(outt, ans);
	}
	printf("%lld\n", outt);
	return 0;
}