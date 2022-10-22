#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
map<string, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		if (!mp[s])
			cout << "OK\n";
		else
			cout << s << mp[s] << '\n';
		mp[s]++;
	}
	return 0;
}