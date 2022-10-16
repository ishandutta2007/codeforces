#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string s; cin >> s;
	int n = s.size();
	vector<vector<vector<int>>> cnt(26, vector<vector<int>>(26, vector<int>(6666, 0)));
	vector<int> cc(26);
	
	s += s;
	for (int i = 0; i < n; i++) {
		cc[s[i] - 'a']++;
		for (int j = i+1; j < i+n; j++) {
			cnt[s[i] - 'a'][s[j] - 'a'][j-i]++;
		}
	}
	
	double ans = 0;
	
	for (int i = 0; i < 26; i++) {
		double addition = 0;
		for (int k = 1; k < n; k++) {
			double tmp = 0;
			for (int j = 0; j < 26; j++) {
				if (cnt[i][j][k] == 1) {tmp += 1.0/cc[i];}
			}
			addition = max(addition, tmp);
		}
		ans += addition * cc[i] / n;
	}
	
	cout << fixed << setprecision(12) << ans;
	
	return 0;
}