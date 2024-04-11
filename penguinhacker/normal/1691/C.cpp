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
		int n, k;
		string s;
		cin >> n >> k >> s;
		int base=0;
		vector<int> pos;
		for (int i=1; i+1<n; ++i)
			if (s[i]=='1')
				pos.push_back(i);
		base+=10*(s[0]=='1')+(s.back()=='1');
		for (int i=1; i+1<n; ++i)
			base+=11*(s[i]=='1');
		int cnt=count(s.begin(), s.end(), '0');
		if (k==0||cnt==0||cnt==n) {
			cout << base << "\n";
			continue;
		}
		if (pos.empty()&&cnt==n-1&&s[0]=='1') {
			cout << (k>=n-1?1:10) << "\n";
			continue;
		}
		int best=0;
		if (pos.size()) {
			if (pos[0]<=k&&s[0]=='0')
				best=max(best, 1);
			if (n-1-pos.back()<=k&&s.back()=='0')
				best=max(best, 10);
		}
		if (pos.size()>=2&&pos[0]+(n-1-pos.back())<=k&&s[0]=='0'&&s.back()=='0')
			best=11;
		cout << base-best << "\n";
	}
	return 0;
}