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
		int n=s.size();
		ll ans=0;
		for (int i=0, j1=0, j2=0; i<n; ++i) {
			j1=max(j1, i);
			j2=max(j2, i);
			while(j1<n&&(s[j1]=='?'||s[j1]-'0'==j1%2))
				++j1;
			while(j2<n&&(s[j2]=='?'||s[j2]-'0'==((j2+1)%2)))
				++j2;
			ans+=max(j1, j2)-i;
			//cout << j1 << " " << j2 << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}