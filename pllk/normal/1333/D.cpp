#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = "#"+s;
	int c = 0;
	while (true) {
		vector<int> u;
		for (int i = 1; i <= n-1; i++) {
			if (s[i] == 'R' && s[i+1] == 'L') {
				u.push_back(i);
				c++;
				s[i] = 'L'; s[i+1] = 'R'; i++;
			}
		}
		if (u.size() == 0) break;
		v.push_back(u);
	}
	if (v.size() > k || c < k) {
		cout << "-1\n";
		return 0;
	}
	int e = k-v.size();
	for (int i = 0; i < v.size(); i++) {
		while (e && v[i].size() > 1) {
			cout << "1 " << v[i].back() << "\n";
			v[i].pop_back();
			e--;
		}
		if (v[i].size()) {
			cout << v[i].size() << " ";
			for (auto x : v[i]) cout << x << " ";
			cout << "\n";
		}
	}
}