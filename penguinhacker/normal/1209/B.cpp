#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100;
int n, a[mxN], b[mxN];
string s;
bitset<mxN> on;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		cin >> a[i] >> b[i];
		on[i]=s[i]=='1';
	}
	int ans=on.count();
	for (int i=1; i<=1000; ++i) {
		for (int j=0; j<n; ++j)
			if (i>=b[j]&&(i-b[j])%a[j]==0)
				on[j]=!on[j];
		ans=max(ans, (int)on.count());
	}
	cout << ans;
	return 0;
}