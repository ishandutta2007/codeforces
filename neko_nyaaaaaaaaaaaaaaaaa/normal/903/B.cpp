#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int h1, a1, c1, h2, a2;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	vector<string> ans;
	while (h2 > 0) {
		if (h2 - a1 <= 0) {ans.push_back("STRIKE"); break;}
		if (h1 - a2 <= 0) {ans.push_back("HEAL"); h1 += c1; h1 -= a2; continue;}
		ans.push_back("STRIKE");
		h2 -= a1;
		h1 -= a2;
	}
	cout << ans.size() << endl;
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}