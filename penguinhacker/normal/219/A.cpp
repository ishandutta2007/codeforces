#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int k, let[26];
string s, temp, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(let, 0, sizeof(let));
	cin >> k >> s;
	for (char c : s) let[c-'a']++;
	for (int i=0; i<26; ++i) {
		if (let[i]%k!=0) {
			cout << -1;
			return 0;
		}
		for (int j=0; j<let[i]/k; ++j)
			temp += ('a'+i);
	}
	while(k--)
		ans+=temp;
	cout << ans;
	return 0;
}