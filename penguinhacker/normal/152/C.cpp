#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, m;
string s[100];
ll ans=1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	for (int i=0; i<m; ++i) {
		set<char> let;
		for (int j=0; j<n; ++j)
			let.insert(s[j][i]);
		ans=ans*let.size()%MOD;
	}
	cout << ans;
	return 0;
}