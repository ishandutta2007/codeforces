
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		long long MN, MX, idMN=1, idMX=1, n;
		cin >>n>> MN;
		MX = MN;
		long long tmp1 = MN;
		bool ans = false;
		for (long long j = 2; j <= n; ++j) {
			long long tmp;
			cin >> tmp;
			if (ans)continue;
			if (tmp > MX) {
				MX = tmp;
				idMX = j;
			}
			if (tmp < MN) {
				MN = tmp;
				idMN = j;
			}
			if (abs(MX - MN) >= abs(idMN - idMX)+1)ans = true;
			if (abs(tmp - tmp1) >= 2) {
				ans = true;
				idMN = j - 1;
				idMX = j;
			}
			tmp1 = tmp;
		}
		if (ans) {
			cout << "YES\n";
			cout << min(idMN, idMX) << " " << max(idMN, idMX) << "\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}