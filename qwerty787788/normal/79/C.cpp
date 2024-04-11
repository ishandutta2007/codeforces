#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s, s2[11];
int n;

int min(int x, int y) {
	if (x < y) return x; else return y;
};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s2[i];
	}
	//
	int max_len = 0;
	int max_start = 0;
	int last_len = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		int ok = 100;
		for (int j = 0; j < n; j++)
			if (s.substr(i, s2[j].size()) == s2[j]) ok = min(ok, s2[j].size());
		if (ok == 100) {
			last_len ++; 
			if (last_len > max_len) {
				max_len = last_len;
				max_start = i;
			}
		} else {
			if (last_len > max_len) {
				max_len = last_len;
				max_start = i + 1;
			}
			last_len = min(ok - 1, last_len + 1);
			if (last_len > max_len) {
				max_len = last_len;
				max_start = i;
			}
		}
	}
	cout << max_len << " " << max_start << endl;
	//
	return 0;
};