#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> p;
	for (int i=0; i<n; ++i) {
		string t;
		cin >> t;
		if (t=="pwd") {
			for (string s : p)
				cout << "/" << s;
			cout << "/\n";
		} else {
			string s;
			cin >> s, s+='/';
			if (s[0]=='/') {
				p.clear();
				s=s.substr(1);
			}
			string cur;
			for (char c : s) {
				if (c=='/') {
					if (cur=="..")
						p.pop_back();
					else
						p.push_back(cur);
					cur.clear();
				}
				else
					cur+=c;
			}
		}
	}
	return 0;
}