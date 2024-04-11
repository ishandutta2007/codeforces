#include <bits/stdc++.h>
using namespace std;

#define ll long long

int k;
string s;
vector<int> occ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> s;
	occ.push_back(-1);
	for (int i=0; i<s.size(); ++i)
		if (s[i]=='1')
			occ.push_back(i);
	occ.push_back(s.size());

	if (occ.size()-2<k)
		cout << 0;
	else if (k==0) {
		int curr = 0;
		ll ans = 0;
		for (int i=0; i<s.size(); ++i) {
			if (s[i]=='0')
				curr++;
			else
				curr=0;
			if (i==s.size()-1||s[i+1]=='1')
				ans += 1ll*curr*(curr+1)/2;
		}
		cout << ans;
	}
	else {
		ll ans = 0;
		for (int i=1; i+k<occ.size(); ++i)
			ans += 1ll*(occ[i]-occ[i-1])*(occ[i+k]-occ[i+k-1]);
		cout << ans;
	}
	return 0;
}