#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
string s[30000];

bool check(int col) {
	for (int i = 1; i < n; i++) if (s[i][col] != s[0][col]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < s[0].size(); i++)
		if (!check(i)) {
			cout << i << endl;
			return 0;
		}
	cout << s[0].size() << endl;
	return 0;
}