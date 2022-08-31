#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		string mex;
		for (int i = 0; i < 26 && mex.empty(); i++) {
			string temp(1, 'a' + i);
			if (s.find(temp) == s.npos) {
				mex = temp;
			}
		}

		for (int i = 0; i < 26 && mex.empty(); i++) {
			for (int j = 0; j < 26 && mex.empty(); j++) {
				string temp(2, 0);
				temp[0] = 'a' + i, temp[1] = 'a' + j;
				if (s.find(temp) == s.npos) {
					mex = temp;
				}
			}
		}

		for (int i = 0; i < 26 && mex.empty(); i++) {
			for (int j = 0; j < 26 && mex.empty(); j++) {
				for (int k = 0; k < 26 && mex.empty(); k++) {
					string temp(3, 0);
					temp[0] = 'a' + i, temp[1] = 'a' + j, temp[2] = 'a' + k;
					if (s.find(temp) == s.npos) {
						mex = temp;
					}
				}
			}
		}
		cout << mex << '\n';
	}
	return 0;
}