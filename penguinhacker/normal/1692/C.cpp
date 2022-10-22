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
		string g[8];
		for (int i=0; i<8; ++i)
			cin >> g[i];
		for (int i=1; i<7; ++i)
			for (int j=1; j<7; ++j)
				if (g[i][j]=='#'&&g[i+1][j+1]=='#'&&g[i-1][j+1]=='#')
					cout << i+1 << " " << j+1 << "\n";
	}
	return 0;
}