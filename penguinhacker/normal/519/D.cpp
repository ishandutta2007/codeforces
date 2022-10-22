#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll val[26], sum[100000];
string s;
map<ll, int> occ[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i=0; i<26; ++i)
		cin >> val[i];
	cin >> s;
	sum[0] = val[s[0]-'a'];
	for (int i=1; i<s.size(); ++i)
		sum[i] = sum[i-1]+val[s[i]-'a'];
	
	ll ans = 0;
	occ[s[0]-'a'][sum[0]]++;
	for (int i=1; i<s.size(); ++i) {
		ans += occ[s[i]-'a'][sum[i-1]];
		occ[s[i]-'a'][sum[i]]++;
	}
	cout << ans;
	return 0;
}