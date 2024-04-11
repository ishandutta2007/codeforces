#include <bits/stdc++.h>
using namespace std;
int hy, ay, dy, hm, am, dm, ch, ca, cd, ans = 1e9;
int main() {
	cin >> hy >> ay >> dy >> hm >> am >> dm;
	cin >> ch >> ca >> cd;
	for (int i = 0; i <= 200; ++i)
		for (int j = 0; j <= 100; ++j) {
			ay += i; dy += j;
			if (ay > dm) {
				int r = (hm - 1) / (ay - dm) + 1;
				ans = min(ans, max(r * max(am - dy, 0) + 1 - hy, 0) * ch + i * ca + j * cd);
			}
			ay -= i; dy -= j;
		}
	cout << ans;
}