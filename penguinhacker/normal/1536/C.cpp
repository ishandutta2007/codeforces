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
		int cnt[2]={};
		map<ar<int, 2>, int> mp;
		for (char c : s) {
			++cnt[c=='D'?0:1];
			int g=__gcd(cnt[0], cnt[1]);
			ar<int, 2> cur={cnt[0]/g, cnt[1]/g};
			cout << ++mp[cur] << " ";
		}
		cout << "\n";
	}
	return 0;
}