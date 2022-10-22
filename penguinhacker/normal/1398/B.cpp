#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

string s;

void test_case() {
	cin >> s;
	pair<int, int> cur={-1, -1};
	vector<int> v;
	for (char c: s) {
		int x=c-'0';
		if (x==cur.first)
			++cur.second;
		else {
			if (cur.first==1)
				v.push_back(cur.second);
			cur={x, 1};
		}
	}
	if (cur.first==1)
		v.push_back(cur.second);
	sort(v.rbegin(), v.rend());
	int ans=0;
	for (int i=0; i<v.size(); i+=2)
		ans+=v[i];
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/