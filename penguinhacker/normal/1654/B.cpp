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
		string s;
		cin >> s;
		int cnt[26]={};
		for (char c : s)
			++cnt[c-'a'];
		int ind=0;
		while(cnt[s[ind]-'a']>=2) {
			--cnt[s[ind]-'a'];
			++ind;
		}
		cout << s.substr(ind) << "\n";
	}
	return 0;
}