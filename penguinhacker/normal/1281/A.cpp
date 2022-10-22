#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s;

void solve() {
	cin >> s;
	if (s.substr(s.size()-2,2) == "po")
		cout << "FILIPINO\n";
	else if (s.size()>=5 && s.substr(s.size()-5,5) == "mnida")
		cout << "KOREAN\n";
	else
		cout << "JAPANESE\n";
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