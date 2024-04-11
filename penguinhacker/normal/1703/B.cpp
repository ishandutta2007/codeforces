#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		string t=s;
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end())-t.begin());
		cout << s.size()+t.size() << "\n";
	}
	return 0;
}