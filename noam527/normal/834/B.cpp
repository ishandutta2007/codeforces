#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, k;
string s;

int main() {
	cin >> n >> k >> s;
	vector<int> a(n + 2, 0);
	vector<pair<int, int>> v(26, make_pair(-1, -1));
	for (int i = 0; i < s.size(); i++) {
		if (v[s[i] - 'A'].first == -1) v[s[i] - 'A'].first = v[s[i] - 'A'].second = i;
		else v[s[i] - 'A'].second = i;
	}
	for (auto i : v)
		if (i.first != -1) a[i.first]++, a[i.second + 1]--;
	for (int i = 1; i < a.size(); i++) a[i] += a[i - 1];
	for (int i = 0; i < a.size(); i++) if (a[i] > k) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
}