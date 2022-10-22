#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	vector<bitset<5>> v(n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<5; ++j) {
			int x;
			cin >> x;
			v[i][j]=x;
		}
	if (n%2) {
		cout << "NO\n";
		return;
	}
	bool ok=0;
	for (int i=0; i<5; ++i)
		for (int j=i+1; j<5; ++j) {
			int a=0, b=0, c=0;
			for (int k=0; k<n; ++k) {
				a+=v[k][i];
				b+=v[k][j];
				c+=v[k][i]&&v[k][j];
			}
			a=min(a-c, n/2), b=min(b-c, n/2);
			ok|=a+b+c>=n;
		}
	cout << (ok?"YES":"NO") << "\n";
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