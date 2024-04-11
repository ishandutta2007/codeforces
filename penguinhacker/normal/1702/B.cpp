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
		set<char> st;
		int ans=1;
		for (char c : s) {
			st.insert(c);
			if (st.size()>3) {
				++ans;
				st={c};
			}
		}
		cout << ans << "\n";
	}
	return 0;
}