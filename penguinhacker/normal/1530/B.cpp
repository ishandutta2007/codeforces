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
		int n, m;
		cin >> n >> m;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (i&&i+1<n&&j&&j+1<m)
					cout << 0;
				else if ((i==0||i==n-1)&&(j==0||j==m-1))
					cout << 1;
				else if (i==0||i==n-1)
					cout << (j%2==0&&j+1<m-1);
				else if (j==0||j==m-1)
					cout << (i%2==0&&i+1<n-1);
			}
			cout << "\n";
		}
	}
	return 0;
}