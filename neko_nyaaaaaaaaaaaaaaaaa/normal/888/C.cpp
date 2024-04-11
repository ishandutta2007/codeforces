#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;
	vector<vector<long>> a(26, vector<long>(1, -1));
	for (long i = 0; i < s.size(); i++) {
	      a[s[i] - 'a'].push_back(i);
	}
	for (long i = 0; i < 26; i++) {
		a[i].push_back(s.size());
	}
	long ans = s.size()/2 + 1;
	for (long i = 0; i < 26; i++) {
	      if (a[i].size() > 1) {
	            long ma = 0;
	            for (long j = 1; j < a[i].size(); j++) {
	                  if (a[i][j] - a[i][j-1] > ma) {ma = a[i][j] - a[i][j-1];}
	            }
	            if (ma < ans) {ans = ma;}
	      }
	}
	cout << ans << endl;
	
	return 0;
}