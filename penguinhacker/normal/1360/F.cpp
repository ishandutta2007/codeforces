#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
string s[10];

int diff(string s1, string s2) {
	int r=0;
	for (int i=0; i<m; ++i)
		if (s1[i]!=s2[i])
			++r;
	return r;
}

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	for (int i=0; i<m; ++i) {
		string curr=s[0];
		for (int j=0; j<26; ++j) {
			curr[i]='a'+j;
			bool b=1;
			for (int k=0; k<n; ++k)
				if (diff(curr, s[k])>1) {
					b=0;
					break;
			}
			if (b) {
				cout << curr << '\n';
				return;
			}
		}
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/