#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s;
bool used[26];

void solve() {
	memset(used, 0, sizeof(used));
	cin >> s;
	deque<char> d;
	bool pos = 1;
	
	used[s[0]-'a'] = 1;
	d.push_back(s[0]);
	int curPos = 0;
	for (int i=1; i<s.size(); ++i) {
		if (curPos == d.size()-1) {
			if (used[s[i]-'a']) {
				if (d[d.size()-2] != s[i]) {
					cout << "NO\n";
					return;
				}
				curPos = d.size()-2;
			}
			else {
				d.push_back(s[i]);
				curPos = d.size()-1;
			}
		}
		else if (curPos == 0) {
			if (used[s[i]-'a']) {
				if (d[1] != s[i]) {
					cout << "NO\n";
					return;
				}
				curPos = 1;
			}
			else {
				d.push_front(s[i]);
			}
		}
		else {
			if (d[curPos-1] == s[i])
				curPos--;
			else if (d[curPos+1] == s[i])
				curPos++;
			else {
				cout << "NO\n";
				return;
			}
		}
		used[s[i]-'a'] = 1;
	}

	for (int i=0; i<26; ++i) {
		if (!used[i])
			d.push_back('a'+i);
	}

	if (pos) {
		cout << "YES\n";
		for (char c : d)
			cout << c;
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}