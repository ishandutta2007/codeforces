
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
		long long s = 0, Xc = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			long long tmp;
			cin >> tmp;
			s += tmp;
			Xc = Xc ^ tmp;
		}
		if (Xc*2 == s) {
			cout << 0 << "\n\n";
		}
		else {
			if (Xc == 0) {
				cout << 1 << "\n" << s << "\n";
			}
			else {
				cout << 2 << "\n";
				s += Xc;
				cout << Xc << " " << s << "\n";
			}
		}
	}
	return 0;
}