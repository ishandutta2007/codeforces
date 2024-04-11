#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
bool taken[100000];

void solve() {
	cin >> n;

	vector<int> princess[n];
	for (int i=0; i<n; ++i)
		taken[i]=0;

	for (int i=0; i<n; ++i) {
		int k;
		cin >> k;
		for (int j=0; j<k; ++j) {
			int g;
			cin >> g, g--;
			princess[i].push_back(g);
		}
	}

	int g=0, b=0; //g is princess b is prince

	for (int i=0; i<n; ++i) {
		bool pos=0; //can the princess marry?
		for (int j : princess[i]) {
			if (!taken[j]) {
				taken[j]=1;
				pos = 1;
				break;
			}
		}
		if (!pos)
			g = i+1;
	}

	for (int i=0; i<n; ++i) {
		if (!taken[i]) {
			b = i+1;
			break;
		}
	}

	if(g) {
		cout << "IMPROVE\n";
		cout << g << ' ' << b << '\n';
	}
	else
		cout << "OPTIMAL\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}