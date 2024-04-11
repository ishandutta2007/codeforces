#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string a, b;
bool trans[20][20];

void solve() {
	memset(trans, 0, sizeof(trans));
	cin >> n >> a >> b;
	for (int i=0; i<n; ++i) {
		if (a[i]>b[i]) {
			cout << -1 << '\n';
			return;
		}
		if (a[i]<b[i])
			trans[a[i]-'a'][b[i]-'a']=1;
	}
	int ans=0;
	for (int i=0; i<20; ++i) {
		for (int j=i+1; j<20; ++j) {
			if (trans[i][j]) {
				++ans;
				for (int k=j+1; k<20; ++k)
					if (trans[i][k])
						trans[j][k]=1;
				break;
			}
		}
	}
	cout << ans << '\n';
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