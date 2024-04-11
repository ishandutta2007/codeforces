#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[555];
int b[555];

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		vector<pair<int,int>> va, vb;
		for (int i = 0; i < n/2; i++) {
			int x, y;
			x = a[i]; y = a[n-1-i];
			if (x > y) swap(x,y);
			va.push_back({x,y});
			x = b[i]; y = b[n-1-i];
			if (x > y) swap(x,y);
			vb.push_back({x,y});
		}
		bool ok = n%2 == 0 || a[n/2] == b[n/2];
		sort(va.begin(),va.end());
		sort(vb.begin(),vb.end());
		if (ok && va == vb) cout << "YES\n";
		else cout << "NO\n";
	}
}