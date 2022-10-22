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
		int n, d12, d23, d13;
		cin >> n >> d12 >> d23 >> d13;
		if ((d12+d23+d13)%2||d23>d12+d13||d12>d23+d13||d13>d12+d23) {
			cout << "NO\n";
			continue;
		}
		int share=(d12+d13-d23)/2;
		if (share==d12&&share==d13||1+d12+d13-share>n) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int lca=d12+d13==d23?1:d12+d23==d13?2:d13+d23==d12?3:share+3;
		int n2=4;
		for (int i=1, cur=1; i<=share; ++i) {
			if (i==share)
				cout << cur << " " << lca << "\n";
			else {
				cout << cur << " " << n2 << "\n";
				cur=n2++;
			}
		}
		n2=max(n2, lca+1);
		for (int i=1, cur=lca; i<=d12-share; ++i) {
			if (i==d12-share)
				cout << cur << " 2\n";
			else {
				cout << cur << " " << n2 << "\n";
				cur=n2++;
			}
		}
		for (int i=1, cur=lca; i<=d13-share; ++i) {
			if (i==d13-share)
				cout << cur << " 3\n";
			else {
				cout << cur << " " << n2 << "\n";
				cur=n2++;
			}
		}
		for (int cur=1; n2<=n;) {
			cout << cur << " " << n2 << "\n";
			cur=n2++;
		}
	}
	return 0;
}