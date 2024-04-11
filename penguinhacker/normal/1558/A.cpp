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
		int a, b;
		cin >> a >> b;
		vector<int> ans;
		for (int i=0; i<=a+b; ++i) {
			int n=(a+b)/2, m=(a+b+1)/2;
			bool ok=0;
			for (int rep=0; rep<2; ++rep) {
				swap(n, m);
				int x=n+i-a; // breaks on A's game
				if (x<0||x%2)
					continue;
				x/=2;
				int y=i-x;
				//cout << i << " " << x << " " << y << endl;
				if (x<=n&&0<=y&&y<=m)
					ok=1;
				//swap(n, m);
			}
			if (ok)
				ans.push_back(i);
		}
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}