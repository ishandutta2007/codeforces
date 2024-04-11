#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> dir = {{'L' , {-1, 0}}, {'R' , {1, 0}}, {'D' , {0, -1}}, {'U' , {0, 1}}}; 

vector<pair<int, int>> getRoad(string &s, pair<int, int> obs) {
	pair<int, int> cur = {0, 0};
	vector<pair<int, int>> res;
	for (char ch : s) {
		cur.first += dir[ch].first;
		cur.second += dir[ch].second;
		if (cur == obs) {
			cur.first -= dir[ch].first;
			cur.second -= dir[ch].second;
		}
		res.push_back(cur);
	}
	return res;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;

	cin >> ntest;

	while (ntest--) {
		string s;
		cin >> s;
		pair<int, int> obs = {1e9, 1e9};
		auto road = getRoad(s, obs);
		bool found = 0;
		for (auto e : road) {
			if (getRoad(s, e).back() == make_pair(0, 0)) {
				found = 1;
				cout << e.first << ' ' << e.second << '\n';
				break;
			}
		}
		if (found == 0) {
			cout << 0 << ' ' << 0 << '\n';
		}
	}

	return 0;
}