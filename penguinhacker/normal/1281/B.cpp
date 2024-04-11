#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s, c;
int smallestChar[5000];
bool pos=0;

void solve() {
	cin >> s >> c;

	if (s<c) {
		cout << s << '\n';
		return;
	}

	smallestChar[s.size()-1]=s.size()-1;
	for (int i=s.size()-2; i>=0; --i) {
		if (s[i] < s[smallestChar[i+1]])
			smallestChar[i] = i;
		else
			smallestChar[i] = smallestChar[i+1];
	}
	
	for (int i=0; i<s.size()-1; ++i) {
		if (s[i] > s[smallestChar[i+1]]) {
			swap(s[i], s[smallestChar[i+1]]);
			if (s<c) {
				cout << s << '\n';
				return;
			}
			else
				break;
		}
	}
	cout << "---\n";
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