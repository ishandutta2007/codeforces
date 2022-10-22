#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	ll ans=0;
	int d=0;
	priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
	for (int i=0; i<s.size(); ++i) {
		if (s[i]=='?') {
			int a, b;
			cin >> a >> b;
			ans+=b;
			pq.push({a-b, i});
			s[i]=')';
		}
		d+=s[i]=='('?1:-1;
		if (d<0) {
			if (pq.empty()) {
				cout << -1;
				return 0;
			}
			ans+=pq.top()[0];
			s[pq.top()[1]]='(';
			pq.pop();
			d+=2;
		}
	}
	if (d!=0) {
		cout << -1;
		return 0;
	}
	cout << ans << "\n" << s;
	return 0;
}