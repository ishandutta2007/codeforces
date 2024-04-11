#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int, int> mp;
	mp['(']=')';
	mp['<']='>';
	mp['{']='}';
	mp['[']=']';
	string s;
	cin >> s;
	stack<char> st;
	int ans=0;
	for (char c : s) {
		if (c=='('||c=='<'||c=='['||c=='{')
			st.push(c);
		else {
			if (st.empty()) {
				cout << "Impossible";
				return 0;
			}
			ans+=mp[st.top()]!=c;
			st.pop();
		}
	}
	if (st.size())
		cout << "Impossible";
	else
		cout << ans;
	return 0;
}