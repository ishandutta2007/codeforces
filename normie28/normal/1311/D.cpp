#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 1e9;
		int A = -1, B = -1, C = -1;
		for (int cA = 1; cA <= 2 * a; ++cA) {
			for (int cB = cA; cB <= 2 * b; cB += cA) {
				for (int i = 0; i < 2; ++i) {
					int cC = cB * (c / cB) + i * cB;
					int res = abs(cA - a) + abs(cB - b) + abs(cC - c);
					if (ans > res) {
						ans = res;
						A = cA;
						B = cB;
						C = cC;
					}
				}
			}
		}
		cout << ans << endl << A << " " << B << " " << C << endl;
	}
}