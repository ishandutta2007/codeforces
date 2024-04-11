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
		vector<int> oc;
		for (int i=0; i<n; ++i)
			if (s[i]=='*')
				oc.push_back(i);
		if (oc.empty()) {
			cout << "0\n";
			continue;
		}
		int med=oc[oc.size()/2];
		int start=med-oc.size()/2;
		ll ans=0;
		for (int i=0; i<oc.size(); ++i)
			ans+=abs(start+i-oc[i]);
		cout << ans << "\n";
	}
	return 0;
}