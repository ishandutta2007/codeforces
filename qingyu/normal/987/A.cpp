#include <bits/stdc++.h>
using namespace std;

map<string, string> a = {
	{"Power", "purple"},
	{"Time", "green"},
	{"Space", "blue"},
	{"Soul", "orange"},
	{"Reality", "red"},
	{"Mind", "yellow"},
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	set<string> b;
	for (auto p : a)
		b.insert(p.first);

	while (n--) {
		string s;
		cin >> s;
		for (auto p : a)
			if (p.second == s)
				b.erase(p.first);
	}	
	cout << b.size() << '\n';
	for (auto s : b)
		cout << s << '\n';
}