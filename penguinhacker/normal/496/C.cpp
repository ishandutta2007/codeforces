#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, m, cnt=0, val[100];
string s[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		val[i]=0;
	}
	
	for (int i=0; i<m; ++i) {
		bool b=1;
		for (int j=1; j<n; ++j) {
			if (val[j]<=val[j-1]&&s[j][i]<s[j-1][i]) {
				b=0;
				break;
			}
		}
		if (!b) {
			cnt++;
			continue;
		}
		for (int j=1; j<n; ++j) {
			if (val[j]<=val[j-1]&&s[j][i]==s[j-1][i]) {
				b=0;
				val[j]=val[j-1];
			}
			if (val[j]<=val[j-1]&&s[j][i]>s[j-1][i])
				val[j]=j;
		}
		if (b)
			break;
	}
	cout << cnt;
	return 0;
}