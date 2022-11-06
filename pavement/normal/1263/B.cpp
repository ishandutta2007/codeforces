#include <bits/stdc++.h>
using namespace std;

map<string, vector<int> > m;
string out[15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	string x;
	cin >> t;
	while (t--) {
		m.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			m[x].push_back(i);
		}
		int ch = 0;
		for (auto it : m) {
			for (int i = 2; i <= it.second.size(); i++) {
				bool f = false;
				for (int k = 0; k < 4; k++) {
					for (int l = 0; l <= 9; l++) {
						if (k == 0) x = to_string(l) + it.first.substr(1);
						else if (k == 1) x = it.first.substr(0, 1) + to_string(l) + it.first.substr(2);
						else if (k == 2) x = it.first.substr(0, 2) + to_string(l) + it.first.substr(3);
						else x = it.first.substr(0, 3) + to_string(l);
						if (!m[x].size()) {
							f = true;
							out[it.second[i - 1]] = x;
							m[x].push_back(it.second[i - 1]);
							ch++;
							break;
						}
					}
					if (f) break;
				}
			}
			out[it.second[0]] = it.first;
		}
		cout << ch << '\n';
		for (int i = 0; i < n; i++) cout << out[i] << '\n';
	}
}