#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
	      s[i] -= '0';
	      ans = max(ans, int(s[i]));
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
	      string sss = "";
	      for (int j = 0; j < s.size(); j++) {
	            if (s[j]) {
	                  sss += '1';
	                  s[j]--;
	            } else {sss += '0';}
	      }
	      cout << stoi(sss) << " ";
	}
	
	return 0;
}