#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

map<char, pair<int, int>> mp={{'N', {1,0}}, {'E', {0,1}}, {'S', {-1,0}}, {'W', {0,-1}}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		pair<int, int> curr={0,0};
		set<pair<pair<int, int>, pair<int, int>>> st;
		for (char c : s) {
			pair<int, int> x=mp[c];
			pair<int, int> nxt={curr.first+x.first, curr.second+x.second};
			if (nxt<curr) {
				swap(curr, nxt);
				st.insert({curr, nxt});
			}
			else {
				st.insert({curr, nxt});
				swap(curr, nxt);
			}
		}
		cout << s.size()+4*st.size() << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/