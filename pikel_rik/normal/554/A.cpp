#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a;
	cin >> a;

	set<string> s;
	for (int j = 0; j < 26; j++) {
		s.insert(char('a' + j) + a);
		s.insert(a + char('a' + j));
	}

	for (int i = 1; i < a.length(); i++) {
		for (int j = 0; j < 26; j++) {
			string temp = a.substr(0, i);
			temp += 'a' + j;
			temp += a.substr(i, a.length());
			s.insert(temp);
		}
	}
	cout << s.size() << '\n';
	return 0;
}