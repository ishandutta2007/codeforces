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
		cin >> n;
		vector<bool> p(26);
		for (int i=0; i<2*n+1; ++i) {
			string s;
			cin >> s;
			for (char c : s)
				p[c-'a']=!p[c-'a'];
		}
		for (int i=0; i<26; ++i)
			if (p[i])
				cout << (char)('a'+i) << "\n";
	}
	return 0;
}